#ifndef FIGHTER_H
#define FIGHTER_H

#include "Players/Player.h"

static const int DOUBLE_FORCE = 2;

class Fighter : public Player
     {
     public:
        Fighter(std::string name);
        ~Fighter() = default;
        Fighter& operator=(Fighter& fighter) = default;
        Fighter(Fighter& fighter) = default;

        int getAttackStrength() override;
        std::ostream& printPlayerInfo(std::ostream& os) const override;

     };

#endif