#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Card.h"
#include "Player.h"
#include "Exception.h"
#include <iostream>
#include <memory>
#include <string.h>
#include <queue>
#include <deque>
#include "Fighter.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Fairy.h"
#include "Barfight.h"
#include "Pitfall.h"
#include "Treasure.h"
#include "Merchant.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"

static const bool REVERSE = true;
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

    int m_numOfPlayers;
    int m_roundsPlayed;
    std::queue<std::unique_ptr <Card>> m_deckCards;
    std::deque<std::unique_ptr <Player>> m_playerQueue;
    std::deque<std::unique_ptr <Player>> m_defeatedPlayers;
    std::deque<std::unique_ptr <Player>> m_winners;

    bool is_Valid_Player_Class (const std::string player_name);
    std::unique_ptr<Player> convet_stringToPlayer (const std::string player_job);
    std::unique_ptr<Card> convet_stringToCard (const std::string card_name);


    /*
        * A helper function used in Mtmchkin::printLeaderBoard(). prints the leaderboard for one queue of players.
        *
        * @param players - the queue which contains the players needed to print thier leaderboard.
        * @param ranking - the rank of the first player in currentQueue.
        * @return
        *      void
        */
    void printLeaderBoardHelper(std::queue<std::unique_ptr <Player>> players, int ranking) const;

};


#endif