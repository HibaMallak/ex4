#ifndef GOBLIN_H
#define GOBLIN_H

#include "Card.h"

static const std::string MONSTER_NAME = "Goblin";
class Goblin : public Card
{
    public:
        Goblin();
        void applyEncounter(Player& player) const override; 
        void printInfo() const override;

    private:
        int m_force = 6;
        int m_loot = 2;
        int m_damage = 10;

};

#endif