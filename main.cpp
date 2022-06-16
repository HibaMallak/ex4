#include <iostream>
#include "Mtmchkin.h"
int main() {
    const int MAX_NUMBERS_OF_ROUNDS = 100;
    try {
        Mtmchkin game("deck.txt");
        while (!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBERS_OF_ROUNDS)
        {
            game.playRound();
        }

        game.printLeaderBoard();
    } catch (const std::exception &e)
    {
     std::cerr << e.what() << std::endl;
    }

    return 0;
}
