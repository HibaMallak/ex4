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

Gang& Gang::operator=(const Gang& gang)
{
    if(this == &gang)
    {
        return *this;
    }
    while(!m_GangCards.empty())
    {
        m_GangCards.pop_front();

    }
    for(std::deque<std::unique_ptr <BattleCards>>::const_iterator it = gang.m_GangCards.begin();
        it != gang.m_GangCards.end(); ++it)
    {
        BattleCards* b = (*it).get();
        this->m_GangCards.push_back(std::unique_ptr<BattleCards>(b));
    }
    return *this;
}


void Gang::applyEncounter(Player& player) const
{
    bool keepBattle = true;

    for(std::deque<std::unique_ptr <BattleCards>>::const_iterator it = m_GangCards.begin();
        it != m_GangCards.end(); ++it)
    {
        if (keepBattle)
        {
            if ((*it)->gang_Encounter(player, keepBattle))
            {
                continue;
            }

            keepBattle = false;
        }

        else
        {
            (*it)->gang_Encounter(player, keepBattle);
        }
    }

    if (keepBattle)
    {
        player.levelUp();
        printWinBattle(player.getPlayerName(), "Gang");
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
        if ((isValidCard(card) != GANG_CARD ) || (card == "Gang"))
        {
            throw DeckFileFormatError(countLines);
        }
        m_GangCards.push_back(std::move(addGangCard(card)));
        ++countLines;
    }

    throw DeckFileFormatError(countLines);
}

std::unique_ptr<BattleCards> Gang::addGangCard(std::string cardName)
{
    if (cardName == "Goblin")
    {
        return std::unique_ptr<BattleCards>(new Goblin());
    }
    if (cardName == "Vampire")
    {
        return std::unique_ptr<BattleCards>(new Vampire());
    }
    
    return std::unique_ptr<BattleCards>(new Dragon());
}

std::ostream& Gang::printInfo(std::ostream& os) const
{
    return os;
}