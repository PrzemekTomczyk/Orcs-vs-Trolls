#pragma once
#include <iostream>
#include <string>

enum class 
	Race
{
	None,
	Orc,
	Troll
};

class Player
{
public:
	Player();

	// initialize function
	void initPlayer();

	int attack();

	// setters
	void setPosition(int x, int y);
	void setRace(std::string race);

	// getters
	void getPosition(int &x, int &y);
	int getAttack();
	int getDefense();
	int getMagic();
	int getHealth();
	std::string getRace();

private:
	// properties
	int m_x;
	int m_y;
	int m_health;
	// number for attack roll (lower=better chance to hit)
	int m_attack;
	int m_defense;
	int m_magic;
	static Race m_race;

};

