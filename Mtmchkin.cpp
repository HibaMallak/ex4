#include "Mtmchkin.h"

Mtmchkin:: Mtmchkin(const std::string fileName)
{
    int team_size;
    std::string player_name;

    m_deck_cards.pushBack(fileName.)///??????

    printStartGameMessage();

    do {
        printEnterTeamSizeMessage();
        cin >> team_size;

        if (team_size<2 || team_size>6)
        {
            printInvalidTeamSize();
        }
    } while (team_size<2 || team_size>6);


    do {
        printInsertPlayerMessage();
        cin >> player_name;

    } while (check);





}


int Mtmchkin::getNumberOfRounds() const
{
    return this->m_roundsPlayed;
}