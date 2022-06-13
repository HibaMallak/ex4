#include "Pitfall.h"


void Pitfall::applyEncounter(Player& player) const
{
    if(player.getPlayerType() != "Rouge")
    {
        player.damage(this->m_damage);
        printBarfightMessage(!IS_ROUGE);
    }
    printBarfightMessage(IS_ROUGE);
}