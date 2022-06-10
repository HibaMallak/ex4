#include "Treasure.h"

Treasure :: Treasure() : m_cardName("Treasure")
{

}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(this->m_coins);
    printTreasureMessage();
}