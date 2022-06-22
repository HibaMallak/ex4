#ifndef FAIRY_H
#define FAIRY_H

#include "Card.h"

static const bool IS_WIZARD = true;
class Fairy : public Card
{
public:

    /*
     * C'tor of Fairy class
     *
     * @return
     *      A new instance of Fairy.
    */
    Fairy();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    ~Fairy() override = default;
    Fairy(const Fairy& fairy) = default;
    Fairy& operator=(const Fairy& fairy) = default;

    /*
     * Handling the player's applyEncounter with the fairy:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Prints the fairy info:
     *
     * @param os - the ostream to print to
     * @return
     *      std::ostream&
    */
    std::ostream& printInfo(std::ostream& os) const override;

private:
        int m_FairyHealthPoints = 10;
};

#endif