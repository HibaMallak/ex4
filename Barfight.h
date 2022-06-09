#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

static const bool IS_FIGHTER = false;
class Barfight : public Card
{
    public:
        void applyEncounter(Player& player) const override;

    private:
        int m_damage = 10;
};

#endif