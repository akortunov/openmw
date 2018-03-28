#ifndef GAME_RENDER_ACTORANIMATION_H
#define GAME_RENDER_ACTORANIMATION_H

#include <map>

#include <osg/ref_ptr>

#include "../mwworld/containerstore.hpp"
#include "../mwworld/inventorystore.hpp"

#include "animation.hpp"

namespace osg
{
    class Node;
}

namespace MWWorld
{
    class ConstPtr;
}

namespace SceneUtil
{
    class LightSource;
    class LightListCallback;
}

namespace MWRender
{

class ActorAnimation : public Animation, public MWWorld::ContainerStoreListener
{
    public:
        ActorAnimation(const MWWorld::Ptr &ptr, osg::ref_ptr<osg::Group> parentNode, Resource::ResourceSystem* resourceSystem);
        virtual ~ActorAnimation();

        virtual void itemAdded(const MWWorld::ConstPtr& item, int count);
        virtual void itemRemoved(const MWWorld::ConstPtr& item, int count);

    protected:
        bool mWeaponSheathing;
        osg::Group* getBoneByName(std::string boneName);
        virtual void updateHolsteredWeapon(bool showHolsteredWeapons);
        virtual void updateHolsteredShield(bool showCarriedLeft);
        virtual void updateQuiver(bool arrowAttached = false);
        virtual std::string getHolsteredWeaponBoneName(const MWWorld::ConstPtr& weapon);
        virtual std::string getQuiverBoneName(const MWWorld::ConstPtr& weapon);
        bool hasBow();
        virtual PartHolderPtr getWeaponPart(const std::string& model, const std::string& bonename, bool enchantedGlow, osg::Vec4f* glowColor);
        virtual PartHolderPtr getWeaponPart(const std::string& model, const std::string& bonename)
        {
            osg::Vec4f stubColor = osg::Vec4f(0,0,0,0);
            return getWeaponPart(model, bonename, false, &stubColor);
        };

    private:
        void addHiddenItemLight(const MWWorld::ConstPtr& item, const ESM::Light* esmLight);
        void removeHiddenItemLight(const MWWorld::ConstPtr& item);

        typedef std::map<MWWorld::ConstPtr, osg::ref_ptr<SceneUtil::LightSource> > ItemLightMap;
        ItemLightMap mItemLights;
        PartHolderPtr mHolsteredWeapon;
        PartHolderPtr mHolsteredShield;
        PartHolderPtr mScabbard;
        PartHolderPtr mQuiver;
};

class GetArrowNodesVisitor : public osg::NodeVisitor
{
public:
    GetArrowNodesVisitor(int ammoCount)
        : osg::NodeVisitor(TRAVERSE_ALL_CHILDREN)
        , mAmmoCount(ammoCount)
    {
    }

    virtual void apply(osg::Group& group);

    void applyImpl(osg::Group& node);

    int mAmmoCount;
    std::vector<osg::Group*> mArrowNodes;
};

}

#endif
