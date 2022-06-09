#include "Card.h"

Card::Card(const std::string cardName)
{
    m_cardName = cardName; //problem, no operator= for string??????
}