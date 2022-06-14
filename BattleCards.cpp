#include "BattleCards.h"


BattleCards::BattleCards(std::string m_name) : Card(m_name)
{

}

void BattleCards:: applyEncounter(Player& player) const
 {

     if(player.getAttackStrength()>= this->m_force )
     {
         win(player);
     }
     else
     {
         loss(player);
     }

}
