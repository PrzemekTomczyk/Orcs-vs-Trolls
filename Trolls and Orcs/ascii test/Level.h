// @author Przemyslaw Tomczyk
// @id C00218004
// @time taken ~20hours
#pragma once
#include <vector>
#include <string>
#include "Character.h"

/// <summary>
/// enem class to flick between combat screen and map view
/// </summary>
enum class 
	LevelState
{
	Move,
	Combat
};

class Level
{
public:
	Level();

	/// <summary>
	/// process' level
	/// </summary>
	/// <param name="player">player reference</param>
	void processLevel(Character*& player);

	/// <summary>
	/// loads level from file
	/// </summary>
	/// <param name="fileName">file name</param>
	/// <param name="player">player reference</param>
	void load(std::string fileName, Character*& player);
	/// <summary>
	/// prints the level
	/// </summary>
	void print();
	/// <summary>
	/// moves player
	/// </summary>
	/// <param name="input">character grabbed from the keyboard</param>
	/// <param name="player">player reference</param>
	void movePlayer(char input, Character*& player);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="player">player reference</param>
	/// <param name="targetX">targetX=the field where player is trying to move into</param>
	/// <param name="targetY">targetY=the field where player is trying to move into</param>
	void combat(Character*& player, int targetX, int targetY);

	// getters
	char getTile(int x, int y);
	// setters
	void setTile(int x, int y, char tile);

private:
	/// <summary>
	/// handles collisions etc
	/// </summary>
	/// <param name="player">player reference</param>
	/// <param name="targetX"></param>
	/// <param name="targetY"></param>
	void processPlayerMove(Character*& player, int targetX, int targetY);
	int m_targetX;
	int m_targetY;

	LevelState m_currentState;

	std::vector <std::string> levelData;
	/// <summary>
	/// holds character pointer as a vector
	/// </summary>
	std::vector <Character*> m_enemies;
	Orc orc;
	Troll troll;

};

