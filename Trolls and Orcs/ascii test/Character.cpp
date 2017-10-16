// @author Przemyslaw Tomczyk
// @id C00218004
// @time taken ~20hours
#include "Character.h"

// default constructor definition
Character::Character()
{
	m_race = "NONAME";
}

/// <summary>
/// overloaded constructor definition
/// </summary>
/// <param name="race"> takes in a string to set the enum race</param>
Character::Character(std::string race)
{
	if (race == "orc")
	{
		Character::m_Race = PlayerRace::Orc;
	}
	else if (race == "troll")
	{
		Character::m_Race = PlayerRace::Troll;
	}
	else
	{
		Character::m_Race = PlayerRace::None;
	} 
}
/// <summary>
/// this overloaded constructor is used to create enemies that the opposite race to the player
/// </summary>
/// <param name="enemy">bool to make sure an enemy has been made using this</param>
/// <param name="playerRace">player's race</param>
Character::Character(bool enemy, std::string playerRace)
{
	if (enemy == true)
	{
		// initialise as a opposite Race to the player
		if (playerRace == "orc")
		{
			Character::m_Race = PlayerRace::Troll;
			// troll stats
			m_stats.health = 140;
			m_stats.attack = 6;
			m_stats.defense = 6;
			m_stats.magic = 10;
		}
		else if (playerRace == "troll")
		{
			Character::m_Race = PlayerRace::Orc;
			// orc stats
			m_stats.health = 100;
			m_stats.attack = 10;
			m_stats.defense = 8;
			m_stats.magic = 4;
		}
	}
}
/// <summary>
/// sets/changes the race
/// </summary>
/// <param name="race">race</param>
void Character::setRace(std::string race)
{
	if (race == "orc")
	{
		Character::m_Race = PlayerRace::Orc;
	}
	else if (race == "troll")
	{
		Character::m_Race = PlayerRace::Troll;
	}
}

/// <summary>
/// sets position
/// </summary>
/// <param name="x">x coord</param>
/// <param name="y">y coord</param>
void Character::setPosition(int x, int y)
{
	m_stats.x = x;
	m_stats.y = y;
}
/// <summary>
/// takes two reference values and then sets them to the current coords
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void Character::getPosition(int & x, int & y)
{
	x = m_stats.x;
	y = m_stats.y;
}

/// <summary>
/// returns race
/// </summary>
/// <returns></returns>
std::string Character::getRace()
{
	std::string type;
	switch (m_Race)
	{
	case PlayerRace::Orc:
		type = "orc";
		break;
	case PlayerRace::Troll:
		type = "troll";
		break;
	default:
		break;
	}
	return type;
}

int Character::getAttack()
{
	return m_stats.attack;
}

int Character::getHealth()
{
	return m_stats.health;
}

/// <summary>
/// carries out an attack. Not working/used, future feature?
/// </summary>
void Character::attack()
{
	int input;
	std::cout << "Which attack type do you want to do?" << std::endl;
	std::cin >> input;
	switch (input)
	{
	case 1:
		break;
	default:
		break;
	}
}

void Character::takeDamage(int damage)
{
	m_stats.health -= damage;
}

/// <summary>
/// default constructor for orc
/// </summary>
Orc::Orc()
{
	Character::m_Race = PlayerRace::Orc;
	m_stats.health = 100;
	m_stats.attack = 10;
	m_stats.defense = 8;
	m_stats.magic = 4;

}
/// <summary>
/// overloaded constructor for orc
/// </summary>
/// <param name="name"></param>
Orc::Orc(std::string name)
{
	m_stats.health = 100;
	m_stats.attack = 10;
	m_stats.defense = 8;
	m_stats.magic = 4;
	m_stats.name = name;

}

/// <summary>
/// default constructor for troll
/// </summary>
Troll::Troll()
{
	m_stats.health = 140;
	m_stats.attack = 6;
	m_stats.defense = 6;
	m_stats.magic = 10;
	Character::m_Race = PlayerRace::Troll;
}

/// <summary>
/// overloaded constructor for troll
/// </summary>
Troll::Troll(std::string name)
{
	m_stats.health = 140;
	m_stats.attack = 6;
	m_stats.defense = 6;
	m_stats.magic = 10;
	m_stats.name = name;
}