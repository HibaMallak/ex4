#ifndef WIZARD_H
#define WIZARD_H

#include "Player.h"

static const int DOUBLE_HP = 2;

class Wizard : public Player
{
public:

        /*
        * C'tor of Wizard class
        *
        * @param name - The name of the wizard.
        * @return
        *      A new instance of Wizard.
        */
        Wizard(const std::string name);

        /*
        * D'tor of Wizard class
        *
        * @return
        *      Deletes this instance of Wizard.
        */
        ~Wizard() override = default;

        /*
        * Copy c'tor of Wizard class
        *
        * @param wizard - The wizard to copy construct from.
        * @return
        *      A copied instance of Wizard.
        */
        Wizard(Wizard& wizard) = default;

        /*
        * Assignment operator
        *
        * @param wizard - The wizard to assign from.
        * @return
        *      default
        */
        Wizard& operator=(Wizard& wizard) = default;

        /*
        * Increases the health points of the wizard by twice the given amount of points.
        *
        * @param printsToHeal - the amount of points to double and add to the health points of the player.
        * @return
        *      void
        */
        void heal(int pointsToHeal) override;

        /*
        * Prints the wizard info:
        *
        * @param os - the ostream to print to
        * @return
        *      std::ostream&
        */
        std::ostream& printPlayerInfo(std::ostream& os) const override;
};

#endif