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
        virtual void updateHolsteredWeapon(bool showHolsteredWeapons);
        virtual std::string getHolsteredWeaponBone(const MWWorld::ConstPtr& weapon);
        virtual PartHolderPtr insertHolsteredWeapon(const std::string& model, const std::string& bonename,
                                        const std::string& bonefilter, bool enchantedGlow, osg::Vec4f* glowColor);

    private:
        void addHiddenItemLight(const MWWorld::ConstPtr& item, const ESM::Light* esmLight);
        void removeHiddenItemLight(const MWWorld::ConstPtr& item);

        typedef std::map<MWWorld::ConstPtr, osg::ref_ptr<SceneUtil::LightSource> > ItemLightMap;
        ItemLightMap mItemLights;
        PartHolderPtr mHolsteredWeapon;
};

}

#endif
