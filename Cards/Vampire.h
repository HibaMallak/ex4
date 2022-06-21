#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "BattleCards.h"
#include "Card.h"



class Vampire : public BattleCards
{
    static const int MIN_FOR_WIN = 10;

    public:
        Vampire();
        ~Vampire() override = default;
        Vampire(Vampire& vampire) = default;
        Vampire& operator=(Vampire& vampire) = default;

        std::ostream& printInfo(std::ostream& os) const override;
        void win (Player& player) const  override;
        void loss (Player& player) const  override;

        bool gang_Encounter(Player& player, bool check) const override;


    private:
      int m_force = 10;
      int m_loot = 2;
      int m_damage = 10;
      int m_forceToLose = 1;


};

#endif