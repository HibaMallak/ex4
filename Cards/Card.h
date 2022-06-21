#ifndef Card_H
#define Card_H

#include <cstring>
#include <memory>
#include "../Players/Player.h"
#include "../utilities.h"

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
    Card() = default;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const=0 ; // shani change from & to * >?????????


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;
    
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual std::ostream& printInfo(std::ostream& os) const =0;

    friend std::ostream& operator << (std::ostream& os, const Card& card);
    bool is_Valid_card (const std::string cardName);
    virtual void addGangCard(std::string card_name){};


protected:
    const std::string m_cardName;
};


#endif 