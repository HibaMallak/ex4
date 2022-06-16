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
    int playerChoice; //maybe add the isdigit and isalpha??
     std::cin >> playerChoice;

    while(playerChoice < LEAVE || playerChoice > FORCE_BOOST)
    {
        printInvalidInput();
        std::cin >> playerChoice;//        std::cin >> playerChoice;
    }

    if(playerChoice == HEALTH_POTION)
    {
        if (!player.pay(this->m_coinsPerPotion))
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getPlayerName(), playerChoice, paid);
            return;

        }

        player.heal(this->m_toAdd);
        paid = this->m_coinsPerPotion;
    } 
    if(playerChoice == FORCE_BOOST)
    {
        if (!player.pay(this->m_coinsPerBoost))
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getPlayerName(), playerChoice, paid);
        }

        player.buff(this->m_toAdd);
        paid = this->m_coinsPerBoost;
    }

    printMerchantSummary(std::cout, player.getPlayerName(), playerChoice - LEAVE, paid);
}


std::ostream& Merchant:: printInfo(std::ostream& os) const
{
    printCardDetails(os, "Merchant");
    return os;
}