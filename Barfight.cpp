#include "Barfight.h"

Barfight :: Barfight() : Card("Barfight")
{

}

void Barfight::applyEncounter(Player& player) const
{
    if(player.getPlayerType() != "Fighter")
    {
        player.damage(this->m_damage);
        printBarfightMessage(!IS_FIGHTER);
    }
    printBarfightMessage(IS_FIGHTER);
}