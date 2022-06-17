#ifndef FAIRY_H
#define FAIRY_H

#include "Cards/Card.h"

static const bool IS_WIZARD = true;
class Fairy : public Card
{
    public:

    Fairy();
    ~Fairy() = default;
    Fairy(Fairy& fairy) = default;
    Fairy& operator=(Fairy& fairy) = default;

    void applyEncounter(Player& player) const override;
    std::ostream& printInfo(std::ostream& os) const override;

    private:
        int m_FairyHP = 10;
};

#endif