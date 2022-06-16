#include <fstream>
#include "Mtmchkin.h"

using std::queue;

Mtmchkin::Mtmchkin(const std::string fileName) : m_roundsPlayed(NO_ROUNDS_PLAYED)
{

    printStartGameMessage();

    std::ifstream file(fileName);
    if (!file)
    {
        throw Exception::DeckFileNotFound();
    }
    std::string cardName;
    int countLines = 1;
    while (std::getline(file, cardName))
    {
        if (!is_Valid_card(cardName))
        {
            throw Exception::DeckFileFormatError(countLines);
        }
        m_deckCards.push(convet_stringToCard(cardName));
        ++countLines;
    }
    if (m_deckCards.size() < MIN_CARD_SIZE)
    {
        throw Exception::DeckFileInvalidSize();
    }

    printEnterTeamSizeMessage();

    std::string teamSize;
    bool inputValid = true;
    while (inputValid)
    {
        try
        {
            if (!std::getline(std::cin, teamSize) || std::stoi(teamSize) < MIN_TEAM_SIZE || std::stoi(teamSize) > MAX_TEAM_SIZE)
            {
                throw Exception::DeckFileInvalidSize();
            }
            inputValid = false;
        }
        catch (...)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
    }

    std::string playerAndJob = " ";
    for (int i = 0; i < std::stoi(teamSize); ++i)
    {
        printInsertPlayerMessage();
        do
        {
            std::getline(std::cin, playerAndJob);
        } while (!is_Valid_Player_Class(playerAndJob));

        m_playerQueue.push_back(convet_stringToPlayer(playerAndJob));
    }
}

bool Mtmchkin::is_Valid_card(const std::string cardName)
{
    if (cardName != "Goblin" && cardName != "Vampire" && cardName != "Dragon" && cardName != "Merchant" &&
        cardName != "Treasure" && cardName != "Pitfall" && cardName != "Barfight" && cardName != "Fairy")
    {
        return false;
    }
    return true;
}

bool Mtmchkin::is_Valid_Player_Class(const std::string player_name)
{
    int pos = player_name.find(" ");
    std::string sub = player_name.substr(0, pos);

    if (Player::is_Valid_name(sub))
    {
        printInvalidName();
        return false;
    }

    sub = player_name.substr(pos + 1);

    if (sub != "Fighter" && sub != "Wizard" && sub != "Rogue")
    {
        printInvalidClass();
        return false;
    }

    return true;
}

std::unique_ptr<Player> Mtmchkin::convet_stringToPlayer(const std::string player_job)
{
    int pos = player_job.find(" ");
    std::string name = player_job.substr(0, pos);
    std::string job = player_job.substr(pos + 1);

    if (job == "Fighter")
    {
        return std::unique_ptr<Player>(new Fighter(name));
    }

    if (job == "Wizard")
    {
        return std::unique_ptr<Player>(new Wizard(name));
    }

    if (job == "Rogue")
    {
        return std::unique_ptr<Player>(new Rogue(name));
    }
}

std::unique_ptr<Card> Mtmchkin::convet_stringToCard(const std::string card_name)
{

    if (card_name == "Goblin")
    {
        return std::unique_ptr<Card>(new Goblin());
    }
    if (card_name == "Vampire")
    {
        return std::unique_ptr<Card>(new Vampire());
    }
    if (card_name == "Dragon")
    {
        return std::unique_ptr<Card>(new Dragon());
    }

    if (card_name == "Merchant")
    {
        return std::unique_ptr<Card>(new Merchant());
    }
    if (card_name == "Treasure")
    {
        return std::unique_ptr<Card>(new Treasure());
    }
    if (card_name == "Pitfall")
    {
        return std::unique_ptr<Card>(new Pitfall());
    }
    if (card_name == "Barfight")
    {
        return std::unique_ptr<Card>(new Barfight());
    }
    if (card_name == "Fairy")
    {
        return std::unique_ptr<Card>(new Fairy());
    }
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_roundsPlayed + 1);
    int teamSizeOnThisRound = m_playerQueue.size();
    for (int i = 0; i < teamSizeOnThisRound; ++i)
    {

        std::unique_ptr<Player> currentPlayer = std::move(m_playerQueue.front());
        std::unique_ptr<Card> currentCard = std::move(m_deckCards.front());

        printTurnStartMessage(currentPlayer->getPlayerName());
        currentCard->applyEncounter(*currentPlayer);

        m_deckCards.pop();
        m_deckCards.push(currentCard);
        m_playerQueue.pop_front();
        if (currentPlayer->isKnockedOut())
        {
            m_defeatedPlayers.push_front(currentPlayer);
        }
        else if (currentPlayer->getLevel() == MAX_LEVEL)
        {
            m_winners.push_back(currentPlayer);
        }
        else
        {
            m_playerQueue.push_back(currentPlayer);
        }
        if (isGameOver())
        {
            printGameEndMessage();
        }
    }

    ++m_roundsPlayed;
}

void Mtmchkin::printLeaderBoardHelper( std::deque<std::unique_ptr <Player>> players, int ranking) const
{
    std::deque<std::unique_ptr<Player>> current = std::move(players);
    for (int i = 0; !players.empty(); ++i)
    {
        printPlayerLeaderBoard(ranking + i, *(current.front()));
        current.pop_front();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking = FIRST_RANK;
    printLeaderBoardHelper(m_winners, ranking);
    printLeaderBoardHelper(m_playerQueue, ranking + m_winners.size());
    printLeaderBoardHelper(m_defeatedPlayers, ranking + m_winners.size() + m_playerQueue.size());
}

bool Mtmchkin::isGameOver() const
{
    if (m_playerQueue.empty())
    {
        return GAME_OVER;
    }
    return !GAME_OVER;
}

int Mtmchkin::getNumberOfRounds() const
{
    return this->m_roundsPlayed;
}