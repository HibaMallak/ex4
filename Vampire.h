#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Card.h"

static const int PLAYER_MAX_HP = 100;
static const std::string MONSTER_NAME = "Vampire";

class Vampire : public Card
{
    public:
        Vampire() = default;
        void applyEncounter(Player& player) const override;
        void printInfo() const override; 

    private:
        int m_force = 10;
        int m_loot = 2;
        int m_damage = 10;
        int m_forceToLose = 1;

};

#endif