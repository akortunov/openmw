#include "luamanager.hpp"

#include <components/debug/debuglog.hpp>

/*
#include "MemoryUtil.h"
#include "ScriptUtil.h"
#include "UIUtil.h"
#include "MWSEDefs.h"
*/

#include "timer.hpp"
#include "util.hpp"
#include "script.hpp"
#include "tes3util.hpp"

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"

#include "../mwworld/timestamp.hpp"

#include "structs/activator.hpp"
#include "structs/alchemy.hpp"
#include "structs/apparatus.hpp"
#include "structs/armor.hpp"
#include "structs/birthsign.hpp"
#include "structs/book.hpp"
#include "structs/class.hpp"
#include "structs/clothing.hpp"
#include "structs/creature.hpp"
#include "structs/door.hpp"
#include "structs/enchantment.hpp"
#include "structs/faction.hpp"
#include "structs/gamesetting.hpp"
#include "structs/global.hpp"
#include "structs/ingredient.hpp"
#include "structs/light.hpp"
#include "structs/lockpick.hpp"
#include "structs/magiceffect.hpp"
#include "structs/misc.hpp"
#include "structs/npc.hpp"
#include "structs/probe.hpp"
#include "structs/ptr.hpp"
#include "structs/race.hpp"
#include "structs/repairtool.hpp"
#include "structs/skill.hpp"
#include "structs/sound.hpp"
#include "structs/spell.hpp"
#include "structs/static.hpp"
#include "structs/vectors.hpp"
#include "structs/weapon.hpp"
#include "structs/weapontype.hpp"

/*
// Lua binding files. These are split out rather than kept here to help with compile times.
#include "MemoryUtilLua.h"
#include "StackLua.h"
#include "ScriptUtilLua.h"
#include "StringUtilLua.h"
#include "TES3ActionDataLua.h"
#include "TES3AILua.h"
#include "TES3AttachmentLua.h"
#include "TES3AudioControllerLua.h"
#include "TES3BodyPartLua.h"
#include "TES3CellLua.h"
#include "TES3CollectionsLua.h"
#include "TES3CollisionLua.h"
#include "TES3CombatSessionLua.h"
#include "TES3ContainerLua.h"
#include "TES3DataHandlerLua.h"
#include "TES3DialogueLua.h"
#include "TES3FaderLua.h"
#include "TES3GameLua.h"
#include "TES3GameFileLua.h"
#include "TES3InputControllerLua.h"
#include "TES3InventoryLua.h"
#include "TES3LeveledListLua.h"
#include "TES3MobileActorLua.h"
#include "TES3MobileCreatureLua.h"
#include "TES3MobileNPCLua.h"
#include "TES3MobilePlayerLua.h"
#include "TES3MobileProjectileLua.h"
#include "TES3MoonLua.h"
#include "TES3ReferenceListLua.h"
#include "TES3RegionLua.h"
#include "TES3ScriptLua.h"
#include "TES3MagicEffectInstanceLua.h"
#include "TES3MagicSourceInstanceLua.h"
#include "TES3StatisticLua.h"
#include "TES3TArrayLua.h"
#include "TES3UIElementLua.h"
#include "TES3UIInventoryTileLua.h"
#include "TES3UIManagerLua.h"
#include "TES3UIMenuControllerLua.h"
#include "TES3UIWidgetsLua.h"
#include "TES3WeatherControllerLua.h"
#include "TES3WeatherLua.h"
#include "TES3WorldControllerLua.h"

#include "NICameraLua.h"
#include "NICollisionSwitchLua.h"
#include "NIColorLua.h"
#include "NINodeLua.h"
#include "NIObjectLua.h"
#include "NILightLua.h"
#include "NIPickLua.h"
#include "NIPixelDataLua.h"
#include "NIPropertyLua.h"
#include "NISourceTextureLua.h"
#include "NISwitchNodeLua.h"
#include "NITimeControllerLua.h"
#include "NITriShapeLua.h"

#include "LuaActivationTargetChangedEvent.h"
#include "LuaAddTopicEvent.h"
#include "LuaAttackEvent.h"
#include "LuaCalcHitArmorPieceEvent.h"
#include "LuaCalcBarterPriceEvent.h"
#include "LuaCalcHitChanceEvent.h"
#include "LuaCalcRepairPriceEvent.h"
#include "LuaCalcRestInterruptEvent.h"
#include "LuaCalcSoulValueEvent.h"
#include "LuaCalcSpellPriceEvent.h"
#include "LuaCalcTrainingPriceEvent.h"
#include "LuaCalcTravelPriceEvent.h"
#include "LuaCellChangedEvent.h"
#include "LuaCrimeWitnessedEvent.h"
#include "LuaDamageEvent.h"
#include "LuaEquipEvent.h"
#include "LuaFilterBarterMenuEvent.h"
#include "LuaFilterContentsMenuEvent.h"
#include "LuaFilterInventoryEvent.h"
#include "LuaFilterInventorySelectEvent.h"
#include "LuaFilterSoulGemTargetEvent.h"
#include "LuaFrameEvent.h"
#include "LuaGenericUiActivatedEvent.h"
#include "LuaGenericUiPostEvent.h"
#include "LuaGenericUiPreEvent.h"
#include "LuaInfoGetTextEvent.h"
#include "LuaInfoResponseEvent.h"
#include "LuaItemDroppedEvent.h"
#include "LuaItemTileUpdatedEvent.h"
#include "LuaKeyDownEvent.h"
#include "LuaKeyUpEvent.h"
#include "LuaLevelUpEvent.h"
#include "LuaLoadedGameEvent.h"
#include "LuaMagicCastedEvent.h"
#include "LuaMenuStateEvent.h"
#include "LuaMouseAxisEvent.h"
#include "LuaMouseButtonDownEvent.h"
#include "LuaMouseButtonUpEvent.h"
#include "LuaMouseWheelEvent.h"
#include "LuaMusicSelectTrackEvent.h"
#include "LuaPotionBrewedEvent.h"
#include "LuaProjectileExpireEvent.h"
#include "LuaRestInterruptEvent.h"
#include "LuaSimulateEvent.h"
#include "LuaSkillRaisedEvent.h"
#include "LuaSpellCastedEvent.h"
#include "LuaSpellResistEvent.h"
#include "LuaSpellTickEvent.h"
#include "LuaUiRefreshedEvent.h"
#include "LuaUiSpellTooltipEvent.h"
#include "LuaWeaponReadiedEvent.h"
#include "LuaWeaponUnreadiedEvent.h"
#include "LuaWeatherChangedImmediateEvent.h"
#include "LuaWeatherCycledEvent.h"
#include "LuaWeatherTransitionFinishedEvent.h"
#include "LuaWeatherTransitionStartedEvent.h"
*/

#include <unordered_map>

namespace MWLua
{
    // Initialize singleton.
    LuaManager LuaManager::singleton;

    // We still abort the program if an unprotected lua error happens. Here we at least
    // get it in the log so it can be debugged.
    int panic(lua_State* L)
    {
        const char* message = lua_tostring(L, -1);
        Log(Debug::Error) << (message ? message : "An unexpected error occurred and forced the lua state to call atpanic.");
        return 0;
    }

    int exceptionHandler(lua_State* L, sol::optional<const std::exception&> maybe_exception, sol::string_view description)
    {
        if (maybe_exception) {
            const std::exception& ex = *maybe_exception;
            Log(Debug::Error) << "An unhandled exception occurred: " << ex.what();
        }
        else {
            Log(Debug::Error) << "An unhandled exception occurred: " << description.data();
        }

        logStackTrace();

        return sol::stack::push(L, description);
    }

    // LuaManager constructor. This is private, as a singleton.
    LuaManager::LuaManager()
    {
        // Open default lua libraries.
        mLuaState.open_libraries();

        // Override the default atpanic to print to the log.
        mLuaState.set_panic(&panic);
        mLuaState.set_exception_handler(&exceptionHandler);

        // Set up our timers.
        mGameTimers = std::make_shared<TimerController>();
        mSimulateTimers = std::make_shared<TimerController>();
        mRealTimers = std::make_shared<TimerController>();

        // Bind our data types.
        bindData();
    }

    void LuaManager::bindData()
    {
        // Bind our LuaScript type, which is used for holding script contexts.
        mLuaState.new_usertype<Script>("LuaScript",
            sol::constructors<Script()>(),

            // Implement dynamic object metafunctions.
            sol::meta_function::index, &DynamicLuaObject::dynamic_get,
            sol::meta_function::new_index, &DynamicLuaObject::dynamic_set,
            sol::meta_function::length, [](DynamicLuaObject& d) { return d.entries.size(); },

            // Set up read-only properties.
            "script", sol::readonly(&Script::mScript),
            "reference", sol::readonly(&Script::mReference)//,
            //"context", sol::readonly_property([](LuaScript& self) { return std::shared_ptr<ScriptContext>(new ScriptContext(self.script)); })

            );

        // Create the base of API tables.
        mLuaState["omw"] = mLuaState.create_table();

        // Expose timers.
        bindLuaTimer();
        mLuaState["omw"]["realTimers"] = mRealTimers;
        mLuaState["omw"]["simulateTimers"] = mSimulateTimers;
        mLuaState["omw"]["gameTimers"] = mGameTimers;

        bindTES3Activator();
        bindTES3Alchemy();
        bindTES3Apparatus();
        bindTES3Armor();
        bindTES3BirthSign();
        bindTES3Book();
        bindTES3Class();
        bindTES3Clothing();
        bindTES3Creature();
        bindTES3Door();
        bindTES3Enchantment();
        bindTES3GameSetting();
        bindTES3GlobalVariable();
        bindTES3Faction();
        bindTES3Ingredient();
        bindTES3Light();
        bindTES3Lockpick();
        bindTES3MagicEffect();
        bindTES3Misc();
        bindTES3NPC();
        bindTES3Probe();
        bindTES3Race();
        bindTES3Reference();
        bindTES3RepairTool();
        bindTES3Skill();
        bindTES3Sound();
        bindTES3Spell();
        bindTES3Static();
        bindTES3Vectors();
        bindTES3Weapon();
        bindTES3WeaponType();

        // Bind TES3 data types.
        /*
        bindTES3ActionData();
        bindTES3AI();
        bindTES3Attachment();
        bindTES3AudioController();
        bindTES3BodyPart();
        bindTES3Cell();
        bindTES3Collections();
        bindTES3Collision();
        bindTES3CombatSession();
        bindTES3Container();
        bindTES3DataHandler();
        bindTES3Dialogue();
        bindTES3Fader();
        bindTES3Game();
        bindTES3GameFile();
        bindTES3InputController();
        bindTES3Inventory();
        bindTES3LeveledList();
        bindTES3MagicEffectInstance();
        bindTES3MagicSourceInstance();
        bindTES3MobileActor();
        bindTES3MobileCreature();
        bindTES3MobileNPC();
        bindTES3MobilePlayer();
        bindTES3MobileProjectile();
        bindTES3Moon();
        bindTES3ReferenceList();
        bindTES3Region();
        bindTES3Script();
        bindTES3Statistic();
        bindTES3TArray();
        bindTES3Weather();
        bindTES3WeatherController();
        bindTES3WorldController();

        bindTES3UIElement();
        bindTES3UIInventoryTile();
        bindTES3UIManager();
        bindTES3UIMenuController();
        bindTES3UIWidgets();

        // Bind NI data types.
        bindNICamera();
        bindNICollisionSwitch();
        bindNIColor();
        bindNINode();
        bindNIObject();
        bindNILight();
        bindNIPick();
        bindNIPixelData();
        bindNIProperties();
        bindNISourceTexture();
        bindNISwitchNode();
        bindNITimeController();
        bindNITriShape();
        */

        // Bind our disable event manager.
        Event::DisableableEventManager::bindToLua();
        mLuaState["omw"]["disableableEvents"] = &mDisableableEventManager;
    }

    void LuaManager::update(float duration, float timestamp, bool paused)
    {
        updateTimers(duration, timestamp, !paused);
    }

    ThreadedStateHandle::ThreadedStateHandle(LuaManager * manager) : state(manager->mLuaState), luaManager(manager)
    {
        //luaManager->claimLuaThread();
    }

    ThreadedStateHandle::~ThreadedStateHandle()
    {
        //luaManager->releaseLuaThread();
    }

    sol::object ThreadedStateHandle::triggerEvent(Event::BaseEvent* e)
    {
        return luaManager->triggerEvent(e);
    }

    /*
    // Guarded access to the userdata cache.
    sol::object ThreadedStateHandle::getCachedUserdata(TES3::BaseObject* o) {
        return luaManager->getCachedUserdata(o);
    }

    sol::object ThreadedStateHandle::getCachedUserdata(TES3::MobileObject* mo) {
        return luaManager->getCachedUserdata(mo);
    }

    void ThreadedStateHandle::insertUserdataIntoCache(TES3::BaseObject* o, sol::object lo) {
        luaManager->insertUserdataIntoCache(o, lo);
    }

    void ThreadedStateHandle::insertUserdataIntoCache(TES3::MobileObject* mo, sol::object lo) {
        luaManager->insertUserdataIntoCache(mo, lo);
    }

    void ThreadedStateHandle::removeUserdataFromCache(TES3::BaseObject* o) {
        luaManager->removeUserdataFromCache(o);
    }

    void ThreadedStateHandle::removeUserdataFromCache(TES3::MobileObject* mo) {
        luaManager->removeUserdataFromCache(mo);
    }
    */

    ThreadedStateHandle LuaManager::getThreadSafeStateHandle()
    {
        return ThreadedStateHandle(this);
    }

    void LuaManager::hook()
    {
        initSimulationTime();

        // FIXME: temporary register data before init
        bindTES3Util();

        // Execute init.lua
        sol::protected_function_result result = mLuaState.safe_script_file("scripts/init.lua");
        if (!result.valid())
        {
            sol::error error = result;
            Log(Debug::Error) << "[LuaManager] ERROR: Failed to initialize Lua interface: " << error.what();
            return;
        }

        // Bind libraries.
        //bindMWSEMemoryUtil();
        //bindMWSEStack();
        //bindScriptUtil();
        //bindStringUtil();


        // Alter existing libraries.
        //luaState["os"]["exit"] = customOSExit;

        // UI framework hooks
        //TES3::UI::hook();

        // Install custom magic effect hooks.
        //TES3::MagicEffectController::InstallCustomMagicEffectController();

        // Look for main.lua scripts in the usual directories.
        //executeMainModScripts("Data Files/MWSE/core");
        //executeMainModScripts("Data Files/MWSE/mods");

        // Temporary backwards compatibility for old-style MWSE mods.
        //executeMainModScripts("Data Files/MWSE/lua", "mod_init.lua");
    }

    void LuaManager::cleanup()
    {
        // Clean up our handles to our override tables. Helps to prevent a crash when
        // closing mid-execution.
        /*
        scriptOverrides.clear();

        userdataMapMutex.lock();
        userdataCache.clear();
        userdataMapMutex.unlock();
        */
    }

    ESM::Script* LuaManager::getCurrentScript()
    {
        return mCurrentScript;
    }

    void LuaManager::setCurrentScript(ESM::Script* script)
    {
        mCurrentScript = script;
    }

    MWWorld::Ptr LuaManager::getCurrentReference()
    {
        return mCurrentReference;
    }

    void LuaManager::setCurrentReference(MWWorld::Ptr ptr)
    {
        mCurrentReference = ptr;
    }

    sol::object LuaManager::triggerEvent(Event::BaseEvent* baseEvent)
    {
        //auto stateHandle = getThreadSafeStateHandle();

        sol::object response = Event::trigger(baseEvent->getEventName(), baseEvent->createEventTable(), baseEvent->getEventOptions());
        delete baseEvent;
        return response;
    }

    void LuaManager::updateTimers(float deltaTime, double simulationTimestamp, bool simulating)
    {
        mRealTimers->incrementClock(deltaTime);
        mGameTimers->setClock(simulationTimestamp);

        if (simulating)
        {
            mSimulateTimers->incrementClock(deltaTime);
        }
    }

    void LuaManager::initSimulationTime()
    {
        // Reset the clocks for each timer.
        mRealTimers->setClock(0.0);
        mSimulateTimers->setClock(0.0);

        auto timestamp = MWBase::Environment::get().getWorld()->getTimeStamp();
        float time = timestamp.getDay() * 24 + timestamp.getHour();
        mGameTimers->setClock(time);
    }

    void LuaManager::clearTimers()
    {
        mRealTimers->clearTimers();
        mSimulateTimers->clearTimers();
        mGameTimers->clearTimers();

        initSimulationTime();
    }

    std::shared_ptr<TimerController> LuaManager::getTimerController(TimerType type)
    {
        switch (type)
        {
            case TimerType::RealTime: return mRealTimers;
            case TimerType::SimulationTime: return mSimulateTimers;
            case TimerType::GameTime: return mGameTimers;
        }
        return nullptr;
    }
}
