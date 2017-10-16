#pragma once
// @author Przemyslaw Tomczyk
// @id C00218004
// @time taken ~20hours

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h> 

// enum used to check player race in a switch statement
enum class PlayerRace
{
	None,
	Orc,
	Troll
};

// struct that holds all variables used by characters
typedef struct Statistics
{
	int health;
	int attack;
	int defense;
	int magic;
	int x;
	int y;
	std::string name;
}Stats;

// abstract class that orcs and trolls inherit from
class Character
{
public:
	// default constructor
	Character();
	// overloaded contructor
	Character(std::string race);
	// constructor for enemies
	Character(bool enemy, std::string playerRace);
	// setters
	virtual void setRace(std::string race); // takes in a string to set the race
	virtual void setPosition(int x, int y);
	// getters
	virtual void getPosition(int &x, int &y); // pass x&y by reference
	// returns character's race as a string
	virtual std::string getRace();
	// returns attack
	virtual int getAttack();
	// returns health
	virtual int getHealth();

	// function used for attacks
	virtual void attack();
	// fucntion used to deal/take damage
	virtual void takeDamage(int damage);

	// protected variables so they can be access by inherited classes
protected:
	std::string m_race;
	// create struct
	Stats m_stats;
	PlayerRace m_Race;
};

// Orc class that inherits from the Character class
class Orc : public Character
{
public:
	// default constructor
	Orc();
	// overloaded constructor
	Orc(std::string race);
	
	//void attack();
	//void takeDamage();
	};


// Troll class that inherits from the Character class
class Troll : public Character
{
public:
	// default constructor
	Troll();
	// overloaded constructor
	Troll(std::string race);

	//void attack();
	//void takeDamage();
};

