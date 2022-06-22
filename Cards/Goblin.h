#ifndef GOBLIN_H
#define GOBLIN_H

#include "Card.h"
#include "BattleCards.h"



class Goblin : public BattleCards
{


public:

        /*
        * C'tor of Goblin class
        *
        * @return
        *      A new instance of Goblin.
        */
        Goblin();

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        ~Goblin() override = default;
        Goblin(const Goblin& goblin) = default;
        Goblin& operator=(const Goblin& goblin) = default;

        /*
        * Prints the goblin info:
        *
        * @param os - the ostream to print to
        * @return
        *      std::ostream&
        */
        std::ostream& printInfo(std::ostream& os) const override;

        /*
        * Applies changes on player when result of encountering goblin win:
        *
        * @param player - The player.
        * @return
        *      void
        */
        void win (Player& player) const override;

        /*
        * Applies changes on player when result of encountering goblin is loss:
        *
        * @param player - The player.
        * @return
        *      void
        */
        void loss (Player& player) const override;

        /*
        * Handling the player's applyEncounter when goblin is part of a gang:
        *
        * @param player - The player.
        * @return
        *      void
        */
        bool gang_Encounter(Player& player, bool check) const override;

private:
        int m_force = 6;
        int m_loot = 2;
        int m_damage = 10;


};

#endif