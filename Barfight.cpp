#include "Barfight.h"
#include "Fighter.h"

Barfight :: Barfight() : Card("Barfight")
{

}

void Barfight::applyEncounter(Player& player) const
{
    try
    {
        Fighter& check= dynamic_cast <Fighter&>(player);
    }
    catch (const std::bad_cast&)
    {
        player.damage(this->m_damage);
        printBarfightMessage(!IS_FIGHTER);
    }

    printBarfightMessage(IS_FIGHTER);
}

std::ostream& Barfight:: operator<<(std::ostream& os) const
{
    printCardDetails(os,"Barfight");
}