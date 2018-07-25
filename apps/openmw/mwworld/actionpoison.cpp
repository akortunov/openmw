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
            MWWorld::ContainerStoreIterator weapon = targetClass.getInventoryStore(actor).getSlot(MWWorld::InventoryStore::Slot_CarriedRight);

            // apply poison to weapon
            if (weapon != targetClass.getInventoryStore(actor).end())
            {
                //weapon->getContainerStore()->unstack(*weapon, actor);
                weapon->getCellRef().setPoison(mId);
                //weapon->getContainerStore()->restack(*weapon);

                actor.getClass().getContainerStore(actor).remove(getTarget(), 1, actor);
            }
        }
    }
}
