#include "Fighter.h"
#include "utilities.h"

Fighter::Fighter(std::string name) : Player(name)
{

}

int Fighter::getAttackStrength()
{
    return (DOUBLE_FORCE * this->m_force) + this->m_level;
}

std::ostream& Fighter::operator<<(std::ostream& os)
{
    printPlayerDetails( os , this->m_name, "Fighter", this->m_level, this->m_force, this->m_HP, this->m_coins);
}