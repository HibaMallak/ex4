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
    Gang(const Gang& gang);
    Gang& operator=(Gang& gang);

    void applyEncounter(Player& player) const override;
    void addGangCard(std::string card_name);

private:
    std::deque<std::unique_ptr <BattleCards>> m_GangCards;



};
#endif //UNTITLED3_GANG_H
