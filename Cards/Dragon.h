#ifndef DRAGON_H
#define DRAGON_H
#include "BattleCards.h"

static const int DNE = 0;

class Dragon : public BattleCards
{

public:

        /*
        * C'tor of Dragon class
        *
        * @return
        *      A new instance of Dragon.
        */
        Dragon();

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        ~Dragon() override = default;
        Dragon(const Dragon& dragon) = default;
        Dragon& operator=(const Dragon& dragon) = default;

        /*
        * Prints the dragon info:
        *
        * @param os - the ostream to print to
        * @return
        *      std::ostream&
        */
        std::ostream& printInfo(std::ostream& os) const override;

        /*
        * Applies changes on player when result of encountering dragon is win:
        *
        * @param player - The player.
        * @return
        *      void
        */
        void win (Player& player) const  override;

        /*
        * Applies changes on player when result of encountering dragon is loss:
        *
        * @param player - The player.
        * @return
        *      void
        */
        void loss (Player& player) const override;

        /*
        * Handling the player's applyEncounter when dragon is part of a gang:
        *
        * @param player - The player.
        * @return
        *      void
        */
        bool gang_Encounter(Player& player, bool check) const override;

private:
        int m_force = 25;
        int m_loot = 1000;

};

#endif