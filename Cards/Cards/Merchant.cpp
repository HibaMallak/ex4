#include "Merchant.h"
#include <fstream>
#include <iostream>
#include <string>

Merchant :: Merchant() : Card("Merchant")
{

}

void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(), player.getPlayerCoins());
    int paid = 0;
    //bool stoiFuncWork = false;
    std::string playerChoice;
    int intPlayerChoice;
    while(getline(std::cin, playerChoice))
    {
        try
        {
            intPlayerChoice = std::stoi(playerChoice);
        }
        catch(...)
        {
            printInvalidInput();
            continue;
        }
        if(intPlayerChoice < LEAVE || intPlayerChoice > FORCE_BOOST)
        {
            printInvalidInput();
            continue;
        }
        else
        {
            break;
        }  
    }
/*
    do
    {
        try
        {
            getline(std::cin, playerChoice);
            intPlayerChoice = std::stoi(playerChoice);
            stoiFuncWork = true;
        }
        catch(...)
        {
            stoiFuncWork = false;
            printInvalidInput();
        }
        if(stoiFuncWork)
        {
            if(intPlayerChoice < LEAVE || intPlayerChoice > FORCE_BOOST)
            {
                stoiFuncWork = false;
                printInvalidInput();
            }
            else
            {
                break;
            }
        }
    } while (!stoiFuncWork);
*/
    if(intPlayerChoice == HEALTH_POTION)
    {
        if (!player.pay(this->m_coinsPerPotion))
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getPlayerName(), HEALTH_POTION, paid);
            return;

        }
        player.heal(this->m_toAdd);
        paid = this->m_coinsPerPotion;
        printMerchantSummary(std::cout, player.getPlayerName(), HEALTH_POTION, paid);
    } 
    if(intPlayerChoice == FORCE_BOOST)
    {
        if (!player.pay(this->m_coinsPerBoost))
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getPlayerName(), FORCE_BOOST, paid);
            return;
        }

        player.buff(this->m_toAdd);
        paid = this->m_coinsPerBoost;
        printMerchantSummary(std::cout, player.getPlayerName(), FORCE_BOOST, paid);
    }
    if(intPlayerChoice == LEAVE)
    {
        printMerchantSummary(std::cout, player.getPlayerName(), LEAVE, paid);
    }
}


std::ostream& Merchant:: printInfo(std::ostream& os) const
{
    printCardDetails(os, "Merchant");
    printEndOfCardDetails(os);
    return os;
}