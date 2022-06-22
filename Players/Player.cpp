#include "Player.h"
#include "../utilities.h"

Player::Player(const std::string name) : m_name(name), m_level(FIRST_LEVEL), m_force(DEFAULT_FORCE)
    , m_healthPoints(MAX_HP), m_coins(COINS_ON_START)
{

}

void Player::levelUp()
{
    if(this->m_level != MAX_LEVEL)
    {
        ++this->m_level;
    }
}

void Player::buff(int forceToAdd)
{
    if(forceToAdd > MIN_NATURAL)
    {
        this->m_force += forceToAdd;
    }
}

void Player::lowerForce(int toLower)
{
    this->m_force -= toLower;
    if(this->m_force < MIN_NATURAL)
    {
        this->m_force = MIN_NATURAL;
    }
}

void Player::heal(int pointsToHeal)
{
    if(pointsToHeal > MIN_NATURAL)
    {
        if(this->m_healthPoints + pointsToHeal > MAX_HP)
        {
            this->m_healthPoints = MAX_HP;
        }
        else
        {
            this->m_healthPoints += pointsToHeal;
        }
    }
}

void Player::damage(int damageToMake)
{
    if(damageToMake >= MIN_NATURAL)
    {
        if(this->m_healthPoints - damageToMake <= MIN_NATURAL)
        {
            this->m_healthPoints = MIN_NATURAL;
        }
        else
        {
            this->m_healthPoints -= damageToMake;
        }
    }
}

bool Player::isKnockedOut() const
{
    if(this->m_healthPoints <= MIN_NATURAL)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    if(coinsToAdd > MIN_NATURAL)
    {
        this->m_coins += coinsToAdd;
    }
}

bool Player::pay(int coinsToPay)
{
    if(coinsToPay > MIN_NATURAL)
    {
        if(this->m_coins - coinsToPay < MIN_NATURAL)
        {
            return false;
        }
        else
        {
            this->m_coins -= coinsToPay;
            return true;
        }
    }
    return true;
}

int Player::getAttackStrength() const
{
    return this->m_force + this->m_level;
}

std::string Player::getPlayerName() const
{
    return this->m_name;
}

int Player::getPlayerCoins() const
{
    return this->m_coins;
}

int Player::getPlayerHealthPoints() const
{
    return this->m_healthPoints;
}

int Player::getLevel() const
{
    return this->m_level;
}

std::ostream& operator<< (std::ostream& os, const Player& player)
{
    return player.printPlayerInfo(os);
}
