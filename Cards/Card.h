#ifndef Card_H
#define Card_H

#include <cstring>
#include <memory>
#include "../Players/Player.h"
#include "../utilities.h"

static const int CARD_INVALID = 0;
static const int GANG_CARD = 1;
static const int NON_GANG_CARD = 2;

class Card 
{
public:

    /*
     * C'tor of Card class
     *
     * @param cardName - The type of the card.
     * @return
     *      A new instance of Card.
    */
    Card(const std::string cardName);

    /*
     * the default C'tor of Card class
     *
     * @return
     *      A new instance of Card.
    */
    Card() = default;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0 ;

    /*
     * Prints the card info:
     *
     * @param os - the ostream to print to
     * @return
     *      std::ostream&
    */
    virtual std::ostream& printInfo(std::ostream& os) const = 0;

    /*
     * Prints the card info:
     *
     * @param os - the ostream to print to
     * @param card - the card to print
     * @return
     *      void
    */
    friend std::ostream& operator << (std::ostream& os, const Card& card);

    /*
     * only used when card is Gang
     * fills the m_gangCards with the gang cards given in the file
     *
     * @param file - the file to get the gang cards from
     * @param card - the card to save current input in
     * @paragraph countLines - the counter of cards recieved
     * @return
     *      void
    */
    virtual void buildGang(std::ifstream& file, std::string card, int &countLines){};

    /*
    * Check if cardName is valid according to the instruction in the exercise document.
    *
    * @param cardName - a string which consists of a cardName 
    * @return
    *       0 if cardName is invalid
    *       1 if cardName is a gang card
    *       2 if cardName is not a gang card 
    */
    static int isValidCard(const std::string cardName);

protected:
    const std::string m_cardName;
};


#endif 