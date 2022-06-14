#include "Dragon.h"



void Dragon:: win (Player& player) const
{
    player.levelUp();
    player.addCoins(this->m_loot);

}

void Dragon:: loss (Player& player) const
{
    if (player.getPlayerCoins()-m_damage<=0)
    {
        player.damage(player.getPlayerCoins());

    }
    player.damage(this->m_damage);


    //how getting out the player

}
Dragon::Dragon() : BattleCards("Dragon")
{

}


void Dragon::printInfo() const
{
    printMonsterDetails(std::cout, this->m_force, DNE, this->m_loot, true);////????????
}