#ifndef Card_H
#define Card_H

#include <cstring>
#include "Player.h"
#include "utilities.h"

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card(const std::string cardName);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo() const;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    ~Card() = default;
    Card& operator=(const Card& other) = default;


protected:
    const std::string m_cardName;

};


#endif 