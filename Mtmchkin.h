#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "string.h"
#include "Queue.h"
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <string.h>

static const bool REVERSE = true;
static const bool GAME_OVER = true;
static const int FIRST_RANK = 1;
static const int NO_ROUNDS_PLAYED = 0;
static const int MIN_TEAM_SIZE = 2;
static const int MAX_TEAM_SIZE = 6;


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
    Queue<Card> m_deckCards;
    Queue<Player> m_playerQueue;
    Queue<Player> m_defeatedPlayers;
    Queue<Player> m_winners;

    /*
    * A helper function used in Mtmchkin::printLeaderBoard(). prints the leaderboard for one queue of players.
    *
    * @param players - the queue which contains the players needed to print thier leaderboard.
    * @param ranking - the rank of the first player in currentQueue.
    * @param reverse - if true, will print the elements in opposite way.
    * @return
    *      void
    */
    void printLeaderBoardHelper(Queue<Player> players, int ranking, bool reverse) const;

};


#endif 
