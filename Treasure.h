#ifndef TREASURE_H
#define TREASURE_H

#include "Card.h"

class Treasure : public Card
{
    public:
        Treasure();
        ~Treasure()= default;
        Treasure(Treasure& treasure)=default;
        Treasure& operator=(Treasure& treasure) =default;

    void applyEncounter(Player& player) const override;
    std::ostream& operator<<(std::ostream& os) const override;


    private:
        int m_coins = 10;
};

#endif