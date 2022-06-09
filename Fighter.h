#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"

static const int DOUBLE_FORCE = 2;

class Fighter : public Player
{
    public:
        int getAttackStrength() override;
        void printInfo() override;
};

#endif