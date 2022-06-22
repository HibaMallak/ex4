#ifndef PITFALL_H
#define PITFALL_H

#include "Card.h"

static const bool IS_ROUGE = false;
class Pitfall : public Card
{
public:

    /*
    * C'tor of Pitfall class
    *
    * @return
    *      A new instance of Pitfall.
    */
    Pitfall();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Pitfall() override = default;
    Pitfall(const Pitfall& pitfall) = default;
    Pitfall& operator=(const Pitfall& pitfall) = default;

    /*
    * Handling the player's applyEncounter with the pitfall:
    *
    * @param player - The player.
    * @return
    *      void
    */
    void applyEncounter(Player& player) const override;

    /*
    * Prints the pitfall info:
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