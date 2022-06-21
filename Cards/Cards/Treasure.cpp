#include "Treasure.h"

Treasure :: Treasure() : Card("Fairy")
{

}

void Treasure::applyEncounter(Player& player) const
{
    player.addCoins(this->m_coins);
    printTreasureMessage();
}


std::ostream&  Treasure:: printInfo(std::ostream& os) const
{
    printCardDetails(os, "Treasure");
    printEndOfCardDetails(os);
    return os;
}