#ifndef GANG_H
#define GANG_H

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

    /*
     * C'tor of Gang class
     *
     * @return
     *      A new instance of Gang.
    */
    Gang();
    
    /*
    * D'tor of Gang class
    *
    * @return
    *      Deletes this instance of Gang.
    */
    ~Gang() override = default;

    /*
    * Copy c'tor of Gang class
    *
    * @param gang - The gang to copy construct from.
    * @return
    *      A copied instance of gang.
    */
    Gang(const Gang& gang);

    /*
    * Assignment operator
    *
    * @param gang - The gang to assign from.
    * @return
    *      default
    */
    Gang& operator=(const Gang& gang);

    /*
     * Handling the player's applyEncounter with the gang:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
    * builds a new instance of Gang with a given card type and returns it as a unique pointer.
    *
    * @param cardName - type of the gang card 
    * @return
    *       a unique pointer of a new instance of BattleCards.
    */
    std::unique_ptr<BattleCards> addGangCard(std::string cardName) const;

    /*
     * fills the m_gangCards with the gang cards given in the file
     *
     * @param file - the file to get the gang cards from
     * @param card - the card to save current input in
     * @paragraph countLines - the counter of cards recieved
     * @return
     *      void
    */
    void buildGang(std::ifstream &file, std::string card, int &countLines) override;

    /*
     * Prints the gang info:
     *
     * @param os - the ostream to print to
     * @return
     *      std::ostream&
    */
    std::ostream& printInfo(std::ostream& os) const override;

private:
    std::deque<std::unique_ptr <BattleCards>> m_gangCards;

};
#endif
