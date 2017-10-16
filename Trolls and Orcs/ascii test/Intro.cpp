// @author Przemyslaw Tomczyk
// @id C00218004
// @time taken ~20hours
#include "Intro.h"
#include "GameSystem.h"

Intro::Intro()
{
}

std::string Intro::lore()
{
	bool validInput = false;
	std::cout << "In a land where Orcs and Trolls have been waging wars for millennia." << std::endl
		<< "You are the promised Warleader but on which side..." << std::endl;
	system("pause");

	// keeps looping until input was valid
	while (!validInput)
	{
		std::string race;

		system("CLS");
		std::cout << "#######################################################" << std::endl;
		std::cout << "You have a choice of becoming an Orc or a Troll. " << std::endl;
		std::cout << "#######################################################" << std::endl;
		std::cout << "Orc information:" << std::endl <<
			">Orcs specialise in melee combat. In one hand they carry a sword and a shield in the other.\n>100 health points" << std::endl <<
			">Higher change to land melee attacks \n>Better chance at blocking damage when defending" << std::endl;
		std::cout << "#######################################################" << std::endl;
		std::cout << "Troll information:" << std::endl <<
			">Trolls specialise in ranged combat. They hurl massive spears at their enemies while also \nbeing skilled in the art of magic.\n>200 health points" << std::endl <<
			">Spears deal bleeding damage on enemy's turn if they hit \n>Magic attacks always hit" << std::endl;
		std::cout << "#######################################################" << std::endl;
		std::cout << "Choose your race(Orc/Troll): ";
		std::cin >> m_input;

		// turns input into lower case for easier validation
		for (int i = 0; i < m_input.length(); i++)
		{
			m_input[i] = tolower(m_input[i]);
		}

		if (m_input == "orc" || m_input == "troll")
		{
			validInput = true;
		}
		else
		{
			std::cout << "Invalid race!" << std::endl << std::flush;
			system("pause");
			std::cout << std::flush;
			system("cls");
		}
	}	
	
	system("pause");
	return m_input;
}