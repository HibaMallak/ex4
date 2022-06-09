#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card
{
    public:
        Treasure() = default;
        void applyEncounter(Player& player) const override;

    private:
        int m_coins = 10;
};

#endif