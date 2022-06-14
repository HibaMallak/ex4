#include "Goblin.h"

Goblin ::Goblin() : BattleCards("Goblin")
{

}



void Goblin:: win (Player& player) const
{
    player.levelUp();
    player.addCoins(this->m_loot);

}

void Goblin:: loss (Player& player) const
{
    if (player.getPlayerCoins()-m_damage<=0)
    {
        player.damage(player.getPlayerCoins());

    }
    player.damage(this->m_damage);

}

void Goblin::printInfo() const
{
    printMonsterDetails( std::cout, this->m_force, this->m_damage, this->m_loot);
}