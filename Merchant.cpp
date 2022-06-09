#include "Merchant.h"

void Merchant::applyEncounter(Player& player) const
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(), player.getPlayerCoins());
    int playerChoice, paid = 0;
    std::cin >> playerChoice;
    while(playerChoice < LEAVE || playerChoice > FORCE_BOOST)
    {
        printInvalidInput();
        std::cin >> playerChoice;
    }
    if(playerChoice == HEALTH_POTION)
    {
        try
        {
            player.pay(this->m_coinsPerPotion);
            player.heal(this->m_toAdd);
            paid = this->m_coinsPerPotion;
        }
        catch(...)//adding exceptions later
        {
            printMerchantInsufficientCoins(std::cout);
        }
    } 
    if(playerChoice == FORCE_BOOST)
    {
        try
        {
            player.pay(this->m_coinsPerBoost);
            player.buff(this->m_toAdd);
            paid = this->m_coinsPerBoost;
        }
        catch(...)//adding exceptions later
        {
            printMerchantInsufficientCoins(std::cout);
        }
    }
    printMerchantSummary(std::cout, player.getPlayerName(), playerChoice, paid);
}
