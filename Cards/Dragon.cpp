#include "Dragon.h"

Dragon::Dragon() : BattleCards("Dragon")
{

}


void Dragon:: win (Player& player) const
{
    player.levelUp();
    player.addCoins(this->m_loot);
    printWinBattle(player.getPlayerName(), "Dragon");

} 

void Dragon:: loss (Player& player) const
{
    player.damage(100);
    printLossBattle(player.getPlayerName(),"Dragon");

    /*
    if (player.getPlayerCoins()-m_damage<=0)
    {
        player.damage(player.getPlayerCoins());
    }
    player.damage(this->m_damage);

*/

}

std::ostream& Dragon::printInfo(std::ostream& os) const
{
    printCardDetails(os,"Dragon");
    printMonsterDetails(os, this->m_force, DNE, this->m_loot, IS_DRAGON);
    printEndOfCardDetails(os);
    return os;
}