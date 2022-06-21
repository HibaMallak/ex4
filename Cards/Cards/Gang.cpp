#include "Gang.h"
#include <fstream>

Gang :: Gang() : Card("Gang")
{

}

Gang::Gang(const Gang& gang)
{
    for(std::deque<std::unique_ptr <BattleCards>>::const_iterator it = gang.m_GangCards.begin();
        it!=gang.m_GangCards.end(); ++it)
    {
        BattleCards* b = (*it).get();
        this->m_GangCards.push_back(std::unique_ptr<BattleCards>(b));

    }
}

Gang& Gang::operator=(Gang& gang)
{
    if(this->m_GangCards == gang.m_GangCards)
    {
        return *this;
    }
    while(!m_GangCards.empty())
    {
        m_GangCards.pop_front();

    }
    for(std::deque<std::unique_ptr <BattleCards>>::const_iterator it = gang.m_GangCards.begin();
        it!=gang.m_GangCards.end(); ++it)
    {
        BattleCards* b = (*it).get();
        this->m_GangCards.push_back(std::unique_ptr<BattleCards>(b));
    }
    return *this;
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

void Gang::buildGang(std::ifstream &file, std::string card, int &countLines)
{

    while(std::getline(file, card))
    {
        if(card == "EndGang")
        {
            return;
        }
        if ((is_Valid_card(card) != GANG_CARD )||
            (card == "Gang"))
        {
            throw DeckFileFormatError(countLines);
        }
        m_GangCards.push_back(std::move(addGangCard(card)));
        ++countLines;
    }

    throw DeckFileFormatError(countLines);
}
std::unique_ptr<BattleCards> Gang::addGangCard(std::string card_name)
{
    if (card_name == "Goblin")
    {
        return std::unique_ptr<BattleCards>(new Goblin());
    }
    if (card_name == "Vampire")
    {
        return std::unique_ptr<BattleCards>(new Vampire());
    }
    return std::unique_ptr<BattleCards>(new Dragon());


}

std::ostream& Gang::printInfo(std::ostream& os) const
{
    return os;
}