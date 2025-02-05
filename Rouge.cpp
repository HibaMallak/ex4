#include "Rouge.h"

Rouge::Rouge(const std::string name)
{
    //Player(name);
}
void Rouge::addCoins(int coinsToAdd) 
{
    if(coinsToAdd> MIN_NATURAL)
    {
        coinsToAdd *= DOUBLE_COINS;
        this->m_coins += coinsToAdd;
    }
}

void Rouge::operator<<(std::ostream& os)
{
    printPlayerDetails( os, this->m_name, "Rouge", this->m_level, this->m_force, this->m_HP, this->m_coins);
}