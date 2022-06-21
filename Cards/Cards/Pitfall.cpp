#include "Pitfall.h"
#include "../Players/Rogue.h"

Pitfall :: Pitfall() : Card("Pitfall")
{

}


void Pitfall::applyEncounter(Player& player) const
{
    try
    {
       // Rogue& check= dynamic_cast <Rogue&>(player);
        dynamic_cast <Rogue&>(player);
    }
    catch (const std::bad_cast&)
    {
        player.damage(this->m_damage);
        printPitfallMessage(IS_ROUGE);
        return;
    }

    printPitfallMessage(!IS_ROUGE);


}


std::ostream& Pitfall::printInfo(std::ostream& os) const
{
    printCardDetails(os, "Pitfall");
    printEndOfCardDetails(os);
    return os;
}