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

std::ostream& Vampire::printInfo(std::ostream& os) const
{
    printCardDetails(os, "Vampire");
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, !IS_DRAGON);
    printEndOfCardDetails(os);
    return os;
}

bool Vampire:: gang_Encounter(Player& player, bool check) const
{
    if (!check || (player.getAttackStrength() < MIN_FOR_WIN ))
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
