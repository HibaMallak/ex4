#include "Rouge.h"

void Rouge::addCoins(int coinsToAdd) 
{
    if(coinsToAdd> MIN_NATURAL)
    {
        coinsToAdd *= DOUBLE_COINS;
        this->m_coins += coinsToAdd;
    }
}

void Rouge::printInfo()
{
    printPlayerDetails( std::cout, this->m_name, "Rouge", this->m_level, this->m_force, this->m_HP, this->m_coins);
}