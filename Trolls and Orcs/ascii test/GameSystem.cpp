// @author Przemyslaw Tomczyk
// @id C00218004
// @time taken ~20hours
#include "GameSystem.h"
#include <iostream>
#include <conio.h>

// this contstructor is used to set up the game (player, load level etc)
GameSystem::GameSystem(std::string levelFileName)
{
	initialise();
	m_level.load(levelFileName, m_player);
	system("CLS");
}

void GameSystem::playGame()
{
	bool isDone = false;

	while (!isDone)
	{
		m_level.processLevel(m_player);
	}
}

void GameSystem::initialise()
{
	if (m_intro.lore() == "orc")
	{
		system("CLS");
		m_player = &orc;
		m_player->getRace();
	}
	else
	{
		system("CLS");
		m_player = &troll;
		m_player->getRace();
	}
//	system("pause");
//	system("CLS");
}