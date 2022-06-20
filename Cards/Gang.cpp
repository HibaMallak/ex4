#include "Gang.h"


Gang :: Gang() : Card("Gang")
{

}


void Gang::applyEncounter(Player& player) const
{
    bool KEEP_BATTLE = true;

    for(std::deque<std::unique_ptr <BattleCards>>::const_iterator it= m_GangCards.begin(); it!=m_GangCards.end(); ++it)
    {
        if ( KEEP_BATTLE && (*it)->gang_Encounter(player,KEEP_BATTLE))
        {
            continue;
        }

        KEEP_BATTLE= false;
        (*it)->gang_Encounter(player,KEEP_BATTLE);
    }

    if (KEEP_BATTLE== true)
    {
        player.levelUp();
        printWinBattle(player.getPlayerName(),"Gang");
    }
}


