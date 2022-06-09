#ifndef ROUGE_H
#define ROUGE_H

#include "Player.h"

static const int DOUBLE_COINS = 2;

class Rouge : public Player
{
    public:
        void addCoins(int coinsToAdd) override;
        void printInfo() override;
};

#endif