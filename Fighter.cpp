#include "Fighter.h"

Fighter::Fighter()
{
    m_playerType="Fighter";
}
int Fighter::getAttackStrength()
{
    return (DOUBLE_FORCE * this->m_force) + this->m_level;
}

void Fighter::printInfo()
{
    printPlayerDetails( std::cout , this->m_name, "Fighter", this->m_level, this->m_force, this->m_HP, this->m_coins);
}