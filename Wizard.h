#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"

static const int DOUBLE_HP = 2;

class Wizard : public Player
{
    public:
        Wizard() = default;
        void heal(int pointsToHeal) override;
        void printInfo() override;
};

#endif