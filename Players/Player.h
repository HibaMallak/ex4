#ifndef EX2_Player_H
#define EX2_Player_H
#include <cstring>
#include <iostream>


static const int MIN_NATURAL = 0;
static const int DEFAULT_FORCE = 5;
static const int MAX_HP = 100;
static const int FIRST_LEVEL = 1;
static const int MAX_LEVEL = 10;
static const int COINS_ON_START = 10;
static const int MAX_NAME_LENGTH = 15;

class Player{
        public:
        /*
         * C'tor of Player class
         *
         * @param name - The name of the player.
         * @param maxHP - The maxHP of the player.
         * @return
         *      A new instance of Player.
        */
        Player(const std::string name);


        /*
         * Copy c'tor of Player class
         *
         * @param p - The player to copy construct from.
         * @return
         *      A copied instance of p.
        */
        Player(const Player& p)=default;


        /*
         * D'tor of Player class
         *
         * @return
         *      Deletes this instance of Player.
        */
        virtual ~Player()=default;


        /*
         * Assignment operator
         *
         * @param p - The player to assign from.
         * @return
         *      default
        */
        Player& operator=(Player& p) =default;


        /*
         * Prints the player info:
         *
         * @return
         *      void
        */
        virtual std::ostream& printPlayerInfo(std::ostream& os) const =0;


        /*
         * Increases the level of the player by one.
         *
         * @return
         *      void
        */
        void levelUp();


        /*
         * Returns the level of the player.
         *
         * @return
         *      The level of the player.
        */
        int getLevel();


        /*
         * Increases the force of the player by given amount.
         *
         * @param forceToAdd - The given amount to add to the force of the player.
         * @return
         *      void
        */
        void buff(int forceToAdd);


        /*
         * Increases the HP of the player by given amount of points.
         *
         * @param printsToHeal - the amount of points to add to the HP of the player.
         * @return
         *      void
        */
        virtual void heal(int pointsToHeal);


        /*
         * Decreases the HP of the player by given amount of points.
         *
         * @param damageToDeal - the amount of points to reduce from the HP of the player.
         * @return
         *      void
        */
        void damage(int damageToDeal);


        /*
         * Check if the player is knocked out:
         *
         * @return
         *      True if player is knocked out
         *      False otherwise
        */
        bool isKnockedOut();


        /*
         * Increases the coins of the player by given amount of coins.
         *
         * @param coinsToAdd - the amount of coins to add to the coins of the player.
         * @return
         *      void
        */
        virtual void addCoins(int coinsToAdd);


        /*
         * Check if player can pay the given amount of coins, and pays if possible.
         *
         * @param coinsToPay - the amount of coins to pay.
         * @return
         *      True if player can pay
         *      False otherwise
        */
        bool pay(int coinsToPay);


        /*
         * Returns the attack strenth, which is defined as force + level of the player.
         *
         * @return
         *      The attack strenth of the player.
        */
        virtual int getAttackStrength();


        /*
         * Returns the player's name.
         *
         * @return
         *      The name of the player.
        */
        std::string getPlayerName() const;

        /*
         * Returns the player's coins number.
         *
         * @return
         *      The number of coins the player has.
        */
        int getPlayerCoins() const;

        int getPlayerHP() const;

        /*
         * Decreases the force of the player by one.
         *
         * @param forceToAdd - The given amount to add to the force of the player.
         * @return
         *      void
        */
        void lowerForce(int toLower);
        static bool is_Valid_name (const std::string player_name); // static?????


protected:
        const std::string m_name;
        int m_level;
        int m_force;
        int m_HP;
        int m_coins;
        //const std::string m_playerType;//according to piazza they might יורידו נקודות


}

std::ostream& operator << (std::ostream& os, const Card& card);
;




#endif