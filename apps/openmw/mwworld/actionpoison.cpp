#include "actionpoison.hpp"

#include "class.hpp"

#include "../mwbase/environment.hpp"
#include "../mwbase/windowmanager.hpp"
#include "../mwbase/world.hpp"

#include "../mwworld/inventorystore.hpp"

#include "../mwmechanics/actorutil.hpp"

namespace MWWorld
{
    ActionPoison::ActionPoison (const Ptr& object, const std::string& id)
    : Action (false, object), mId (id)
    {}

    void ActionPoison::executeImp (const Ptr& actor)
    {
        if(actor == MWMechanics::getPlayer() && MWMechanics::isPlayerInCombat())
        { // Player can not use poisons in combat
            MWBase::Environment::get().getWindowManager()->messageBox("#{sInventoryMessage3}");
            return;
        }

        const MWWorld::Class& targetClass = actor.getClass();
        if (targetClass.hasInventoryStore(actor))
        {
            InventoryStore& invStore = targetClass.getInventoryStore(actor);
            MWWorld::ContainerStoreIterator weapon = invStore.getSlot(MWWorld::InventoryStore::Slot_CarriedRight);

            // apply poison to weapon
            if (weapon != invStore.end())
            {
                MWWorld::Ptr weaponPtr = *weapon;
                if (weaponPtr.getRefData().getCount() > 1)
                {
                    MWWorld::ContainerStoreIterator newStack = invStore.unstack(weaponPtr, actor);
                    weaponPtr.getCellRef().setPoison(mId);
                    invStore.equip(MWWorld::InventoryStore::Slot_CarriedRight, newStack, actor);
                }
                else
                {
                    weaponPtr.getCellRef().setPoison(mId);
                    //invStore.restack(weaponPtr);
                }

                invStore.remove(getTarget(), 1, actor);
            }
        }
    }
}
