#ifndef GOBLIN_H
#define GOBLIN_H

#include "Card.h"
#include "BattleCards.h"

class Goblin : public BattleCards
{
    public:
        Goblin();
        ~Goblin()=default;
        Goblin(Goblin& goblin)=default;
        Goblin& operator=(Goblin& goblin) =default;

        std::ostream& operator<<(std::ostream& os) const override;
        void win (Player& player) const override;
        void loss (Player& player) const override;

    private:
        int m_force = 6;
        int m_loot = 2;
        int m_damage = 10;


};

#endif