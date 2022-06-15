#include "Vampire.h"

Vampire::Vampire() : BattleCards("Vampire")
{

}


void Vampire:: win (Player& player) const
{
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getPlayerName(), "Vampire");
}

void Vampire:: loss (Player& player) const
{
    if (player.getPlayerCoins() - m_damage <= 0)
    {
        player.damage(player.getPlayerCoins());
    }
    else
    {
        player.damage(this->m_damage);
    }

    player.lowerForce(this->m_forceToLose);
    printLossBattle(player.getPlayerName(), "Vampire");

}

std::ostream& Vampire::printInfo(std::ostream& os)
{
    printCardDetails(os, "Vampire");
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, !IS_DRAGON);
    return os;
}
