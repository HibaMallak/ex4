#include "Gang.h"


Gang :: Gang() : Card("Gang")
{

}

Gang::Gang(const Gang& gang)
{
    for(std::deque<std::unique_ptr <BattleCards>>::const_iterator it = gang.getGangCards().begin();
        it!=gang.getGangCards().end(); ++it)
    {
        m_GangCards.push_back(std::move(*it));
    }
}

Gang& Gang::operator=(Gang& gang)
{
    if(this->getGangCards() == gang.getGangCards())
    {
        return *this;
    }
    while(!m_GangCards.empty())
    {
        m_GangCards.pop_front();

    }
    for(std::deque<std::unique_ptr <BattleCards>>::const_iterator it = gang.getGangCards().begin();
        it!=gang.getGangCards().end(); ++it)
    {
        m_GangCards.push_back(std::move(*it));
    }
    return *this;
}

std::deque<std::unique_ptr <BattleCards>> Gang::getGangCards() const
{
    return m_GangCards;
}

void Gang::applyEncounter(Player& player) const
{
    bool KEEP_BATTLE = true;

    for(std::deque<std::unique_ptr <BattleCards>>::const_iterator it= m_GangCards.begin(); it!=m_GangCards.end(); ++it)
    {
        if (KEEP_BATTLE)
        {
            if ((*it)->gang_Encounter(player,KEEP_BATTLE))
            {
                continue;
            }

            KEEP_BATTLE= false;
        }

        else
        {
            (*it)->gang_Encounter(player,KEEP_BATTLE);
        }
    }

    if (KEEP_BATTLE== true)
    {
        player.levelUp();
        printWinBattle(player.getPlayerName(),"Gang");
    }
}

void Gang::addGangCard(std::string card_name)
{
    if (card_name == "Goblin")
    {
        m_GangCards.push_back(std::unique_ptr<BattleCards>(new Goblin()));
    }
    if (card_name == "Vampire")
    {
        m_GangCards.push_back(std::unique_ptr<BattleCards>(new Vampire()));
    }
    if (card_name == "Dragon")
    {
        m_GangCards.push_back(std::unique_ptr<BattleCards>(new Dragon()));
    }
}