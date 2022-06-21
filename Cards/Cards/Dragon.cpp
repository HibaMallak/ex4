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

bool Dragon:: gang_Encounter(Player& player, bool check) const
{
    if (check == false || (player.getAttackStrength() < MIN_FOR_WIN ))
    {
        loss(player);
        return false;
    }
    else if (player.getAttackStrength() < MIN_FOR_WIN )//new
    {
        loss(player);
        return false;
    }


    player.addCoins(this->m_loot);
    return true;

}