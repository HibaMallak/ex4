#ifndef WIZARD_H
#define WIZARD_H

#include "Players/Player.h"

static const int DOUBLE_HP = 2;

class Wizard : public Player
    {
     public:

       Wizard(std::string name);
       ~Wizard() = default;
       Wizard(Wizard& wizard) = default;
       Wizard& operator=(Wizard& wizard) = default;

        void heal(int pointsToHeal) override;
        std::ostream& printPlayerInfo(std::ostream& os) const override;
    };

#endif