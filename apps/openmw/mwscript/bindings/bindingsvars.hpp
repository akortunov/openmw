#ifndef EXTENSIONBINDINGS_HPP
#define EXTENSIONBINDINGS_HPP

#include "lua.hpp"

#include <components/interpreter/types.hpp>
#include <components/interpreter/interpreter.hpp>  // for Interpreter

namespace MWScript { class InterpreterContext; }

namespace MWScriptExtensions
{
    extern Interpreter::Interpreter interpreter;
    extern lua_State *luaState;
    extern bool opcodesInstalled;
    extern bool pythonInitialized;
    extern MWScript::InterpreterContext *context;
    extern Interpreter::Data stackReturn;
}
#endif
