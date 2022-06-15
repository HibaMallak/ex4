#include "Fairy.h"
#include "Wizard.h"

Fairy :: Fairy() : Card("Fairy")
{

}
void Fairy::applyEncounter(Player& player) const
{
    try
    {
        Wizard& check= dynamic_cast <Wizard&>(player);
    }
    catch (const std::bad_cast&)
    {
        printFairyMessage(!IS_WIZARD);
    }

    player.heal(this->m_FairyHP);
    printFairyMessage(IS_WIZARD);
}

std::ostream& Fairy::printInfo(std::ostream& os) const
{
    printCardDetails(os, "Fairy");
    return os;
}