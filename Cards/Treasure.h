#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card
{
public:

        /*
        * C'tor of Treasure class
        *
        * @return
        *      A new instance of Treasure.
        */
        Treasure();

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        ~Treasure() override = default;
        Treasure(const Treasure& treasure) = default;
        Treasure& operator=(const Treasure& treasure) = default;

        /*
        * Handling the player's applyEncounter with the treasure:
        *
        * @param player - The player.
        * @return
        *      void
        */
        void applyEncounter(Player& player) const override;

        /*
        * Prints the merchant info:
        *
        * @param os - the ostream to print to
        * @return
        *      std::ostream&
        */
        std::ostream& printInfo(std::ostream& os) const override;

private:
        int m_coins = 10;

};

#endif