#ifndef ROUGE_H
#define ROUGE_H

#include "Player.h"

static const int DOUBLE_COINS = 2;

class Rogue : public Player
{
public:
        /*
        * C'tor of Rogue class
        *
        * @param name - The name of the rogue.
        * @return
        *      A new instance of Rogue.
        */
        Rogue(std::string name);
        
        /*
        * Copy c'tor of Rogue class
        *
        * @param rogue - The rogue to copy construct from.
        * @return
        *      A copied instance of Rogue.
        */
        Rogue(const Rogue& rogue) = default;

        /*
        * D'tor of Rogue class
        *
        * @return
        *      Deletes this instance of Rouge.
        */
        ~Rogue() override = default;

        /*
        * Assignment operator
        *
        * @param rogue - The rogue to assign from.
        * @return
        *      default
        */
        Rogue& operator=(const Rogue& rogue) = default;

        /*
        * Increases the coins of the rogue by given amount of coins.
        *
        * @param coinsToAdd - the amount of coins to add to the coins of the rogue.
        * @return
        *      void
        */
        void addCoins(int coinsToAdd) override;

        /*
        * Prints the rogue info:
        *
        * @param os - the ostream to print to
        * @return
        *      std::ostream&
        */
        std::ostream& printPlayerInfo(std::ostream& os) const override;
};

#endif
