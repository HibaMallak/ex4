#include "Goblin.h"

Goblin ::Goblin() : m_cardName("Goblin")
{

}
void Goblin::applyEncounter(Player& player) const
{
    if(player.getAttackStrength() >= this->m_force)
    {
        player.levelUp();
        player.addCoins(this->m_loot);
    }
    else
    {
        if (player.getPlayerCoins()-m_damage<=0)
        {
            player.damage(player.getPlayerCoins());

        }
        player.damage(this->m_damage);
    }
}

void Goblin::printInfo() const
{
    printMonsterDetails( std::cout, this->m_force, this->m_damage, this->m_loot);
}