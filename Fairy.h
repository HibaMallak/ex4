#ifndef FAIRY_H
#define FAIRY_H

#include "Card.h"

static const bool IS_WIZARD = true;
class Fairy : public Card
{
    public:
        void applyEncounter(Player& player) const override;

    private:
        int m_FairyHP = 10;
};

#endif