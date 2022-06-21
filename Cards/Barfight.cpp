#include "Barfight.h"
#include "../Players/Fighter.h"

Barfight :: Barfight() : Card("Barfight")
{

}

void Barfight::applyEncounter(Player& player) const
{
    try
    {
        //Fighter& check = dynamic_cast <Fighter&>(player);
        dynamic_cast <Fighter&>(player);
    }
    catch (const std::bad_cast&)
    {
        player.damage(this->m_damage);
        printBarfightMessage(IS_FIGHTER);
        return;
    }

    printBarfightMessage(!IS_FIGHTER);
}

std::ostream& Barfight::printInfo(std::ostream& os) const
{
    printCardDetails(os, "Barfight");
    printEndOfCardDetails(os);
    return os;
}