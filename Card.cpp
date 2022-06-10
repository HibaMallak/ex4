#include "Card.h"

Card::Card(const std::string cardName): m_cardName (cardName)
{
    if(cardName.length() > MAX_NAME_LENGTH || cardName.length() )
    {
        printInvalidName();
    }
    else
    {
        int len= cardName.length();
        char charAtIndex;

        for(int i= MIN_NATURAL; i< len; i++)
        {
            charAtIndex = cardName.at(i);
            if(charAtIndex< 'A' || charAtIndex > 'z' || charAtIndex> 'Z' || charAtIndex< 'a')
                printInvalidName();
        }
    }
}