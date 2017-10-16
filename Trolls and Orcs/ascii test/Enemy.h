#pragma once
#include <string>
class Enemy
{
public:
	Enemy(std::string playerRace, char tile);
	// setters
	void setPosition(int x, int y);
	// getters
	void getPosition(int &x, int &y);
	int getAttack();
	int getDefense();
	int getMagic();
	int getHealth();
	std::string getRace();
	
	void takeDamage(int damage);

private:
	std::string m_name;
	char m_tile;
	int m_attack;
	int m_defense;
	int m_health;
	int m_magic;
	int m_x;
	int m_y;


};

