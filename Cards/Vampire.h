#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "BattleCards.h"
#include "Card.h"



class Vampire : public BattleCards
{

public:

        /*
        * C'tor of Vampire class
        *
        * @return
        *      A new instance of Vampire.
        */
        Vampire();

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        ~Vampire() override = default;
        Vampire(const Vampire& vampire) = default;
        Vampire& operator=(const Vampire& vampire) = default;

        /*
        * Prints the vampire info:
        *
        * @param os - the ostream to print to
        * @return
        *      std::ostream&
        */
        std::ostream& printInfo(std::ostream& os) const override;

        /*
        * Applies changes on player when result of encountering vampire is win:
        *
        * @param player - The player.
        * @return
        *      void
        */
        void win (Player& player) const  override;

        /*
        * Applies changes on player when result of encountering vampire is loss:
        *
        * @param player - The player.
        * @return
        *      void
        */
        void loss (Player& player) const  override;

        /*
        * Handling the player's applyEncounter when vampire is part of a gang:
        *
        * @param player - The player.
        * @return
        *      void
        */
        bool gang_Encounter(Player& player, bool check) const override;

private:
      int m_force = 10;
      int m_loot = 2;
      int m_damage = 10;
      int m_forceToLose = 1;

};

#endif