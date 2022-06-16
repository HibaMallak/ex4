
#ifndef UNTITLED3_BATTLECARDS_H
#define UNTITLED3_BATTLECARDS_H

#include "Card.h"
static const bool IS_DRAGON = true;


class BattleCards : public Card
{
public:
    BattleCards(std::string m_name);
    virtual ~BattleCards()=default;

    void applyEncounter(Player& player) const override; // shani change from & to *
    virtual void win (Player& player) const =0;
    virtual void loss (Player& player) const =0;
    virtual std::ostream& printInfo(std::ostream& os) const = 0;


protected:
    int m_force;
    int m_loot;
    int m_damage;
    int m_forceToLose;





};

#endif