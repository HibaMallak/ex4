#ifndef BARFIGHT_H
#define BARFIGHT_H

#include "Card.h"

static const bool IS_FIGHTER = false;
class Barfight : public Card
{
    public:

    /*
     * C'tor of Barfight class
     *
     * @return
     *      A new instance of Barfights.
    */
    Barfight();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Barfight() override = default;
    Barfight(const Barfight& barfight) = default;
    Barfight& operator=(const Barfight& barfight) = default;

    /*
     * Handling the player's applyEncounter with the barfight:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Prints the gang info:
     *
     * @param os - the ostream to print to
     * @return
     *      std::ostream&
    */
    std::ostream& printInfo(std::ostream& os) const override;

    private:
        int m_damage = 10;
};

#endif