#include "Wizard.h"

Wizard::Wizard()
{
    m_playerType="Wizard";
}

void Wizard::heal(int pointsToHeal)
{
    if(pointsToHeal> MIN_NATURAL)
    {
        pointsToHeal *= DOUBLE_HP;
        if(this->m_HP+ pointsToHeal > MAX_HP)
        {
            this->m_HP= MAX_HP;
        }
        else
        {
            this->m_HP += pointsToHeal;
        }
    }
}

void Wizard::operator<<(std::ostream& os)
{
    printPlayerDetails( std::cout, this->m_name, "Wizard", this->m_level, this->m_force, this->m_HP, this->m_coins);
}