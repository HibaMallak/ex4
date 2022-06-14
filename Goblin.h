#ifndef GOBLIN_H
#define GOBLIN_H

#include "Card.h"
#include "BattleCards.h"

class Goblin : public BattleCards
{
    public:
        Goblin();
        ~Goblin()=default;

        void printInfo() const override;
        void win (Player& player) const override;
        void loss (Player& player) const override;

    private:
        int m_force = 6;
        int m_loot = 2;
        int m_damage = 10;


};

#endif