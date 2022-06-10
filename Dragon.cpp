#include "Dragon.h"

Dragon::Dragon() : m_cardName("Dragon")
{

}
void Dragon::applyEncounter(Player& player) const
{
    if(player.getAttackStrength()>= this->m_force )
    {
        player.levelUp();
        player.addCoins(this->m_loot);
    }
    else
    {
        player.damage(PLAYER_MAX_HP);
        //how getting out the player
    }
}

void Dragon::printInfo() const
{
    printMonsterDetails(std::cout, this->m_force, DNE, this->m_loot, IS_DRAGON);
}