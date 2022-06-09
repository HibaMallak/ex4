#ifndef DRAGON_H
#define DRAGON_H

#include "Card.h"

static const int DNE = 0;
static const int PLAYER_MAX_HP = 100;
static const bool IS_DRAGON = true;
class Dragon : public Card
{
    public:
        void applyEncounter(Player& player) const override; 
        void printInfo() const override;

    private:
        int m_force = 25;
        int m_loot = 1000;

};

#endif