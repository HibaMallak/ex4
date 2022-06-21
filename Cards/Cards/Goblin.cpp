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
    if (player.getPlayerHP() - m_damage <= 0)
    {
        player.damage(player.getPlayerHP());

    }
    else
    {
        player.damage(this->m_damage);
    }
    printLossBattle(player.getPlayerName(), "Goblin");

}

std::ostream&  Goblin:: printInfo(std::ostream& os) const
{
    printCardDetails(os, "Goblin");
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, !IS_DRAGON);
    printEndOfCardDetails(os);
    return os;
}

bool Goblin:: gang_Encounter(Player& player, bool check) const
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
