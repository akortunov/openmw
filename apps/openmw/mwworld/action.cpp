#include "action.hpp"

#include "../mwbase/environment.hpp"
#include "../mwbase/world.hpp"

#include "../mwbase/soundmanager.hpp"

#include "../mwmechanics/actorutil.hpp"

const MWWorld::Ptr& MWWorld::Action::getTarget() const
{
    return mTarget;
}

MWWorld::Action::Action (bool keepSound, const Ptr& target) : mKeepSound (keepSound), mSoundOffset(0), mTarget (target)
{}

MWWorld::Action::~Action() {}

void MWWorld::Action::execute (const Ptr& actor)
{
    if(!mSoundId.empty())
    {
        if(mKeepSound && actor == MWMechanics::getPlayer())
            MWBase::Environment::get().getSoundManager()->playSound(mSoundId, 1.0, 1.0,
                MWBase::SoundManager::Play_TypeSfx, MWBase::SoundManager::Play_Normal, mSoundOffset
            );
        else
        {
            bool local = mTarget.isEmpty() || !mTarget.isInCell(); // no usable target
            if(mKeepSound)
                MWBase::Environment::get().getSoundManager()->playSound3D(
                    (local ? actor : mTarget).getRefData().getPosition().asVec3(),
                    mSoundId, 1.0, 1.0, MWBase::SoundManager::Play_TypeSfx,
                    MWBase::SoundManager::Play_Normal, mSoundOffset
                );
            else
                MWBase::Environment::get().getSoundManager()->playSound3D(local ? actor : mTarget,
                    mSoundId, 1.0, 1.0, MWBase::SoundManager::Play_TypeSfx,
                    MWBase::SoundManager::Play_Normal, mSoundOffset
                );
        }
    }

    executeImp(actor);
}

void MWWorld::Action::execute (const Ptr& actor, float distanceToObject)
{
    if(!mSoundId.empty())
    {
        if(mKeepSound && actor == MWMechanics::getPlayer())
            MWBase::Environment::get().getSoundManager()->playSound(mSoundId, 1.0, 1.0,
                MWBase::SoundManager::Play_TypeSfx, MWBase::SoundManager::Play_Normal, mSoundOffset
            );
        else
        {
            bool local = mTarget.isEmpty() || !mTarget.isInCell(); // no usable target
            if(mKeepSound)
                MWBase::Environment::get().getSoundManager()->playSound3D(
                    (local ? actor : mTarget).getRefData().getPosition().asVec3(),
                    mSoundId, 1.0, 1.0, MWBase::SoundManager::Play_TypeSfx,
                    MWBase::SoundManager::Play_Normal, mSoundOffset
                );
            else
                MWBase::Environment::get().getSoundManager()->playSound3D(local ? actor : mTarget,
                    mSoundId, 1.0, 1.0, MWBase::SoundManager::Play_TypeSfx,
                    MWBase::SoundManager::Play_Normal, mSoundOffset
                );
        }
    }

    executeImp(actor, distanceToObject);
}

void MWWorld::Action::setSound (const std::string& id)
{
    mSoundId = id;
}

void MWWorld::Action::setSoundOffset(float offset)
{
    mSoundOffset=offset;
}
