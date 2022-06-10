#include "Pitfall.h"

Pitfall :: Pitfall() : m_cardName("Pitfall")
{

}
void Pitfall::applyEncounter(Player& player) const
{
    if(player.getPlayerType() != "Rouge")
    {
        player.damage(this->m_damage);
        printBarfightMessage(!IS_ROUGE);
    }
    printBarfightMessage(IS_ROUGE);
}