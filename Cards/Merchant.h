#ifndef MERCHANT_H
#define MERCHANT_H

#include "Card.h"

static const int LEAVE = 0;
static const int HEALTH_POTION = 1;
static const int FORCE_BOOST = 2;

class Merchant : public Card
{
    public:
    Merchant();
    ~Merchant() override = default;
    Merchant(Merchant& merchant) = default;
    Merchant& operator=(Merchant& merchant) = default;

    void applyEncounter(Player& player) const override;
    std::ostream& printInfo(std::ostream& os) const override;


    private:
        int m_coinsPerPotion = 5;
        int m_coinsPerBoost = 10;
        int m_toAdd = 1;
      
};

#endif