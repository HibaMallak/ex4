#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"

static const int DOUBLE_FORCE = 2;

class Fighter : public Player
{
public:
      /*
      * C'tor of Fighter class
      *
      * @param name - The name of the fighter.
      * @return
      *      A new instance of Player.
      */
      Fighter(std::string name);

      /*
      * D'tor of Fighter class
      *
      * @return
      *      Deletes this instance of Fighter.
      */
      ~Fighter() override = default;

      /*
      * Assignment operator
      *
      * @param fughter - The fighter to assign from.
      * @return
      *      default
      */
      Fighter& operator=(const Fighter& fighter) = default;

      /*
      * Copy c'tor of Fighter class
      *
      * @param fighter - The fighter to copy construct from.
      * @return
      *      A copied instance of Fighter.
      */
      Fighter(const Fighter& fighter) = default;
      
      /*
      * Returns the attack strength, which is defined as 2*force + level of the fighter.
      *
      * @return
      *      The attack strength of the fighter.
      */
      int getAttackStrength() const override;

      /*
      * Prints the fighter info:
      *
      * @param os - the ostream to print to
      * @return
      *      std::ostream&
      */
      std::ostream& printPlayerInfo(std::ostream& os) const override;

};

#endif