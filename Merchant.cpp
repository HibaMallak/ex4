#include "Merchant.h"

Merchant :: Merchant() : Card("Merchant")
{

}

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

    printMerchantSummary(std::cout, player.getPlayerName(), playerChoice, paid);
}


std::ostream& Merchant:: operator<<(std::ostream& os) const
{
    printCardDetails(os,"Merchant");
}