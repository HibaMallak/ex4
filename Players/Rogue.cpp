#include "Rogue.h"
#include "../utilities.h"

Rogue::Rogue(std::string name) : Player(name)
{

}
void Rogue::addCoins(int coinsToAdd)
{
    if(coinsToAdd > MIN_NATURAL)
    {
        coinsToAdd *= DOUBLE_COINS;
        this->m_coins += coinsToAdd;
    }
}

std::ostream& Rogue::printPlayerInfo(std::ostream& os) const
{
    printPlayerDetails(os, this->m_name, "Rogue", this->m_level, this->m_force, this->m_healthPoints, 
        this->m_coins);
    return os;
}
