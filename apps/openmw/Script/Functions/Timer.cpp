//
// Created by koncord on 15.03.16.
//

#include "../ScriptFunctions.hpp"
#include "../API/TimerAPI.hpp"

using namespace std;
using namespace mwmp;

int ScriptFunctions::CreateTimer(ScriptFunc callback, int msec) noexcept
{
    return mwmp::TimerAPI::CreateTimer(callback, msec, "", vector<boost::any>());
}

int ScriptFunctions::CreateTimerEx(ScriptFunc callback, int msec, const char *types, va_list args) noexcept
{
    try
    {
        vector<boost::any> params;
        Utils::getArguments(params, args, types);

        return mwmp::TimerAPI::CreateTimer(callback, msec, types, params);
    }
    catch (...)
    {
        return -1;
    }

}

void ScriptFunctions::StartTimer(int timerId) noexcept
{
    TimerAPI::StartTimer(timerId);
}

void ScriptFunctions::StopTimer(int timerId) noexcept
{
    TimerAPI::StopTimer(timerId);
}

void ScriptFunctions::RestartTimer(int timerId, int msec) noexcept
{
    TimerAPI::ResetTimer(timerId, msec);
}

void ScriptFunctions::FreeTimer(int timerId) noexcept
{
    TimerAPI::FreeTimer(timerId);
}

bool ScriptFunctions::IsTimerElapsed(int timerId) noexcept
{
    return TimerAPI::IsTimerElapsed(timerId);
}
