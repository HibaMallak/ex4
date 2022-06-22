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
        Player(const Player& p) = default;

        /*
        * D'tor of Player class
        *
        * @return
        *      Deletes this instance of Player.
        */
        virtual ~Player() = default;

        /*
        * Assignment operator
        *
        * @param p - The player to assign from.
        * @return
        *      default
        */
        Player& operator=(const Player& p) = default;

        /*
        * Increases the level of the player by one.
        *
        * @return
        *      void
        */
        void levelUp();

        /*
        * Increases the force of the player by given amount.
        *
        * @param forceToAdd - The given amount to add to the force of the player.
        * @return
        *      void
        */
        void buff(int forceToAdd);

        /*
        * Decreases the force of the player by given amount.
        *
        * @param forceToAdd - The given amount to add to the force of the player.
        * @return
        *      void
        */
        void lowerForce(int toLower);

        /*
        * Increases the health points of the player by given amount of points.
        *
        * @param printsToHeal - the amount of points to add to the health points of the player.
        * @return
        *      void
        */
        virtual void heal(int pointsToHeal);

        /*
        * Decreases the health points of the player by given amount of points.
        *
        * @param damageToDeal - the amount of points to reduce from the health points of the player.
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
        bool isKnockedOut() const;

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
        * Returns the attack strength, which is defined as force + level of the player.
        *
        * @return
        *      The attack strenth of the player.
        */
        virtual int getAttackStrength() const;

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

        /*
        * Returns the player's healthPoints.
        *
        * @return
        *      The amount of healthPoints the player has.
        */
        int getPlayerHealthPoints() const;

        /*
        * Returns the level of the player.
        *
        * @return
        *      The level of the player.
        */
        int getLevel() const;
        
        /*
        * Prints the player info:
        *
        * @param os - the ostream to print to
        * @return
        *      std::ostream&
        */
        virtual std::ostream& printPlayerInfo(std::ostream& os) const = 0;
        
        /*
        * operator << prints by calling printPlayerInfo:
        *
        * @param os - the ostream to print to
        * @param player - the player to print
        * @return
        *      std::ostream&
        */
        friend std::ostream& operator << (std::ostream& os, const Player& Player);

protected:
        
        const std::string m_name;
        int m_level;
        int m_force;
        int m_healthPoints;
        int m_coins;

};

#endif