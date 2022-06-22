#include "BattleCards.h"


BattleCards::BattleCards(const std::string m_name) : Card(m_name)
{

}

void BattleCards:: applyEncounter(Player& player) const
 {
    if(this->m_cardName == DRAGON)
    {
        if(player.getAttackStrength() < MIN_TO_WIN_DRAGON)
        {
            loss(player);
        }
        else
        {
            win(player);
        }
    }
    if(this->m_cardName == GOBLIN)
    {
        if(player.getAttackStrength() < MIN_TO_WIN_GOBLIN)
        {
            loss(player);
        }
        else
        {
            win(player);
        }

    }
    if(this->m_cardName == VAMPIRE)
    {
        if(player.getAttackStrength() < MIN_TO_WIN_VAMPIRE )
        {
            loss(player);
        }
        else
        {
            win(player);
        }
    }
}
