#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "BattleCards.h"
#include "Card.h"

class Vampire : public BattleCards
{
    public:
        Vampire();
        ~Vampire()=default;
        Vampire(Vampire& vampire)=default;
        Vampire& operator=(Vampire& vampire) =default;

        std::ostream& operator<<(std::ostream& os) const override;
        void win (Player& player) const  override;
        void loss (Player& player) const  override;

    private:
      int m_force = 10;
      int m_loot = 2;
      int m_damage = 10;
      int m_forceToLose = 1;


};

#endif