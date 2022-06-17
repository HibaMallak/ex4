#include "Goblin.h"

Goblin ::Goblin() : BattleCards("Goblin")
{

}


void Goblin:: win (Player& player) const
{
    player.levelUp();
    player.addCoins(this->m_loot);
    printWinBattle(player.getPlayerName(), "Goblin");
}

void Goblin:: loss (Player& player) const
{
    if (player.getPlayerCoins() - m_damage <= 0)
    {
        player.damage(player.getPlayerCoins());

    }
    player.damage(this->m_damage);
    printLossBattle(player.getPlayerName(), "Goblin");

}

std::ostream&  Goblin:: printInfo(std::ostream& os) const
{
    printCardDetails(os, "Goblin");
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, !IS_DRAGON);
    printEndOfCardDetails(os);
    return os;
}

