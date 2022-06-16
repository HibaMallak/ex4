#ifndef DRAGON_H
#define DRAGON_H
#include "Cards/BattleCards.h"
#include "Cards/Card.h"

static const int DNE = 0;
class Dragon : public BattleCards
{
    public:
        Dragon();
        ~Dragon() = default;
        Dragon(Dragon& dragon) = default;
        Dragon& operator=(Dragon& dragon) = default;

        std::ostream& printInfo(std::ostream& os) const override;
        void win (Player& player)const  override;
        void loss (Player& player) const override;

    private:
        int m_force = 25;
        int m_loot = 1000;

};

#endif