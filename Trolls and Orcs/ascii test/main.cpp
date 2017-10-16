// @author Przemyslaw Tomczyk
// @id C00218004
// @time taken ~20hours

/// @brief: Text game where you pick a side (orc/troll)
/// you then proceed to slaughter your enemies or perish
/// while doing so
/// Basic collision and combat done

#include "GameSystem.h"

int main()
{
	// create gamesystem object and pass file name
	// this file is the level
	GameSystem gameSystem("level.txt");
	gameSystem.playGame();

	system("pause");
	return 0;
}

/// <summary>
/// DONE		- 1. Orc&Troll enemies 
/// DONE		- 2. Player movement, error checking like walking into walls
/// ai not done - 3. Move orc, troll and spooders around
/// sort of		- 4. Combat menu. Has to be done using enums for states
/// fifty:fifty	- 5. Combat: melee/spells and defending/shielding 
/// dropped		- 6. Loot table. This requires inventory system/menu
/// 
/// future:
/// > save/load game
/// > level up
/// > shop?
/// > multiples levels?
/// </summary>