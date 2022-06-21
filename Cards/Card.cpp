#include "Card.h"

Card::Card(const std::string cardName): m_cardName (cardName)
{
    //if(cardName.length() > MAX_NAME_LENGTH || cardName.length() || (!is_Valid_card(cardName))  )

}

bool Card:: is_Valid_card (const std::string cardName)
{

    if (cardName != "Goblin" && cardName != "Vampire" && cardName != "Dragon" && cardName != "Merchant" &&
            cardName != "Treasure" &&cardName != "Pitfall" &&cardName != "Barfight" &&cardName != "Fairy")
    {
        return false;
    }
    return true;

    /*
    int len= cardName.length();
    char charAtIndex;

    /// maybe delete
    for(int i= MIN_NATURAL; i< len; i++)
    {
        charAtIndex = cardName.at(i);
        if(charAtIndex< 'A' || charAtIndex > 'z' || charAtIndex> 'Z' || charAtIndex< 'a')
            printInvalidName();
    }

     */

}

std::ostream& operator << (std::ostream& os, const Card& card)
{
    return card.printInfo(os);
}
