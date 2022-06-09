#include "Treasure.h"

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(this->m_coins);
    printTreasureMessage();
}