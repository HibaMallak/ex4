#include "BattleCards.h"


BattleCards::BattleCards(std::string m_name) : Card(m_name)
{

}

void BattleCards:: applyEncounter(Player& player) const
 {
    if(this->m_cardName == "Dragon")
    {
        if(player.getAttackStrength()< 25)
        {
            loss(player);
        }
        else{
            win(player);
        }
    }
    if(this->m_cardName == "Goblin")
    {
        if(player.getAttackStrength() < 6)
    {
        loss(player);
    }
    else
    {
        win(player);
    }

    }
    if(this->m_cardName == "Vampire")
    {
        if(player.getAttackStrength() < 10 )
    {
        loss(player);
    }
    else
    {
        win(player);
    }
    }
    /*
    if(player.getAttackStrength() < this->m_force )
    {
        loss(player);
    }
    else
    {
        win(player);
    }*/

}
