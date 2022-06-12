#include "Mtmchkin.h"

Mtmchkin:: Mtmchkin(const std::string fileName) : m_roundsPlayed(NO_ROUNDS_PLAYED)
{
    int teamSize;
    std::string cardName;
    std::ifstream file = fileName;
    getline(fileName, cardName);
    m_deckCards.pushBack(cardName);///??????

    printStartGameMessage();

    do {
        printEnterTeamSizeMessage();
        std::cin >> teamSize;

        if (teamSize < MIN_TEAM_SIZE || teamSize > MAX_TEAM_SIZE)
        {
            printInvalidTeamSize();
        }
    } while (teamSize < MIN_TEAM_SIZE || teamSize > MAX_TEAM_SIZE);

    std::string playerAndJob;
    for( int i = 0; i < teamSize; ++i)
    {
        do {
            printInsertPlayerMessage();
            std::cin >> playerAndJob;
            std::cin >> std::at(playerName.length()+1);
            } while (check);
        
            //this->m_playerQueue.pushBack(playerName);
    }
    m_defeatedPlayers = new Queue<Player>();
    m_winners = new Queue<Player>();





}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundsPlayed +1);
    for(int i = 0; i < m_playerQueue.size(); ++i)
    {
        Player currentPlayer = m_playerQueue.front();
        Card currentCard = m_deckCards.front();

        printTurnStartMessage(currentPlayer.getPlayerName());
        currentCard.applyEncounter(currentPlayer);

        m_deckCards.popFront();
        m_deckCards.pushBack(currentCard);
        m_playerQueue.popFront();
        if(currentPlayer.isKnockedOut())
        {
            m_defeatedPlayers.pushBack(currentPlayer);
        }
        else if(currentPlayer.getLevel() == MAX_LEVEL)
        {
            m_winners.pushBack(currentPlayer);
        }
        else 
        {
            m_playerQueue.pushBack(currentPlayer);
        }
        if(isGameOver())
        {
            printGameEndMessage();
        }
    }

    ++m_roundsPlayed;
}

void Mtmchkin::printLeaderBoardHelper(const Queue<Player> players, int ranking, bool reverse) const
{
    Queue<Player> current = players;
    if(reverse)
    {
        Player reversedQueue [players.size()];
        for(int i = 0; i < players.size(); ++i)
        {
            reversedQueue[i] = current.front();
            current.popFront();
        }
        for(int i = players.size()-1; i >= 0 ; ++i)
        {
            current.pushBack(reversedQueue[i]);
        }
    }

    for(int i = 0; i < players.size(); ++i)
    {
        printPlayerLeaderBoard(ranking +i, current.front());
        current.popFront();
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