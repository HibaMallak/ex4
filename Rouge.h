#ifndef ROUGE_H
#define ROUGE_H

#include "Player.h"

static const int DOUBLE_COINS = 2;

class Rouge : public Player
{
    public:
    Rouge(const std::string name);
    ~Rouge() = default;
    Rouge& operator=(Rouge& p) =default;

        void addCoins(int coinsToAdd) override;
        void operator<<(std::ostream& os) override;
};

#endif