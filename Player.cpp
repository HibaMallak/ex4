#include "Player.h"
//add playertype whe neccessary

Player::Player(const std::string name) : m_name(name), m_level(FIRST_LEVEL), m_force(DEFAULT_FORCE), m_HP(MAX_HP)
        , m_coins(COINS_ON_START)
{
    if(! is_Valid_name(name))
    {
        printInvalidName();
        throw ; ///..........add!!!!!!
    }

}


bool Player:: is_Valid_name (const std::string name)
{
    if(name.length() > MAX_NAME_LENGTH || name.length() )
    {
        return false;
    }

    int len= name.length();
    char charAtIndex;

    for(int i = MIN_NATURAL; i < len; i++)
    {
        charAtIndex = name.at(i);
        if(charAtIndex < 'A' || charAtIndex > 'z' || (charAtIndex > 'Z' && charAtIndex < 'a'))
        {
            return false;

            // maybe need other exp than first if????????
        }
    }

    return true;
}



void Player::levelUp()
{
    if(this->m_level!= MAX_LEVEL)
    {
        ++this->m_level;
    }
}

int Player::getLevel()
{
    return this->m_level;
}

void Player::buff(int forceToAdd)
{
    if(forceToAdd>0)
    {
        this->m_force += forceToAdd;
    }
}

void Player::heal(int pointsToHeal)
{
    if(pointsToHeal>0)
    {
        if(this->m_HP+ pointsToHeal > MAX_HP)
        {
            this->m_HP= MAX_HP;
        }
        else
        {
            this->m_HP += pointsToHeal;
        }
    }
}

void Player::damage(int damageToMake)
{
    if(damageToMake>0)
    {
        if(this->m_HP - damageToMake <0)
        {
            this->m_HP =0;
        }
        else
        {
            this->m_HP -= damageToMake;
        }
    }
}

bool Player::isKnockedOut()
{
    if(this->m_HP <= MIN_NATURAL)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd)
{
    if(coinsToAdd> MIN_NATURAL)
    {
        this->m_coins += coinsToAdd;
    }
}

bool Player::pay(int coinsToPay)
{
    if(coinsToPay> MIN_NATURAL)
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

int Player::getAttackStrength()
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

void Player::lowerForce(int toLower)
{
    this->m_force -= toLower;
    if(this->m_force < MIN_NATURAL)
    {
        this->m_force == MIN_NATURAL;
    }
}