#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

static const int LEAVE = 0;
static const int HEALTH_POTION = 1;
static const int FORCE_BOOST = 2;

class Merchant : public Card
{
public:

        /*
        * C'tor of Merchant class
        *
        * @return
        *      A new instance of Merchant.
        */
        Merchant();

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        ~Merchant() override = default;
        Merchant(const Merchant& merchant) = default;
        Merchant& operator=(const Merchant& merchant) = default;

        /*
        * Handling the player's applyEncounter with the merchant:
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

        int m_coinsPerPotion = 5;
        int m_coinsPerBoost = 10;
        int m_toAdd = 1;

        /*
        * recieve the choice of player 
        *
        * @return
        *       the player's choice
        */
        int getAndCheckChoice() const;
      
};

#endif