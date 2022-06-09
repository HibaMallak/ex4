#include "Dragon.h"

void Dragon::applyEncounter(Player& player) const
{
    if(player.getAttackStrength()>= this->m_force )
    {
        player.levelUp();
        player.addCoins(this->m_loot);
    }
    else
    {
        player.damage(PLAYER_MAX_HP);
    }
}

void Dragon::printInfo() const
{
    printMonsterDetails(std::cout, this->m_force, DNE, this->m_loot, IS_DRAGON);
}