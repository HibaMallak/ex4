#include "Fairy.h"

void Fairy::applyEncounter(Player& player) const
{
    if(player.getPlayerType() == IS_WIZARD)
    {
        player.heal(this->m_FairyHP);
        printFairyMessage(player.getPlayerType() == IS_WIZARD);
    }
    printFairyMessage(player.getPlayerType() != IS_WIZARD);
}