// @author Przemyslaw Tomczyk
// @id C00218004
// @time taken ~20hours
#pragma once
#include <string>

#include "Level.h"
#include "Intro.h"
#include "Character.h"

class GameSystem
{
public:
	GameSystem(std::string levelFile);

	// function that runs the game
	void playGame();
	// initialises player character
	void initialise();

private:
	Intro m_intro;

	Character* m_player;
	Orc orc;
	Troll troll;

	Level m_level;

};

