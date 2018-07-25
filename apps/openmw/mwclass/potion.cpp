#include "potion.hpp"

#include <components/esm/loadalch.hpp>

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"
#include "../mwbase/windowmanager.hpp"

#include "../mwworld/ptr.hpp"
#include "../mwworld/actionapply.hpp"
#include "../mwworld/actionequip.hpp"
#include "../mwworld/actiontake.hpp"
#include "../mwworld/cellstore.hpp"
#include "../mwworld/esmstore.hpp"
#include "../mwworld/inventorystore.hpp"
#include "../mwphysics/physicssystem.hpp"
#include "../mwworld/nullaction.hpp"

#include "../mwgui/tooltips.hpp"

#include "../mwrender/objects.hpp"
#include "../mwrender/renderinginterface.hpp"

#include "../mwmechanics/alchemy.hpp"

namespace MWClass
{
    bool Potion::isPoison(const MWWorld::ConstPtr& ptr) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();

        for (std::vector<ESM::ENAMstruct>::const_iterator effectIt (ref->mBase->mEffects.mList.begin());
             effectIt != ref->mBase->mEffects.mList.end(); ++effectIt)
        {
            const ESM::MagicEffect *magicEffect =
                MWBase::Environment::get().getWorld()->getStore().get<ESM::MagicEffect>().find (
                effectIt->mEffectID);

            // Re-casting a bound equipment effect has no effect if the spell is still active
            if (magicEffect->mData.mFlags & ESM::MagicEffect::Harmful)
            {
                continue;
            }

            return false;
        }

        return true;
    }

    void Potion::insertObjectRendering (const MWWorld::Ptr& ptr, const std::string& model, MWRender::RenderingInterface& renderingInterface) const
    {
        if (!model.empty()) {
            renderingInterface.getObjects().insertModel(ptr, model);
        }
    }

    void Potion::insertObject(const MWWorld::Ptr& ptr, const std::string& model, MWPhysics::PhysicsSystem& physics) const
    {
        // TODO: add option somewhere to enable collision for placeable objects
    }

    std::string Potion::getModel(const MWWorld::ConstPtr &ptr) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();

        const std::string &model = ref->mBase->mModel;
        if (!model.empty()) {
            return "meshes\\" + model;
        }
        return "";
    }

    std::string Potion::getName (const MWWorld::ConstPtr& ptr) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();

        return ref->mBase->mName;
    }

    std::shared_ptr<MWWorld::Action> Potion::activate (const MWWorld::Ptr& ptr,
        const MWWorld::Ptr& actor) const
    {
        return defaultItemActivate(ptr, actor);
    }

    std::string Potion::getScript (const MWWorld::ConstPtr& ptr) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref =
            ptr.get<ESM::Potion>();

        return ref->mBase->mScript;
    }

    int Potion::getValue (const MWWorld::ConstPtr& ptr) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();

        return ref->mBase->mData.mValue;
    }

    void Potion::registerSelf()
    {
        std::shared_ptr<Class> instance (new Potion);

        registerClass (typeid (ESM::Potion).name(), instance);
    }

    std::string Potion::getUpSoundId (const MWWorld::ConstPtr& ptr) const
    {
        return std::string("Item Potion Up");
    }

    std::string Potion::getDownSoundId (const MWWorld::ConstPtr& ptr) const
    {
        return std::string("Item Potion Down");
    }

    std::string Potion::getInventoryIcon (const MWWorld::ConstPtr& ptr) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();

        return ref->mBase->mIcon;
    }

    bool Potion::hasToolTip (const MWWorld::ConstPtr& ptr) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();

        return (ref->mBase->mName != "");
    }

    MWGui::ToolTipInfo Potion::getToolTipInfo (const MWWorld::ConstPtr& ptr, int count) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();

        MWGui::ToolTipInfo info;
        info.caption = ref->mBase->mName + MWGui::ToolTips::getCountString(count);
        info.icon = ref->mBase->mIcon;

        std::string text;

        text += "\n#{sWeight}: " + MWGui::ToolTips::toString(ref->mBase->mData.mWeight);
        text += MWGui::ToolTips::getValueString(ref->mBase->mData.mValue, "#{sValue}");

        info.effects = MWGui::Widgets::MWEffectList::effectListFromESM(&ref->mBase->mEffects);

        // hide effects the player doesn't know about
        MWWorld::Ptr player = MWBase::Environment::get().getWorld ()->getPlayerPtr();
        for (unsigned int i=0; i<info.effects.size(); ++i)
            info.effects[i].mKnown = MWMechanics::Alchemy::knownEffect(i, player);

        info.isPotion = true;

        if (MWBase::Environment::get().getWindowManager()->getFullHelp()) {
            text += MWGui::ToolTips::getCellRefString(ptr.getCellRef());
            text += MWGui::ToolTips::getMiscString(ref->mBase->mScript, "Script");
        }

        info.text = text;

        return info;
    }

    std::pair<std::vector<int>, bool> Potion::getEquipmentSlots (const MWWorld::ConstPtr& ptr) const
    {
        std::vector<int> slots_;
        bool stack = false;

        if (isPoison(ptr))
        {
            slots_.push_back (int (MWWorld::InventoryStore::Slot_Poison));
            stack = true;
        }

        return std::make_pair (slots_, stack);
    }

    std::shared_ptr<MWWorld::Action> Potion::use (const MWWorld::Ptr& ptr, bool force) const
    {
        if (isPoison(ptr))
        {
            std::shared_ptr<MWWorld::Action> action (
                new MWWorld::ActionEquip (ptr));

            action->setSound ("Item Potion Down");

            return action;
        }
        else
        {
            MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();

            std::shared_ptr<MWWorld::Action> action (
                new MWWorld::ActionApply (ptr, ref->mBase->mId));

            action->setSound ("Drink");

            return action;
        }
    }

    MWWorld::Ptr Potion::copyToCellImpl(const MWWorld::ConstPtr &ptr, MWWorld::CellStore &cell) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();

        return MWWorld::Ptr(cell.insert(ref), &cell);
    }

    bool Potion::canSell (const MWWorld::ConstPtr& item, int npcServices) const
    {
        return (npcServices & ESM::NPC::Potions) != 0;
    }

    float Potion::getWeight(const MWWorld::ConstPtr &ptr) const
    {
        const MWWorld::LiveCellRef<ESM::Potion> *ref = ptr.get<ESM::Potion>();
        return ref->mBase->mData.mWeight;
    }
}
