#include "ScriptFunctions.hpp"
#include "API/PublicFnAPI.hpp"
#include <cstdarg>
#include <iostream>

#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/world.hpp"

#include "../mwworld/esmstore.hpp"

//#include <apps/openmw-mp/Player.hpp>
////#include <apps/openmw-mp/Networking.hpp>
//#include <components/openmw-mp/NetworkMessages.hpp>

template<typename... Types>
constexpr char TypeString<Types...>::value[];
constexpr ScriptFunctionData ScriptFunctions::functions[];
constexpr ScriptCallbackData ScriptFunctions::callbacks[];

using namespace std;

void ScriptFunctions::MakePublic(ScriptFunc _public, const char *name, char ret_type, const char *def) noexcept
{
    Public::MakePublic(_public, name, ret_type, def);
}

boost::any ScriptFunctions::CallPublic(const char *name, va_list args) noexcept
{
    vector<boost::any> params;

    try
    {
        string def = Public::GetDefinition(name);
        Utils::getArguments(params, args, def);

        return Public::Call(name, params);
    }
    catch (...) {}

    return 0;
}

std::vector<std::string> splitString(const std::string &str, char delim = ';')
{
    std::istringstream ss(str);
    std::vector<std::string> result;
    std::string token;
    while (std::getline(ss, token, delim))
        result.push_back(token);
    return result;
}

void ScriptFunctions::MessageBox(const char *label, const char *buttons) noexcept
{
    std::vector<std::string> buttonLabels = splitString(buttons);

    MWBase::Environment::get().getWindowManager()->interactiveMessageBox(label, buttonLabels);
}

void ScriptFunctions::SetGMST(const char *name, double value) noexcept
{
    MWWorld::Store<ESM::GameSetting> *gmst = const_cast<MWWorld::Store<ESM::GameSetting>*>(&MWBase::Environment::get().getWorld()->getStore().get<ESM::GameSetting>());
    ESM::GameSetting* gmstValue = const_cast<ESM::GameSetting*>(gmst->search(name));
    if (gmstValue == nullptr)
    {
        ESM::GameSetting newGmst;
        newGmst.mId = name;
        if (name[0] == 'f')
            newGmst.mValue = (float)value;
        if (name[0] == 'i')
            newGmst.mValue = (int)value;

        gmst->insertStatic(newGmst);
        return;
    }

    if (name[0] == 'f')
        gmstValue->mValue = (float)value;
    if (name[0] == 'i')
        gmstValue->mValue = (int)value;
}

double ScriptFunctions::GetGMST(const char *name) noexcept
{
    const MWWorld::Store<ESM::GameSetting> &gmst = MWBase::Environment::get().getWorld()->getStore().get<ESM::GameSetting>();

    if (name[0] == 'f')
        return gmst.find(name)->mValue.getFloat();
    if (name[0] == 'i')
        return gmst.find(name)->mValue.getInteger();

    // FIXME: TESMP seems to do not support variance return types
    return 0;
    //return gmst.find(name)->mValue.getString();
}
