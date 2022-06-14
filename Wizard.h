#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"

static const int DOUBLE_HP = 2;

class Wizard : public Player
    {
     public:

       Wizard(std::string name);
       Wizard(Wizard& wizard)=default;;
       ~Wizard() = default;
       Wizard& operator=(Wizard& wizard) =default;

        void heal(int pointsToHeal) override;
        void operator<<(std::ostream& os) override;
    };

#endif