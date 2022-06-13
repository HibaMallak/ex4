#include <fstream>
#include "Mtmchkin.h"


using std::queue;


Mtmchkin:: Mtmchkin(const std::string fileName) : m_roundsPlayed(NO_ROUNDS_PLAYED)
{
   // int teamSize;
    std::string cardName, teamSize;
    std::ifstream file(fileName);

    while (std::getline (file, cardName))
    {
        m_deckCards.push(convet_stringToCard(cardName));
    }

    if (m_deckCards.size()< MIN_CARD_SIZE)
    {
        //THROW  DECKFILEINVALIDSIZE
    }


    printStartGameMessage();
    printEnterTeamSizeMessage();
    bool inputValid= true;

    while (inputValid)
    {
        try {
            if (!std::getline(std::cin, teamSize) || std::stoi(teamSize) < 2 || std::stoi(teamSize) > 6)
            {
                throw;
            }
            inputValid = false;
        }
         catch (...)
         {
             printInvalidTeamSize();
             printEnterTeamSizeMessage();
         }
    }


    std::string playerAndJob=" ";
    printInsertPlayerMessage();


    for( int i = 0; i < std::stoi(teamSize); ++i)
    {
        printInsertPlayerMessage();

        while (!is_Valid_Player_Class(playerAndJob))
        {
            if (!std::getline(std::cin, playerAndJob) )
            {
                throw; //??????
            }
        }

        m_playerQueue.push(convet_stringToPlayer(playerAndJob));
    }


}
bool Mtmchkin:: is_Valid_Player_Class (const std::string player_name)
{
    int pos = player_name.find(" ");

    std::string sub = player_name.substr(0,pos);


    if (Player:: is_Valid_name(sub))
    {
        printInvalidName();
        throw ;//????
    }

    sub = player_name.substr(pos+1);

    if (sub != "Fighter" && sub != "Wizard" && sub != "Rogue")
    {
        printInvalidClass();
        throw ;//????
    }

    return true;

}

std::unique_ptr<Player> Mtmchkin:: convet_stringToPlayer (const std::string player_job)
{
    int pos = player_job.find(" ");

    std::string sub = player_job.substr(pos+1);

    if (sub == "Fighter")
    {
        return std::unique_ptr<Player> (new Fighter());
    }
    if ( sub == "Wizard")
    {
        return std::unique_ptr<Player> (new Wizard());
    }

    if (sub == "Rogue")
    {
        return std::unique_ptr<Player> (new Rogue());
    }
}

std::unique_ptr<Card> Mtmchkin:: convet_stringToCard (const std::string card_name)
{

    if (card_name == "Goblin")
    {
        return std::unique_ptr<Card>(new Goblin()); /// like this?????
    }
    if (card_name == "Vampire")
    {
        return std::unique_ptr<Card> (new Vampire());
    }

    if (card_name == "Dragon")
    {
        return std::unique_ptr<Card> (new Dragon());
    }

    if (card_name == "Merchant")
    {
        return  std::unique_ptr<Card> (new Merchant());
    }
    if (card_name == "Treasure")
    {
        return std::unique_ptr<Card> (new Treasure());
    }
    if (card_name == "Pitfall")
    {
        return std::unique_ptr<Card> (new Pitfall());
    }
    if (card_name == "Barfight")
    {
        return std::unique_ptr<Card> (new Barfight());
    }
    if (card_name == "Fairy")
    {
        return  std::unique_ptr<Card> (new Fairy());
    }
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundsPlayed +1);
    for(int i = 0; i < m_playerQueue.size(); ++i)
    {

        std::unique_ptr<Player> currentPlayer = m_playerQueue.front();/// ptr dont work???
        std::unique_ptr<Card> currentCard = m_deckCards.front();

        printTurnStartMessage(currentPlayer->getPlayerName());
        currentCard->applyEncounter(currentPlayer);

        m_deckCards.pop();
        m_deckCards.push(currentCard);
        m_playerQueue.pop();
        if(currentPlayer->isKnockedOut())
        {
            m_defeatedPlayers.push(currentPlayer);
        }
        else if(currentPlayer->getLevel() == MAX_LEVEL)
        {
            m_winners.push(currentPlayer);
        }
        else
        {
            m_playerQueue.push(currentPlayer);
        }
        if(isGameOver())
        {
            printGameEndMessage();
        }
    }

    ++m_roundsPlayed;
}

void Mtmchkin::printLeaderBoardHelper(const queue<Player*> players, int ranking, bool reverse) const
{
    queue<Player*> current = players;
    if(reverse)
    {
        Player* reversedQueue [players.size()];
        for(int i = 0; i < players.size(); ++i)
        {
            reversedQueue[i] = current.front();
            current.pop();
        }
        for(int i = players.size()-1; i >= 0 ; ++i)
        {
            current.push(reversedQueue[i]);
        }
    }

    for(int i = 0; i < players.size(); ++i)
    {
        printPlayerLeaderBoard(ranking +i, current.front());
        current.pop();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking = FIRST_RANK;

    printLeaderBoardHelper( m_winners, ranking, !REVERSE);
    printLeaderBoardHelper( m_playerQueue, ranking + m_winners.size(), !REVERSE);
    printLeaderBoardHelper( m_defeatedPlayers, ranking + m_winners.size() + m_playerQueue.size(), REVERSE);

}

bool Mtmchkin::isGameOver() const
{
    if(m_playerQueue.size() > 0)
    {
        return !GAME_OVER;
    }
    return GAME_OVER;
}

int Mtmchkin::getNumberOfRounds() const
{
    return this->m_roundsPlayed;

}