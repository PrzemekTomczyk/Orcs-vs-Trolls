#include "Player.h"
#include <random>
#include <ctime>

Race Player::m_race = Race::None;

// default constructor
Player::Player()
{
	m_x = 0;
	m_y = 0;
	//initPlayer();
}

// initialise player depending on which race they've chosen
void Player::initPlayer()
{
	switch (m_race)
	{
	case Race::Orc:
		m_health = 100;
		m_attack = 10;
		m_defense = 8;
		m_magic = 4;
		break;
	case Race::Troll:
		m_health = 200;
		m_attack = 6;
		m_defense = 6;
		m_magic = 10;
		break;
	default:
		break;
	}
}

int Player::attack()
{
	static std::default_random_engine randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackRoll(0, m_attack);

	return attackRoll(randomEngine);
}

// definition of player's set position func
void Player::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}

// definition for player's get position func using reference vars
void Player::getPosition(int &x, int &y)
{
	x = m_x;
	y = m_y;
}

void Player::setRace(std::string race)
{
	if (race == "orc")
	{
		Player::m_race = Race::Orc;
	}
	else if (race == "troll")
	{
		Player::m_race = Race::Troll;
	}
}

//get attack value
int Player::getAttack()
{
	return m_attack;
}
//get defense value
int Player::getDefense()
{
	return m_defense;
}
//get magic value
int Player::getMagic()
{
	return m_magic;
}
//get health value
int Player::getHealth()
{
	return m_health;
}

std::string Player::getRace()
{
	std::string type;
	switch (m_race)
	{
	case Race::Orc:
		type = "orc";
		break;
	case Race::Troll:
		type = "troll";
		break;
	default:
		break;
	}
	return type;
}