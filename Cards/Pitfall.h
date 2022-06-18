#ifndef PITFALL_H
#define PITFALL_H

#include "Card.h"

static const bool IS_ROUGE = false;
class Pitfall : public Card
{
    public:
    Pitfall();
    ~Pitfall() override = default;
    Pitfall(Pitfall& pitfall) = default;
    Pitfall& operator=(Pitfall& pitfall) = default;

    void applyEncounter(Player& player) const override;
    std::ostream& printInfo(std::ostream& os) const override;


    private:
      int m_damage = 10;
};

#endif