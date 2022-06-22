#include <fstream>
#include "Mtmchkin.h"

using std::queue;

Mtmchkin::Mtmchkin(const std::string fileName) : m_roundsPlayed(NO_ROUNDS_PLAYED)
{
    printStartGameMessage();
    
    fillCardsDeck(fileName);
    if (m_deckCards.size() < MIN_CARD_SIZE)
    {
        throw DeckFileInvalidSize();
    }

    std::string teamSize = getAndCheckTeamSize();
    std::string playerAndJob = " ";
    for (int i = 0; i < std::stoi(teamSize); ++i)
    {
        printInsertPlayerMessage();
        do
        {
            std::getline(std::cin, playerAndJob);
        } while (!isValidPlayerClass(playerAndJob));

        m_playerQueue.push_back(std::move(convertStringToPlayer(playerAndJob)));
    }
}

void Mtmchkin::fillCardsDeck(const std::string fileName)
{
    std::ifstream file(fileName, std::fstream::in);
    if (!file)
    {
        throw DeckFileNotFound();
    }
    std::string cardName;
    int countLines = 1;
    while (std::getline(file, cardName))
    {
        if ((Card::is_Valid_card(cardName) == CARD_INVALID ))
        {
            throw DeckFileFormatError(countLines);
        }
        if(cardName == "Gang")
        {
            m_deckCards.push(std::move(std::unique_ptr<Card>(new Gang())));
            m_deckCards.back()->buildGang(file, cardName, countLines);
            ++countLines;
            continue;

        }
        else
        {
            m_deckCards.push(std::move(convertStringToCard(cardName)));
        }
        ++countLines;
    }
}

std::string Mtmchkin::getAndCheckTeamSize() const 
{
    printEnterTeamSizeMessage();
    std::string teamSize;
    bool inputInValid = true;
    while (inputInValid)
    {
        try
        {
            if (!std::getline(std::cin, teamSize) || std::stoi(teamSize) < MIN_TEAM_SIZE
                || std::stoi(teamSize) > MAX_TEAM_SIZE)
            {
                throw DeckFileInvalidSize();
            }
            inputInValid = false;
        }
        catch (...)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
    }
    return teamSize;
}

bool Mtmchkin:: isValidName (const std::string name) const
{
    if(name.length() > MAX_NAME_LENGTH || name.length() <= MIN_NATURAL)
    {
        return false;
    }
    for(const char &c :name)
    { 
        if(!isalpha(c))
        {
            return false;
        }
    }
    return true;
}

bool Mtmchkin::isValidPlayerClass(const std::string nameAndClass) const
{
    int pos = nameAndClass.find(" ");
    std::string sub = nameAndClass.substr(0, pos);

    if (!isValidName(sub))
    {
        printInvalidName();
        return false;
    }

    sub = nameAndClass.substr(pos + 1);

    if (sub != "Fighter" && sub != "Wizard" && sub != "Rogue")
    {
        printInvalidClass();
        return false;
    }

    return true;
}

std::unique_ptr<Player> Mtmchkin::convertStringToPlayer(const std::string playerJob) const
{
    int pos = playerJob.find(" ");
    std::string name = playerJob.substr(0, pos);
    std::string job = playerJob.substr(pos + 1);

    if (job == "Fighter")
    {
        return std::unique_ptr<Player>(new Fighter(name));
    }

    if (job == "Wizard")
    {
        return std::unique_ptr<Player>(new Wizard(name));
    }

    return std::unique_ptr<Player>(new Rogue(name));
}

std::unique_ptr<Card> Mtmchkin::convertStringToCard(const std::string cardName) const
{

    if (cardName == "Goblin")
    {
        return std::unique_ptr<Card>(new Goblin());
    }
    if (cardName == "Vampire")
    {
        return std::unique_ptr<Card>(new Vampire());
    }
    if (cardName == "Dragon")
    {
        return std::unique_ptr<Card>(new Dragon());
    }

    if (cardName == "Merchant")
    {
        return std::unique_ptr<Card>(new Merchant());
    }
    if (cardName == "Treasure")
    {
        return std::unique_ptr<Card>(new Treasure());
    }
    if (cardName == "Pitfall")
    {
        return std::unique_ptr<Card>(new Pitfall());
    }
    if (cardName == "Barfight")
    {
        return std::unique_ptr<Card>(new Barfight());
    }

    return std::unique_ptr<Card>(new Fairy());
}

void Mtmchkin::playRound()
{
    if(isGameOver())
    {
        return;
    }

    std::unique_ptr<Player> currentPlayer;
    std::unique_ptr<Card> currentCard;
    printRoundStartMessage(m_roundsPlayed + 1);
    int teamSizeOnThisRound = m_playerQueue.size();

    for (int i = 0; i < teamSizeOnThisRound; ++i)
    {
        currentPlayer = std::move(m_playerQueue.front());
        currentCard = std::move(m_deckCards.front());

        printTurnStartMessage(currentPlayer->getPlayerName());
        currentCard->applyEncounter(*currentPlayer);

        m_deckCards.pop();
        m_deckCards.push(std::move(currentCard));

        m_playerQueue.pop_front();
        if (currentPlayer->isKnockedOut())
        {
            m_defeatedPlayers.push_front(std::move(currentPlayer));
        }
        else if (currentPlayer->getLevel() == MAX_LEVEL)
        {
            m_winners.push_back(std::move(currentPlayer));
        }
        else
        {
            m_playerQueue.push_back(std::move(currentPlayer));
        }

        if (isGameOver())
        {
            printGameEndMessage();
        }
    }

    ++m_roundsPlayed;
}

void Mtmchkin:: printLeaderBoardHelper( const std::deque<std::unique_ptr<Player>> &players, int& ranking) const
{

    for(std::deque<std::unique_ptr<Player>>::const_iterator it = players.begin(); it != players.end(); ++it)
    {
        printPlayerLeaderBoard(ranking, **it);
        ranking++;
    }

}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int ranking = FIRST_RANK;
    printLeaderBoardHelper(m_winners, ranking);
    printLeaderBoardHelper(m_playerQueue, ranking);
    printLeaderBoardHelper(m_defeatedPlayers, ranking);

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