#include "Card.h"

Card::Card(const std::string cardName): m_cardName (cardName)
{
    if(cardName.length() > MAX_NAME_LENGTH || cardName.length() || (!is_Valid_card(cardName))  )
    {
        printInvalidName();
        //THROW DeckFileFormat
    }
}

bool Card:: is_Valid_card (const std::string cardName)
{
    int len= cardName.length();
    char charAtIndex;

    /// delete
    for(int i= MIN_NATURAL; i< len; i++)
    {
        charAtIndex = cardName.at(i);
        if(charAtIndex< 'A' || charAtIndex > 'z' || charAtIndex> 'Z' || charAtIndex< 'a')
            printInvalidName();
    }

    if (cardName != "Goblin" && cardName != "Vampire" && cardName != "Dragon" && cardName != "Merchant" &&
            cardName != "Treasure" &&cardName != "Pitfall" &&cardName != "Barfight" &&cardName != "Fairy")
    {
        return false;
    }
    return true;

}