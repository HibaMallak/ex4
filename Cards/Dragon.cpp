#include "Dragon.h"

Dragon::Dragon() : BattleCards(DRAGON)
{

}


void Dragon:: win (Player& player) const
{
    player.levelUp();
    player.addCoins(this->m_loot);
    printWinBattle(player.getPlayerName(), DRAGON);

} 

void Dragon:: loss (Player& player) const
{
    player.damage(100);
    printLossBattle(player.getPlayerName(), DRAGON);

}

std::ostream& Dragon::printInfo(std::ostream& os) const
{
    printCardDetails(os, DRAGON);
    printMonsterDetails(os, this->m_force, DNE, this->m_loot, IS_DRAGON);
    printEndOfCardDetails(os);
    return os;
}

bool Dragon:: gang_Encounter(Player& player, bool check) const
{
    if (!check)
    {
        loss(player);
        return false;
    }
    else if (player.getAttackStrength() < MIN_TO_WIN_DRAGON )
    {
        loss(player);
        return false;
    }

    player.addCoins(this->m_loot);
    return true;
}