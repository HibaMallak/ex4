#ifndef UNTITLED3_GANG_H
#define UNTITLED3_GANG_H

#include "Card.h"
#include "Goblin.h"
#include "Vampire.h"
#include "Dragon.h"
#include "BattleCards.h"
#include <deque>
#include <iostream>


class Gang : public Card
{
public:
    Gang();
    ~Gang() override = default;
    Gang(const Gang& gang);
    Gang& operator=(Gang& gang);

    void applyEncounter(Player& player) const override;
    std::unique_ptr<BattleCards> addGangCard(std::string card_name);
    void buildGang(std::ifstream &file, std::string card, int &countLines) override;
    std::ostream& printInfo(std::ostream& os) const override;

private:
    std::deque<std::unique_ptr <BattleCards>> m_GangCards;



};
#endif //UNTITLED3_GANG_H
