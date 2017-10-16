#include "Enemy.h"
#include <random>
#include <ctime>

Enemy::Enemy(std::string playerRace, char tile)
{
	if (playerRace == "orc")
	{
		m_name = "Troll";
		m_health = 200;
		m_attack = 6;
		m_defense = 6;
		m_magic = 10;
	}
	else
	{
		m_name = "Orc";
		m_health = 100;
		m_attack = 10;
		m_defense = 8;
		m_magic = 4;
	}
	m_tile = tile;
}

// definition of Enemy's set position func
void Enemy::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}

// definition for Enemy's get position func using reference vars
void Enemy::getPosition(int &x, int &y)
{
	x = m_x;
	y = m_y;
}

//get attack value
int Enemy::getAttack()
{
	return m_attack;
}
//get defense value
int Enemy::getDefense()
{
	return m_defense;
}
//get magic value
int Enemy::getMagic()
{
	return m_magic;
}
//get health value
int Enemy::getHealth()
{
	return m_health;
}

std::string Enemy::getRace()
{
	return std::string(m_name);
}

void Enemy::takeDamage(int damage)
{
	m_health -= damage;
}