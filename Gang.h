#ifndef UNTITLED3_GANG_H
#define UNTITLED3_GANG_H

#include "Card.h"
#include "Goblin.h"
#include "Vampire.h"
#include "Dragon.h"
#include "BattleCards.h"
#include <deque>


class Gang : public Card
{
public:
    Gang();
    ~Gang() override = default;
    Gang(Gang& gang) = default;
    Gang& operator=(Gang& gang) = default;

    void applyEncounter(Player& player) const override;
    void Gang::addGangCard(std::string card_name);

private:
    std::deque<std::unique_ptr <BattleCards>> m_GangCards;



};
#endif //UNTITLED3_GANG_H
