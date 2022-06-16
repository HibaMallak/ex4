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
    player.damage(player.getPlayerHP());
    
    /*
    if (player.getPlayerCoins()-m_damage<=0)
    {
        player.damage(player.getPlayerCoins());
 
    }
    player.damage(this->m_damage);
    printLossBattle(player.getPlayerName(),"Dragon");
*/
    //how getting out the player

}

std::ostream& Dragon::printInfo(std::ostream& os) const
{
    printCardDetails(os,"Dragon");
    printMonsterDetails(os, this->m_force, DNE, this->m_loot, IS_DRAGON);
    return os;
}