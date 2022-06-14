#include "Fairy.h"
Fairy :: Fairy() : Card("Fairy")
{

}
void Fairy::applyEncounter(Player& player) const
{
    if(player.getPlayerType() != "Wizard")
    {
        player.heal(this->m_FairyHP);
        printFairyMessage(player.getPlayerType() == IS_WIZARD);
    }
    printFairyMessage(player.getPlayerType() != IS_WIZARD);
}