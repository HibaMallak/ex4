#ifndef PITFALL_H
#define PITFALL_H

#include "Card.h"

static const bool IS_ROUGE = false;
class Pitfall : public Card
{
    public:
        Pitfall()= default; //???????
         ~Pitfall() = default;
        void applyEncounter(Player& player) const override;

    private:
      int m_damage = 10;
};

#endif