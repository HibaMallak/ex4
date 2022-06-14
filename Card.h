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
    virtual void applyEncounter(Player& player) const=0 ; // shani change from & to * >?????????


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual std::ostream& operator<<(std::ostream& os) const=0;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;


    bool is_Valid_card (const std::string cardName);


    protected:
    const std::string m_cardName;

};


#endif 