#ifndef ROUGE_H
#define ROUGE_H

#include "Player.h"

static const int DOUBLE_COINS = 2;

class Rogue : public Player
        {
        public:
         Rogue(std::string name);
         Rogue(Rogue& rogue)=default;;
        ~Rogue() = default;
         Rogue& operator=(Rogue& rogue) =default;


        void addCoins(int coinsToAdd) override;
        void operator<<(std::ostream& os) override;
        };

#endif