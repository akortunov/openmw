//
// Created by koncord on 08.05.16.
//

#include <iostream>
#include "LangLua.hpp"
#include "../Script.hpp"
#include "../Types.hpp"

using namespace std;

std::set<std::string> LangLua::packagePath;
std::set<std::string> LangLua::packageCPath;

void setLuaPath(lua_State* L, const char* path, bool cpath = false)
{
    string field = cpath ? "cpath" : "path";
    lua_getglobal(L, "package");

    lua_getfield(L, -1, field.c_str());
    std::string cur_path = lua_tostring(L, -1);
    cur_path.append(";");
    cur_path.append(path);
    lua_pop(L, 1);
    lua_pushstring(L, cur_path.c_str());
    lua_setfield(L, -2, field.c_str());
    lua_pop(L, 1);
}

lib_t LangLua::GetInterface()
{
    return reinterpret_cast<lib_t>(lua);
}

LangLua::LangLua(lua_State *lua)
{
    this->lua = lua;
}

LangLua::LangLua()
{
    lua = luaL_newstate();
    luaL_openlibs(lua); // load all lua std libs

    std::string p, cp;
    for (auto& path : packagePath)
        p += path + ';';

    for (auto& path : packageCPath)
        cp += path + ';';

    setLuaPath(lua, p.c_str());
    setLuaPath(lua, cp.c_str(), true);

}

LangLua::~LangLua()
{

}

template<unsigned int I, unsigned int F>
struct Lua_dispatch_ {
    template<typename R, typename... Args>
    inline static R Lua_dispatch(lua_State*&& lua, Args&&... args) noexcept {
        constexpr ScriptFunctionData const& F_ = ScriptFunctions::functions[F];
        auto arg = luabridge::Stack<typename CharType<F_.func.types[I - 1]>::type>::get(lua, I);
        return Lua_dispatch_<I - 1, F>::template Lua_dispatch<R>(
                forward<lua_State*>(lua),
                arg,
                forward<Args>(args)...);
    }
};

template<unsigned int F>
struct Lua_dispatch_<0, F> {
    template<typename R, typename... Args>
    inline static R Lua_dispatch(lua_State*&&, Args&&... args) noexcept {
        constexpr ScriptFunctionData const& F_ = ScriptFunctions::functions[F];
        return reinterpret_cast<FunctionEllipsis<R>>(F_.func.addr)(forward<Args>(args)...);
    }
};

template<unsigned int I>
static typename enable_if<ScriptFunctions::functions[I].func.ret == 'v', int>::type wrapper(lua_State* lua) noexcept {
    Lua_dispatch_<ScriptFunctions::functions[I].func.numargs, I>::template Lua_dispatch<void>(forward<lua_State*>(lua));
    return 0;
}

template<unsigned int I>
static typename enable_if<ScriptFunctions::functions[I].func.ret != 'v', int>::type wrapper(lua_State* lua) noexcept {
    auto ret = Lua_dispatch_<ScriptFunctions::functions[I].func.numargs, I>::template Lua_dispatch<
            typename CharType<ScriptFunctions::functions[I].func.ret>::type>(forward<lua_State*>(lua));
    luabridge::Stack <typename CharType<ScriptFunctions::functions[I].func.ret>::type>::push (lua, ret);
    return 1;
}

template<unsigned int I>
struct F_
{
    static constexpr LuaFuctionData F{ScriptFunctions::functions[I].name, wrapper<I>};
};


template<> struct F_<0> { static constexpr LuaFuctionData F{"CreateTimer", LangLua::CreateTimer}; };
template<> struct F_<1> { static constexpr LuaFuctionData F{"CreateTimerEx", LangLua::CreateTimerEx}; };
template<> struct F_<2> { static constexpr LuaFuctionData F{"MakePublic", LangLua::MakePublic}; };
template<> struct F_<3> { static constexpr LuaFuctionData F{"CallPublic", LangLua::CallPublic}; };

#ifdef __arm__
template<std::size_t... Is>
struct indices {};
template<std::size_t N, std::size_t... Is>
struct build_indices : build_indices<N-1, N-1, Is...> {};
template<std::size_t... Is>
struct build_indices<0, Is...> : indices<Is...> {};
template<std::size_t N>
using IndicesFor = build_indices<N>;

template<size_t... Indices>
LuaFuctionData *functions(indices<Indices...>)
{

    static LuaFuctionData functions_[sizeof...(Indices)]{
            F_<Indices>::F...
    };

    static_assert(
            sizeof(functions_) / sizeof(functions_[0]) ==
            sizeof(ScriptFunctions::functions) / sizeof(ScriptFunctions::functions[0]),
            "Not all functions have been mapped to Lua");

    return functions_;
}
#else
template<unsigned int I>
struct C
{
    constexpr static void Fn(LuaFuctionData *functions_)
    {
        functions_[I] = F_<I>::F;
        C<I - 1>::Fn(functions_);
    }
};

template<>
struct C<0>
{
    constexpr static void Fn(LuaFuctionData *functions_)
    {
        functions_[0] = F_<0>::F;
    }
};

template<size_t LastI>
LuaFuctionData *functions()
{

    static LuaFuctionData functions_[LastI];
    C<LastI - 1>::Fn(functions_);

    static_assert(
        sizeof(functions_) / sizeof(functions_[0]) ==
        sizeof(ScriptFunctions::functions) / sizeof(ScriptFunctions::functions[0]),
        "Not all functions have been mapped to Lua");

    return functions_;
}
#endif

void LangLua::LoadCommand(const char *command)
{
    int err = 0;

    if ((err = luaL_loadbuffer(lua, command, strlen(command), "console")) != 0)
        throw runtime_error("Lua error (" + to_string(err) + "): \"" +
                            string(lua_tostring(lua, -1)) + "\"");

    constexpr auto functions_n = sizeof(ScriptFunctions::functions) / sizeof(ScriptFunctions::functions[0]);

#ifdef __arm__
    LuaFuctionData *functions_ = functions(IndicesFor<functions_n>{});
#else
    LuaFuctionData *functions_ = functions<sizeof(ScriptFunctions::functions) / sizeof(ScriptFunctions::functions[0])>();
#endif
    luabridge::Namespace omw = luabridge::getGlobalNamespace(lua).beginNamespace("omw");

    for (unsigned i = 0; i < functions_n; i++)
        omw.addCFunction(functions_[i].name, functions_[i].func);

    omw.endNamespace();

    if ((err = lua_pcall(lua, 0, LUA_MULTRET, 0)) != 0) // Run once script for load in memory.
        throw runtime_error("Lua error (" + to_string(err) + "): \"" +
                            string(lua_tostring(lua, -1)) + "\"");
}

void LangLua::LoadProgram(const char *filename)
{
    int err = 0;

    if ((err =luaL_loadfile(lua, filename)) != 0)
        throw runtime_error("Lua script " + string(filename) + " error (" + to_string(err) + "): \"" +
                            string(lua_tostring(lua, -1)) + "\"");

    constexpr auto functions_n = sizeof(ScriptFunctions::functions) / sizeof(ScriptFunctions::functions[0]);

#ifdef __arm__
    LuaFuctionData *functions_ = functions(IndicesFor<functions_n>{});
#else
    LuaFuctionData *functions_ = functions<sizeof(ScriptFunctions::functions) / sizeof(ScriptFunctions::functions[0])>();
#endif
    luabridge::Namespace omw = luabridge::getGlobalNamespace(lua).beginNamespace("omw");

    for (unsigned i = 0; i < functions_n; i++)
        omw.addCFunction(functions_[i].name, functions_[i].func);

    omw.endNamespace();

    if ((err = lua_pcall(lua, 0, 0, 0)) != 0) // Run once script for load in memory.
        throw runtime_error("Lua script " + string(filename) + " error (" + to_string(err) + "): \"" +
                            string(lua_tostring(lua, -1)) + "\"");
}

int LangLua::FreeProgram()
{
    lua_close(lua);
    return 0;
}

bool LangLua::IsCallbackPresent(const char *name)
{
    return luabridge::getGlobal(lua, name).isFunction();
}

boost::any LangLua::Call(const char *name, const char *argl, int buf, ...)
{
    va_list vargs;
    va_start(vargs, buf);

    int n_args = (int)(strlen(argl));

    lua_getglobal(lua, name);

    for (int index = 0; index < n_args; index++)
    {
        switch (argl[index])
        {
            case 'i':
                luabridge::Stack<unsigned int>::push(lua,va_arg(vargs, unsigned int));
                break;

            case 'q':
                luabridge::Stack<signed int>::push(lua,va_arg(vargs, signed int));
                break;

            case 'l':
                luabridge::Stack<unsigned long long>::push(lua, va_arg(vargs, unsigned long long));
                break;

            case 'w':
                luabridge::Stack<signed long long>::push(lua, va_arg(vargs, signed long long));
                break;

            case 'f':
                luabridge::Stack<double>::push(lua, va_arg(vargs, double));
                break;

            case 'p':
                luabridge::Stack<void*>::push(lua, va_arg(vargs, void*));
                break;

            case 's':
                luabridge::Stack<const char*>::push(lua, va_arg(vargs, const char*));
                break;

            case 'b':
                luabridge::Stack<bool>::push(lua, (bool) va_arg(vargs, int));
                break;

            default:
                throw runtime_error("C++ call: Unknown argument identifier " + argl[index]);
        }
    }

    va_end(vargs);

    luabridge::LuaException::pcall(lua, n_args, 1);
    return boost::any(luabridge::LuaRef::fromStack(lua, -1));
}

boost::any LangLua::Call(const char *name, const char *argl, const std::vector<boost::any> &args)
{
    int n_args = (int)(strlen(argl));

    lua_getglobal(lua, name);

    for (int index = 0; index < n_args; index++)
    {
        switch (argl[index])
        {
            case 'i':
                luabridge::Stack<unsigned int>::push(lua, boost::any_cast<unsigned int>(args.at(index)));
                break;

            case 'q':
                luabridge::Stack<signed int>::push(lua, boost::any_cast<signed int>(args.at(index)));
                break;

            case 'l':
                luabridge::Stack<unsigned long long>::push(lua, boost::any_cast<unsigned long long>(args.at(index)));
                break;

            case 'w':
                luabridge::Stack<signed long long>::push(lua, boost::any_cast<signed long long>(args.at(index)));
                break;

            case 'f':
                luabridge::Stack<double>::push(lua, boost::any_cast<double>(args.at(index)));
                break;

            case 'p':
                luabridge::Stack<void *>::push(lua, boost::any_cast<void *>(args.at(index)));
                break;

            case 's':
                luabridge::Stack<const char *>::push(lua, boost::any_cast<const char *>(args.at(index)));
                break;

            case 'b':
                luabridge::Stack<bool>::push(lua, boost::any_cast<int>(args.at(index)));
                break;
            default:
                throw runtime_error("Lua call: Unknown argument identifier " + argl[index]);
        }
    }

    luabridge::LuaException::pcall(lua, n_args, 1);
    return boost::any(luabridge::LuaRef::fromStack(lua, -1));
}

void LangLua::AddPackagePath(const std::string& path)
{
    packagePath.emplace(path);
}

void LangLua::AddPackageCPath(const std::string& path)
{
    packageCPath.emplace(path);
}
