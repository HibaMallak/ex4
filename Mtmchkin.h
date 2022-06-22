#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Exception.h"
#include "utilities.h"
#include <iostream>
#include <memory>
#include <cstring>
#include <queue>
#include <deque>
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include "Cards/Fairy.h"
#include "Cards/Barfight.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Cards/Dragon.h"
#include "Cards/Vampire.h"
#include "Cards/Goblin.h"
#include "Cards/Gang.h"

static const bool GAME_OVER = true;
static const int FIRST_RANK = 1;
static const int NO_ROUNDS_PLAYED = 0;
static const int MIN_TEAM_SIZE = 2;
static const int MAX_TEAM_SIZE = 6;
static const int MIN_CARD_SIZE = 5;


class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);


    Mtmchkin(const Mtmchkin& game) = delete;
    Mtmchkin& operator=(Mtmchkin& game) = delete;

    ~Mtmchkin() = default;

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:

    int m_roundsPlayed;
    std::queue<std::unique_ptr <Card>> m_deckCards;
    std::deque<std::unique_ptr <Player>> m_playerQueue;
    std::deque<std::unique_ptr <Player>> m_defeatedPlayers;
    std::deque<std::unique_ptr<Player>> m_winners;

    /*
    * fills the m_deckCards with the cards given in the fileName
    *
    * @param fileName - the file to get the cards from
    * @return
    *       void
    */
    void fillCardsDeck(const std::string fileName);

    /*
    * recieve the team size 
    *
    * @return
    *       the team size
    */
    std::string getAndCheckTeamSize() const;

    /*
    * builds a new instance of Player with a given job and returns it as a unique pointer.
    *
    * @param playerJob - job of the player 
    * @return
    *       a unique pointer of a new instance of Player.
    */
    std::unique_ptr<Player> convertStringToPlayer (const std::string playerJob) const;

    /*
    * builds a new instance of Card with a given kind of card and returns it as a unique pointer.
    *
    * @param cardName - kind of the card
    * @return
    *       a unique pointer of a new instance of Card.
    */
    std::unique_ptr<Card> convertStringToCard (const std::string cardName) const;
    
    /*
    * Check if playerName is valid according to the instruction in the exercise document.
    *
    * @param name - a string which consists of a name 
    * @return
    *       True if playerName is valid
    *       False otherwise
    */
    bool isValidName (const std::string name) const;

    /*
    * Check if the player's name and class given are valid according to the instruction in the exercise document.
    *
    * @param nameAndClass - a string which consists of a name and class
    * @return
    *       True if name and class are valid
    *       False otherwise
    */
    bool isValidPlayerClass (const std::string nameAndClass) const;

    /*
    * A helper function used in Mtmchkin::printLeaderBoard(). prints the leaderboard for one queue of players.
    *
    * @param players - the queue which contains the players needed to print thier leaderboard.
    * @param ranking - the rank of the first player in the given queue.
    * @return
    *      void
    */
    void printLeaderBoardHelper( const std::deque<std::unique_ptr <Player>> &players, int& ranking) const;

};


#endif