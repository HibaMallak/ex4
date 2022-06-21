#include "Card.h"

Card::Card(const std::string cardName): m_cardName (cardName)
{
    //if(cardName.length() > MAX_NAME_LENGTH || cardName.length() || (!is_Valid_card(cardName))  )

}


int Card::is_Valid_card(const std::string cardName)
{
    if (cardName == "Goblin" || cardName == "Vampire" || cardName == "Dragon")
    {
        return GANG_CARD;
    }
    if(cardName != "Merchant" && cardName != "Treasure" && cardName != "Pitfall"
       && cardName != "Barfight" && cardName != "Fairy"&&cardName!="Gang"&&cardName!="EndGang")
    {
        return CARD_INVALID;
    }
    return NON_GANG_CARD;
}

std::ostream& operator << (std::ostream& os, const Card& card)
{
    return card.printInfo(os);
}
