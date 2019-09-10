#ifndef GAME_MWLUA_LUAMANAGER_H
#define GAME_MWLUA_LUAMANAGER_H

#include <unordered_map>
#include <queue>

#include <extern/sol2/sol.hpp>

#include <components/esm/loadscpt.hpp>

#include "../mwworld/ptr.hpp"

#include "baseevent.hpp"

#include "disableableeventmanager.hpp"

namespace MWLua
{
    typedef std::unordered_map<unsigned long, sol::object> UserdataMap;

    class TimerController;
    class LuaManager;

    enum class TimerType
    {
        RealTime,
        SimulationTime,
        GameTime
    };

    class ThreadedStateHandle
    {
    public:
        ThreadedStateHandle(LuaManager *);
        ~ThreadedStateHandle();

        // Trigger a thread-safe event.
        sol::object triggerEvent(Event::BaseEvent*);

        // Guarded access to the userdata cache.
        //sol::object getCachedUserdata(TES3::BaseObject*);
        //sol::object getCachedUserdata(TES3::MobileObject*);
        //void insertUserdataIntoCache(TES3::BaseObject*, sol::object);
        //void insertUserdataIntoCache(TES3::MobileObject*, sol::object);
        //void removeUserdataFromCache(TES3::BaseObject*);
        //void removeUserdataFromCache(TES3::MobileObject*);

        sol::state& state;

    private:
        LuaManager * luaManager;
    };

    class LuaManager
    {
        friend class ThreadedStateHandle;

    public:
        // Returns an instance to the singleton.
        static LuaManager& getInstance()
        {
            return singleton;
        };

        // Returns a thread-locking reference to the sol2 lua state.
        ThreadedStateHandle getThreadSafeStateHandle();

        void hook();

        void cleanup();

        // Set context for lua scripts.
        ESM::Script* getCurrentScript();
        void setCurrentScript(ESM::Script* script);
        MWWorld::Ptr getCurrentReference();
        void setCurrentReference(MWWorld::Ptr ptr);

        // Helper function to execute main.lua scripts recursively in a directory.
        //void executeMainModScripts(const char* path, const char* filename = "main.lua");

        // Management functions for timers.
        void updateTimers(float deltaTime, double simulationTimestamp, bool simulating);
        std::shared_ptr<TimerController> getTimerController(TimerType type);

        void update(float duration, float timestamp, bool paused);

        void clearTimers();

    private:
        LuaManager();

        //
        void bindData();

        void initSimulationTime();

        // Event management.
        Event::DisableableEventManager mDisableableEventManager;

        //
        static LuaManager singleton;

        sol::state mLuaState;

        //
        ESM::Script* mCurrentScript = nullptr;
        MWWorld::Ptr mCurrentReference;

        // Timers.
        std::shared_ptr<TimerController> mGameTimers;
        std::shared_ptr<TimerController> mSimulateTimers;
        std::shared_ptr<TimerController> mRealTimers;

        sol::object triggerEvent(Event::BaseEvent*);
    };
}

#endif