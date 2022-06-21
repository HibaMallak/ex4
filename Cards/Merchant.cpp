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
    bool stoiFuncWork = true;
    std::string playerChoice;
    std::cin >> playerChoice;
    int intPlayerChoice;
    do
    {
        try
        {
            intPlayerChoice = std::stoi(playerChoice);
        }
        catch(...)
        {
            stoiFuncWork = false;
            printInvalidInput();
            std::cin >> playerChoice;
        }
        if(stoiFuncWork)
        {
            if(intPlayerChoice > LEAVE || intPlayerChoice < FORCE_BOOST)
            {
                stoiFuncWork = false;
            }
        }
    } while (!stoiFuncWork);

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