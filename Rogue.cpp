#include "Rogue.h"

Rogue::Rogue()
{
    //Player(name);
}
void Rogue::addCoins(int coinsToAdd)
{
    if(coinsToAdd> MIN_NATURAL)
    {
        coinsToAdd *= DOUBLE_COINS;
        this->m_coins += coinsToAdd;
    }
}

void Rogue::operator<<(std::ostream& os)
{
    printPlayerDetails( os, this->m_name, "Rogue", this->m_level, this->m_force, this->m_HP, this->m_coins);
}