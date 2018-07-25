#ifndef GAME_MWWORLD_POISON_H
#define GAME_MWWORLD_POISON_H

#include <string>

#include "action.hpp"
#include "ptr.hpp"

namespace MWWorld
{
    class ActionPoison : public Action
    {
            std::string mId;

            virtual void executeImp (const Ptr& actor);

        public:

            ActionPoison (const Ptr& object, const std::string& id);
    };
}

#endif
