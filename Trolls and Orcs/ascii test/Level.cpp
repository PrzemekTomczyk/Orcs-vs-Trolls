// @author Przemyslaw Tomczyk
// @id C00218004
// @time taken ~20hours
#include "Level.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <conio.h>
#include "GameSystem.h"

/// Map Legend:
/// @	= player
/// E	= Enemy
/// #	= walls
/// .	= blank space 

Level::Level()
{
	// set current state in default constructor
	m_currentState = LevelState::Move;
}

void Level::processLevel(Character*& player)
{
	// depends on the enum state, do X
	switch (m_currentState)
	{
	case LevelState::Move:
		print();
		char input;
		std::cout << "Enter a move command (w/s/a/d)(p to quit)" << std::endl;
		// grabs first character inputted by the user
		input = _getch();
		// moves player depending what the pressed
		movePlayer(input, player);
		break;
	case LevelState::Combat:
		system("CLS");
		combat(player, m_targetX, m_targetY);
		system("pause");
		m_currentState = LevelState::Move;
		break;
	default:
		break;
	}
}

// load the level
void Level::load(std::string fileName, Character*& player)
{
	// loads level
	std::fstream file;
	// opens file, if fails then closes program
	file.open(fileName);
	if (file.fail())
	{
		perror(fileName.c_str());
		system("pause");
		exit(1);
	}
	
	// pushes each line in the file down
	std::string line;

	while (std::getline(file, line))
	{
		levelData.push_back(line);
	}
	// make sure to close the file
	file.close();

	// process the level
	char tile;
	for (int i = 0; i < levelData.size(); i++)
	{
		for (int j = 0; j < levelData[i].size(); j++)
		{
			tile = levelData[i][j];

			switch (tile)
			{
			case '@':
				player->setPosition(j,i);
				break;
			case 'E':
				// for every 'E' in the file, create a new character in the vector
				m_enemies.push_back(new Character(true, player->getRace()));
				m_enemies.back()->setPosition(j, i);
			default:
				break;
			}
		}
	}
}

// function to print the level
void Level::print()
{
	system("CLS");
	for (int i = 0; i < levelData.size(); i++)
	{
		// not using cout as it causes way more flickering
		printf("%s\n", levelData[i].c_str());
	}
	printf("\n");
}

// this function handles player movement using w/s/a/d
void Level::movePlayer(char input, Character*& player)
{
	int playerX;
	int playerY;
	// passes above 2 variabesl as reference and sets them to player's actual x/y values
	player->getPosition(playerX, playerY);
	
	// depending on input, do case X
	switch (input)
	{
	case 'w': //up
	case 'W':
		// y-1 to check above player
		m_targetX = playerX;
		m_targetY = playerY - 1;
		processPlayerMove(player, m_targetX, m_targetY);
		break;
	case 's': // y+1 to check above player
	case 'S':
		m_targetX = playerX;
		m_targetY = playerY + 1;
		processPlayerMove(player, m_targetX, m_targetY);
			break;
	case 'a': // x-1 to check above player
	case 'A':
		m_targetX = playerX - 1;
		m_targetY = playerY;
		processPlayerMove(player, m_targetX, m_targetY);
			break;
	case 'd': // x+1 to check above player
	case 'D':
		m_targetX = playerX + 1;
		m_targetY = playerY;
		processPlayerMove(player, m_targetX, m_targetY);
			break;
	case 'p': // press p to exit game
	case 'P':
		// close console window
		exit(1);
		break;
	default:
		break;
	}
}

// returns game tile in the x/y pos
char Level::getTile(int x, int y)
{
	return levelData[y][x];
}

// sets tile in the x/y pos to the given char
void Level::setTile(int x, int y, char tile)
{
	levelData[y][x] = tile;
}

void Level::processPlayerMove(Character*& player, int targetX, int targetY)
{
	int playerX;
	int playerY;
	player->getPosition(playerX, playerY);
	
	char moveTile = getTile(targetX, targetY);

	switch (moveTile)
	{
	case '.':
		player->setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	case '#':
		break;
	case 'E':
		m_currentState = LevelState::Combat;
		break;
	default:
		break;
	}

}

// function to handle incomplete combat
void Level::combat(Character*& player, int targetX, int targetY)
{
	bool inCombat = true;
	bool playerTurn = true;
	int enemyX;
	int enemyY;
	// variable to hold approached enemy's index
	int approachedEnemy;
	m_enemies[0]->getPosition(enemyX, enemyY);

	// find enemy we're fighting
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->getPosition(enemyX, enemyY);
		if (targetX == enemyX && targetY == enemyY)
		{
			approachedEnemy = i;
		}
	}

		while (inCombat)
	{
		system("CLS");
		if (playerTurn)
		{
			// do player attack
			std::cout << "You're attacking!" << std::endl;
			std::cout << "hp left: " << player->getHealth() << std::endl;
			m_enemies[approachedEnemy]->takeDamage(player->getAttack());
			playerTurn = !playerTurn;
			system("pause");
		}
		else // else enemy's turn
		{
			// do enemy attack
			std::cout << m_enemies[approachedEnemy]->getRace() << " is taunting!" << std::endl;
			std::cout << "hp left: " << m_enemies[approachedEnemy]->getHealth() << std::endl;
			player->takeDamage(m_enemies[approachedEnemy]->getAttack());
			playerTurn = !playerTurn;
			system("pause");
		}

		if (player->getHealth() <= 0)
		{
			system("CLS");
			inCombat = false;
			std::cout << "You have been deaded! R.I.P [*]" << std::endl;
			system("pause");
			system("CLS");
			std::cout << "Game will now close..." << std::endl;
			system("pause");
			exit(1);
		}
		else if (m_enemies[approachedEnemy]->getHealth() <= 0)
		{
			system("CLS");
			inCombat = false;
			std::cout << "You have killed the enemy " << m_enemies[approachedEnemy]->getRace() << " " << approachedEnemy + 1 << std::endl;
			// set a tile to a dot if the enemy was killed
			setTile(targetX, targetY, '.');
		}
	}	
}