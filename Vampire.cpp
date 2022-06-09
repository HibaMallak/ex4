#include "Vampire.h"

void Vampire::applyEncounter(Player& player) const
{
    if(player.getAttackStrength()>= this->m_force )
    {
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getPlayerName(), MONSTER_NAME);
    }
    else
    {
        player.damage(this->m_damage);
        player.lowerForce(this->m_forceToLose);
        printLossBattle(player.getPlayerName(), MONSTER_NAME);
    }
}

void Vampire::printInfo() const 
{
    printMonsterDetails(std::cout, this->m_force, this->m_damage, this->m_loot);
}