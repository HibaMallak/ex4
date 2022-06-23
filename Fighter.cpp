#include "Fighter.h"
#include "../utilities.h"

Fighter::Fighter(const std::string name) : Player(name)
{

}

int Fighter::getAttackStrength() const
{
    return ((DOUBLE_FORCE * this->m_force) + this->m_level);
}

std::ostream& Fighter::printPlayerInfo(std::ostream& os) const
{
    printPlayerDetails(os , this->m_name, "Fighter", this->m_level, this->m_force, this->m_healthPoints,
        this->m_coins);
    return os;
}