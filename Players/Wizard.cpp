#include "Wizard.h"
#include "../utilities.h"

Wizard::Wizard(std::string name) : Player(name)
{

}

void Wizard::heal(int pointsToHeal)
{
    if(pointsToHeal > MIN_NATURAL)
    {
        pointsToHeal *= DOUBLE_HP;
        if(this->m_healthPoints + pointsToHeal > MAX_HP)
        {
            this->m_healthPoints = MAX_HP;
        }
        else
        {
            this->m_healthPoints += pointsToHeal;
        }
    }
}

std::ostream& Wizard::printPlayerInfo(std::ostream& os) const
{
    printPlayerDetails(os, this->m_name, "Wizard", this->m_level, this->m_force, this->m_healthPoints, 
        this->m_coins);
    return os;
}