#include "Pitfall.h"
#include "Rogue.h"

Pitfall :: Pitfall() : Card("Pitfall")
{

}


void Pitfall::applyEncounter(Player& player) const
{
    try
    {
        Rogue& check= dynamic_cast <Rogue&>(player);
    }
    catch (const std::bad_cast&)
    {
        player.damage(this->m_damage);
        printBarfightMessage(!IS_ROUGE);
    }

    printBarfightMessage(IS_ROUGE);


}


std::ostream&  Pitfall:: operator<<(std::ostream& os) const
{
    printCardDetails(os,"Pitfall");
}