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
    std::string playerChoice;
    std::getline(std::cin, playerChoice);

    while(std::stoi(playerChoice) < LEAVE || std::stoi(playerChoice) > FORCE_BOOST)
    {
        printInvalidInput();
        std::getline(std::cin, playerChoice);
    }

    if(std::stoi(playerChoice) == HEALTH_POTION)
    {
        if (!player.pay(this->m_coinsPerPotion))
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getPlayerName(), std::stoi(playerChoice), paid);
            return;

        }

        player.heal(this->m_toAdd);
        paid = this->m_coinsPerPotion;
    } 
    if(std::stoi(playerChoice) == FORCE_BOOST)
    {
        if (!player.pay(this->m_coinsPerBoost))
        {
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout, player.getPlayerName(), std::stoi(playerChoice), paid);
        }

        player.buff(this->m_toAdd);
        paid = this->m_coinsPerBoost;
    }

    printMerchantSummary(std::cout, player.getPlayerName(), std::stoi(playerChoice), paid);
}


std::ostream& Merchant:: printInfo(std::ostream& os) const
{
    printCardDetails(os, "Merchant");
    return os;
}