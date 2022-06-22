#include "Goblin.h"

Goblin ::Goblin() : BattleCards(GOBLIN)
{

}


void Goblin:: win (Player& player) const
{
    player.levelUp();
    player.addCoins(this->m_loot);
    printWinBattle(player.getPlayerName(), GOBLIN);
}

void Goblin:: loss (Player& player) const
{
    if (player.getPlayerHealthPoints() - m_damage <= MIN_NATURAL)
    {
        player.damage(player.getPlayerHealthPoints());

    }
    else
    {
        player.damage(this->m_damage);
    }
    printLossBattle(player.getPlayerName(), GOBLIN);

}

std::ostream&  Goblin:: printInfo(std::ostream& os) const
{
    printCardDetails(os, GOBLIN);
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, !IS_DRAGON);
    printEndOfCardDetails(os);
    return os;
}

bool Goblin:: gang_Encounter(Player& player, bool check) const
{
    if (!check)
    {
        loss(player);
        return false;
    }
    else if (player.getAttackStrength() < MIN_TO_WIN_GOBLIN )
    {
        loss(player);
        return false;
    }

    player.addCoins(this->m_loot);
    return true;

}
