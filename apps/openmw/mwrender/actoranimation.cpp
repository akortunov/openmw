#include "actoranimation.hpp"
#include <utility>

#include <osg/Node>
#include <osg/Group>
#include <osg/MatrixTransform>
#include <osg/Vec4f>

#include <components/esm/loadligh.hpp>
#include <components/esm/loadcell.hpp>

#include <components/resource/resourcesystem.hpp>
#include <components/resource/scenemanager.hpp>

#include <components/sceneutil/attach.hpp>
#include <components/sceneutil/lightmanager.hpp>
#include <components/sceneutil/lightutil.hpp>
#include <components/sceneutil/visitor.hpp>

#include <components/fallback/fallback.hpp>

#include <components/misc/stringops.hpp>

#include <components/settings/settings.hpp>

#include <components/vfs/manager.hpp>

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"
#include "../mwworld/ptr.hpp"
#include "../mwworld/class.hpp"
#include "../mwworld/cellstore.hpp"
#include "../mwmechanics/actorutil.hpp"

#include "vismask.hpp"

namespace MWRender
{

ActorAnimation::ActorAnimation(const MWWorld::Ptr& ptr, osg::ref_ptr<osg::Group> parentNode, Resource::ResourceSystem* resourceSystem)
    : Animation(ptr, parentNode, resourceSystem)
{
    MWWorld::ContainerStore& store = mPtr.getClass().getContainerStore(mPtr);

    for (MWWorld::ConstContainerStoreIterator iter = store.cbegin(MWWorld::ContainerStore::Type_Light);
         iter != store.cend(); ++iter)
    {
        const ESM::Light* light = iter->get<ESM::Light>()->mBase;
        if (!(light->mData.mFlags & ESM::Light::Carry))
        {
            addHiddenItemLight(*iter, light);
        }
    }

    mWeaponSheathing = Settings::Manager::getBool("weapon sheathing", "Game");
}

ActorAnimation::~ActorAnimation()
{
    for (ItemLightMap::iterator iter = mItemLights.begin(); iter != mItemLights.end(); ++iter)
    {
        mInsert->removeChild(iter->second);
    }

    mScabbard.reset();
    mHolsteredWeapon.reset();
    mHolsteredShield.reset();
}

PartHolderPtr ActorAnimation::getWeaponPart(const std::string& model, const std::string& bonename, bool enchantedGlow, osg::Vec4f* glowColor)
{
    osg::Group* parent = getBoneByName(bonename);
    if (!parent)
        return NULL;

    osg::ref_ptr<osg::Node> instance = mResourceSystem->getSceneManager()->getInstance(model, parent);

    const NodeMap& nodeMap = getNodeMap();
    NodeMap::const_iterator found = nodeMap.find(Misc::StringUtils::lowerCase(bonename));
    if (found == nodeMap.end())
        return PartHolderPtr();

    if (enchantedGlow)
        addGlow(instance, *glowColor);

    return PartHolderPtr(new PartHolder(instance));
}

osg::Group* ActorAnimation::getBoneByName(std::string boneName)
{
    if (!mObjectRoot)
        return NULL;

    SceneUtil::FindByNameVisitor findVisitor (boneName);
    mObjectRoot->accept(findVisitor);

    return findVisitor.mFoundNode;
}

std::string ActorAnimation::getHolsteredWeaponBoneName(const MWWorld::ConstPtr& weapon)
{
    std::string boneName = "";
    if(weapon.isEmpty())
        return boneName;

    const std::string &type = weapon.getClass().getTypeName();
    if(type == typeid(ESM::Weapon).name())
    {
        const MWWorld::LiveCellRef<ESM::Weapon> *ref = weapon.get<ESM::Weapon>();
        ESM::Weapon::Type weaponType = (ESM::Weapon::Type)ref->mBase->mData.mType;
        switch(weaponType)
        {
            case ESM::Weapon::ShortBladeOneHand:
            case ESM::Weapon::LongBladeOneHand:
            case ESM::Weapon::BluntOneHand:
            case ESM::Weapon::AxeOneHand:
                boneName = "Bip01 L WeaponOneHand";
                break;
            case ESM::Weapon::LongBladeTwoHand:
            case ESM::Weapon::BluntTwoClose:
            case ESM::Weapon::AxeTwoHand:
                boneName = "Bip01 TwoClose";
                break;
            case ESM::Weapon::BluntTwoWide:
            case ESM::Weapon::SpearTwoWide:
                boneName = "Bip01 TwoWide";
                break;
            case ESM::Weapon::MarksmanBow:
                boneName = "Bip01 Bow";
                break;
            case ESM::Weapon::MarksmanCrossbow:
                boneName = "Bip01 Crossbow";
                break;
            default:
                break;
        }
    }

    return boneName;
}

std::string ActorAnimation::getQuiverBoneName(const MWWorld::ConstPtr& weapon)
{
    std::string boneName = "";
    if(weapon.isEmpty())
        return boneName;

    const std::string &type = weapon.getClass().getTypeName();
    if(type == typeid(ESM::Weapon).name())
    {
        const MWWorld::LiveCellRef<ESM::Weapon> *ref = weapon.get<ESM::Weapon>();
        ESM::Weapon::Type weaponType = (ESM::Weapon::Type)ref->mBase->mData.mType;
        switch(weaponType)
        {
            case ESM::Weapon::MarksmanBow:
                boneName = "Bip01 Arrow";
                break;
            case ESM::Weapon::MarksmanCrossbow:
                boneName = "Bip01 Bolt";
                break;
            default:
                break;
        }
    }

    return boneName;
}

void ActorAnimation::updateHolsteredWeapon(bool showHolsteredWeapons)
{
    if (!mWeaponSheathing)
        return;

    if (!mPtr.getClass().hasInventoryStore(mPtr))
        return;

    mHolsteredWeapon.reset();
    mScabbard.reset();

    const MWWorld::InventoryStore& inv = mPtr.getClass().getInventoryStore(mPtr);
    MWWorld::ConstContainerStoreIterator weapon = inv.getSlot(MWWorld::InventoryStore::Slot_CarriedRight);
    if(weapon == inv.end())
        return;

    osg::Vec4f glowColor = getEnchantmentColor(*weapon);
    std::string mesh = weapon->getClass().getModel(*weapon);
    std::string boneName = getHolsteredWeaponBoneName(*weapon);
    if (mesh.empty() || boneName.empty())
        return;

    if (showHolsteredWeapons && !boneName.empty())
    {
        bool isEnchanted = !weapon->getClass().getEnchantment(*weapon).empty();
        mHolsteredWeapon = getWeaponPart(mesh, boneName, isEnchanted, &glowColor);
    }

    // If there is a scabbard model for this mesh, show it
    std::string scabbardName = mesh.replace(mesh.size()-4, 4, "_sbd.nif");
    if(!mResourceSystem->getVFS()->exists(scabbardName))
        return;

    mScabbard = getWeaponPart(scabbardName, boneName, false, &glowColor);
}

void ActorAnimation::updateHolsteredShield(bool showCarriedLeft)
{
    if (!mWeaponSheathing)
        return;

    if (!mPtr.getClass().hasInventoryStore(mPtr))
        return;

    mHolsteredShield.reset();

    const MWWorld::InventoryStore& inv = mPtr.getClass().getInventoryStore(mPtr);
    MWWorld::ConstContainerStoreIterator shield = inv.getSlot(MWWorld::InventoryStore::Slot_CarriedLeft);
    if (shield == inv.end())
        return;

    if (shield->getTypeName() != typeid(ESM::Armor).name())
        return;

    osg::Vec4f glowColor = getEnchantmentColor(*shield);
    std::string mesh = shield->getClass().getModel(*shield);
    std::string boneName = "Bip01 Shield";
    if (mesh.empty() || boneName.empty())
        return;

    if (!showCarriedLeft && !boneName.empty())
    {
        bool isEnchanted = !shield->getClass().getEnchantment(*shield).empty();
        mHolsteredShield = getWeaponPart(mesh, boneName, isEnchanted, &glowColor);
    }
}

void ActorAnimation::updateQuiver(bool arrowAttached)
{
    if (!mWeaponSheathing)
        return;

    if (!mPtr.getClass().hasInventoryStore(mPtr))
        return;

    mQuiver.reset();

    const MWWorld::InventoryStore& inv = mPtr.getClass().getInventoryStore(mPtr);
    MWWorld::ConstContainerStoreIterator weapon = inv.getSlot(MWWorld::InventoryStore::Slot_CarriedRight);
    if(weapon == inv.end())
        return;

    std::string mesh = weapon->getClass().getModel(*weapon);
    std::string boneName = getQuiverBoneName(*weapon);
    if (mesh.empty() || boneName.empty())
        return;

    // If there is a scabbard model for this mesh, show it
    std::string quiverName = mesh.replace(mesh.size()-4, 4, "_quiver.nif");
    if(!mResourceSystem->getVFS()->exists(quiverName))
        return;

    mQuiver = getWeaponPart(quiverName, boneName);

    MWWorld::ConstContainerStoreIterator ammo = inv.getSlot(MWWorld::InventoryStore::Slot_Ammunition);
    if (ammo == inv.end())
        return;

    int count = ammo->getRefData().getCount();
    if (arrowAttached)
        count--;
    if (count <= 0)
        return;

    bool suitableAmmo = false;
    if (weapon->get<ESM::Weapon>()->mBase->mData.mType == ESM::Weapon::MarksmanCrossbow)
        suitableAmmo = ammo->get<ESM::Weapon>()->mBase->mData.mType == ESM::Weapon::Bolt;
    else if (weapon->get<ESM::Weapon>()->mBase->mData.mType == ESM::Weapon::MarksmanBow)
        suitableAmmo = ammo->get<ESM::Weapon>()->mBase->mData.mType == ESM::Weapon::Arrow;

    if (mQuiver && suitableAmmo)
    {
        GetArrowNodesVisitor findVisitor (count);
        mQuiver->getNode()->accept(findVisitor);
        std::vector<osg::Group*> arrowNodes = findVisitor.mArrowNodes;

        osg::Vec4f glowColor = getEnchantmentColor(*ammo);
        std::string model = ammo->getClass().getModel(*ammo);
        for (std::vector<osg::Group*>::iterator it = arrowNodes.begin() ; it != arrowNodes.end(); ++it)
        {
            osg::ref_ptr<osg::Node> arrow = mResourceSystem->getSceneManager()->getInstance(model, *it);
            if (!ammo->getClass().getEnchantment(*ammo).empty())
                addGlow(arrow, glowColor);
        }
    }
}

void ActorAnimation::itemAdded(const MWWorld::ConstPtr& item, int /*count*/)
{
    if (item.getTypeName() == typeid(ESM::Light).name())
    {
        const ESM::Light* light = item.get<ESM::Light>()->mBase;
        if (!(light->mData.mFlags & ESM::Light::Carry))
        {
            addHiddenItemLight(item, light);
        }
    }
}

void ActorAnimation::itemRemoved(const MWWorld::ConstPtr& item, int /*count*/)
{
    if (item.getTypeName() == typeid(ESM::Light).name())
    {
        ItemLightMap::iterator iter = mItemLights.find(item);
        if (iter != mItemLights.end())
        {
            if (!item.getRefData().getCount())
            {
                removeHiddenItemLight(item);
            }
        }
    }
}

void ActorAnimation::addHiddenItemLight(const MWWorld::ConstPtr& item, const ESM::Light* esmLight)
{
    if (mItemLights.find(item) != mItemLights.end())
        return;

    const Fallback::Map* fallback = MWBase::Environment::get().getWorld()->getFallback();
    static bool outQuadInLin = fallback->getFallbackBool("LightAttenuation_OutQuadInLin");
    static bool useQuadratic = fallback->getFallbackBool("LightAttenuation_UseQuadratic");
    static float quadraticValue = fallback->getFallbackFloat("LightAttenuation_QuadraticValue");
    static float quadraticRadiusMult = fallback->getFallbackFloat("LightAttenuation_QuadraticRadiusMult");
    static bool useLinear = fallback->getFallbackBool("LightAttenuation_UseLinear");
    static float linearRadiusMult = fallback->getFallbackFloat("LightAttenuation_LinearRadiusMult");
    static float linearValue = fallback->getFallbackFloat("LightAttenuation_LinearValue");
    bool exterior = mPtr.isInCell() && mPtr.getCell()->getCell()->isExterior();

    osg::Vec4f ambient(1,1,1,1);
    osg::ref_ptr<SceneUtil::LightSource> lightSource = SceneUtil::createLightSource(esmLight, Mask_Lighting, exterior, outQuadInLin,
                                 useQuadratic, quadraticValue, quadraticRadiusMult, useLinear, linearRadiusMult, linearValue, ambient);

    mInsert->addChild(lightSource);

    if (mLightListCallback && mPtr == MWMechanics::getPlayer())
        mLightListCallback->getIgnoredLightSources().insert(lightSource.get());

    mItemLights.insert(std::make_pair(item, lightSource));
}

void ActorAnimation::removeHiddenItemLight(const MWWorld::ConstPtr& item)
{
    ItemLightMap::iterator iter = mItemLights.find(item);
    if (iter == mItemLights.end())
        return;

    if (mLightListCallback && mPtr == MWMechanics::getPlayer())
    {
        std::set<SceneUtil::LightSource*>::iterator ignoredIter = mLightListCallback->getIgnoredLightSources().find(iter->second.get());
        if (ignoredIter != mLightListCallback->getIgnoredLightSources().end())
            mLightListCallback->getIgnoredLightSources().erase(ignoredIter);
    }

    mInsert->removeChild(iter->second);
    mItemLights.erase(iter);
}

void GetArrowNodesVisitor::apply(osg::Group& node)
{
    applyImpl(node);
    traverse(node);
}

void GetArrowNodesVisitor::applyImpl(osg::Group& node)
{
    for (int i=0; i<std::min(mAmmoCount, 10); i++)
    {
        const std::string toFind = "Arrow"+std::to_string(i);
        if (Misc::StringUtils::ciCompareLen(node.getName(), toFind, toFind.size()) == 0)
        {
            mArrowNodes.push_back(&node);
        }
    }
}

}
