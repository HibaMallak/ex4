#ifndef DRAGON_H
#define DRAGON_H
#include "BattleCards.h"
//#include "Card.h"


static const int DNE = 0;
class Dragon : public BattleCards
{
    static const int MIN_FOR_WIN = 25;

public:
        Dragon();
        ~Dragon() override = default;
        Dragon(Dragon& dragon) = default;
        Dragon& operator=(Dragon& dragon) = default;

        std::ostream& printInfo(std::ostream& os) const override;
        void win (Player& player)const  override;
        void loss (Player& player) const override;

    bool gang_Encounter(Player& player, bool check) const override;

private:
        int m_force = 25;
        int m_loot = 1000;

};

#endif