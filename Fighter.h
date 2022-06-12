#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"

static const int DOUBLE_FORCE = 2;

class Fighter : public Player
{
    public:
    Fighter();
    ~Fighter() = default;
    Fighter& operator=(Rouge& p) =default;
    int getAttackStrength() override;
    void operator<<(std::ostream& os) override;

};

#endif