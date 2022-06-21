#ifndef GOBLIN_H
#define GOBLIN_H

#include "Card.h"
#include "BattleCards.h"



class Goblin : public BattleCards
{
    static const int MIN_FOR_WIN = 6;

public:
        Goblin();
        ~Goblin() override = default;
        Goblin(Goblin& goblin) = default;
        Goblin& operator=(Goblin& goblin) = default;

        std::ostream& printInfo(std::ostream& os) const override;
        void win (Player& player) const override;
        void loss (Player& player) const override;

    bool gang_Encounter(Player& player, bool check) const override;

private:
        int m_force = 6;
        int m_loot = 2;
        int m_damage = 10;


};

#endif