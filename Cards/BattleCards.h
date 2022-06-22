
#ifndef UNTITLED3_BATTLECARDS_H
#define UNTITLED3_BATTLECARDS_H

#include "Card.h"
static const bool IS_DRAGON = true;
static const int MIN_TO_WIN_DRAGON = 25;
static const int MIN_TO_WIN_GOBLIN = 6;
static const int MIN_TO_WIN_VAMPIRE = 10;
static const std::string DRAGON = "Dragon";
static const std::string VAMPIRE = "Vampire";
static const std::string GOBLIN = "Goblin";

class BattleCards : public Card
{
public:

    /*
     * C'tor of Barfight class
     *
     * @return
     *      A new instance of Barfights.
    */
    BattleCards(const std::string m_name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    BattleCards(const BattleCards& battleCard) = default;
    BattleCards& operator=(const BattleCards& battleCard) = default;
    virtual ~BattleCards() override = default;

    /*
     * Handling the player's applyEncounter with the battle card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Applies changes on player when result of encounter one of gang cards is win:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void win (Player& player) const = 0;

    /*
     * Applies changes on player when result of encounter one of gang cards is loss:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void loss (Player& player) const = 0;

    /*
     * Prints the battle card info:
     *
     * @param os - the ostream to print to
     * @return
     *      std::ostream&
    */
    virtual std::ostream& printInfo(std::ostream& os) const = 0;

    /*
     * Handling the player's applyEncounter when card is part of a gang:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual bool gang_Encounter(Player& player, bool check) const =0;

protected:
    int m_force;
    int m_loot;
    int m_damage;
    int m_forceToLose;

};

#endif