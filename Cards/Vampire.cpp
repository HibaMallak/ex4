#include "Vampire.h"

Vampire::Vampire() : BattleCards(VAMPIRE)
{

}

void Vampire:: win (Player& player) const
{
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getPlayerName(), VAMPIRE);
}

void Vampire:: loss (Player& player) const
{
    if (player.getPlayerHealthPoints() - m_damage <= MIN_NATURAL)
    {
        player.damage(player.getPlayerHealthPoints());
    }
    else
    {
        player.damage(this->m_damage);
    }

    player.lowerForce(this->m_forceToLose);
    printLossBattle(player.getPlayerName(), VAMPIRE);

}

std::ostream& Vampire::printInfo(std::ostream& os) const
{
    printCardDetails(os, VAMPIRE);
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, !IS_DRAGON);
    printEndOfCardDetails(os);
    return os;
}

bool Vampire:: gang_Encounter(Player& player, bool check) const
{
    if (!check)
    {
        loss(player);
        return false;
    }
    else if (player.getAttackStrength() < MIN_TO_WIN_VAMPIRE)
    {
        loss(player);
        return false;
    }

    player.addCoins(this->m_loot);
    return true;
}
