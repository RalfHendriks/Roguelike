#include "game.h"
#include <iostream>

Game::Game()
{
	dungeon_ = nullptr;
	inputHandler_ = InputHandler();
	Hero::Instance();
	EnemyFactory::Instance();
	commands_ = std::map<std::string, Commands>();
	commands_.insert(std::make_pair("North", Commands::North));
	commands_.insert(std::make_pair("East", Commands::East));
	commands_.insert(std::make_pair("South", Commands::South));
	commands_.insert(std::make_pair("West", Commands::West));
	commands_.insert(std::make_pair("Fight", Commands::Fight));
	commands_.insert(std::make_pair("Flee", Commands::Flee));
	commands_.insert(std::make_pair("Search", Commands::Search));
	commands_.insert(std::make_pair("Stats", Commands::Stats));
	commands_.insert(std::make_pair("Down", Commands::Down));
	commands_.insert(std::make_pair("Up", Commands::Up));
	commands_.insert(std::make_pair("Legend", Commands::Legend));
	commands_.insert(std::make_pair("Rest", Commands::Rest));
	commands_.insert(std::make_pair("Map", Commands::Map));
	commands_.insert(std::make_pair("ShowConnectedRooms", Commands::ShowConnectedRooms));
	commands_.insert(std::make_pair("Talisman", Commands::Talisman));
	commands_.insert(std::make_pair("Inventory", Commands::Inventory));
	commands_.insert(std::make_pair("Use", Commands::Use));
	commands_.insert(std::make_pair("Save", Commands::Save));
}

Game::~Game()
{
	delete dungeon_;
	commands_.clear();
	Hero::Instance()->Destroy();
	EnemyFactory::Instance()->Destroy();
}

void Game::Start()
{
	Setup();
	RunGameSequence();
}

void Game::Refresh()
{
	inputHandler_.handleInput("CLEAR");
	if (dungeon_ != nullptr) {
		if (mapEnabled_)
		{
			inputHandler_.setTextColor(inputHandler_.GREEN);
			dungeon_->Print(Hero::Instance());
		}
		if (legendEnabled_) {
			inputHandler_.setTextColor(inputHandler_.CYAN);
			GetLegend();
		}
	}
	if (Hero::Instance() != nullptr) {
		if (statsEnabled_)
		{
			GetHeroStats();
		}
		if (Hero::Instance()->GetDisplayInventory())
		{
			inputHandler_.setTextColor(inputHandler_.CYAN);
			Hero::Instance()->PrintInventory();
		}

	}
	inputHandler_.setTextColor(inputHandler_.WHITE);
}

void Game::GetLegend()
{
	if (dungeon_ != nullptr) {
		inputHandler_.setTextColor(inputHandler_.YELLOW);
		dungeon_->PrintLegend();
	}
}

void Game::GetHeroStats()
{
	if (Hero::Instance() != nullptr) {
		inputHandler_.setTextColor(inputHandler_.MAGENTA);
		Hero::Instance()->PrintStats();
	}
}

std::string Game::ExecuteAction(std::string action)
{
	std::string output = "";
	if (action != "")
	{
		output = CanDoAction(action) + "\n";
		if (Hero::Instance()->GetHealth() < 1) {
			gameIsRunning_ = false;
			return output + "	Struck down by the terrors of the dungeon.\n	You lie bleeding on the ground with your body losing all color except from the blood on your skin.\n	The last thing you feel is the knawing of rats on your almost lifeless body.\n	This is the end... \n\n FIN \n\n";
		}
	}
	return output;
}

std::string Game::CanDoAction(std::string action)
{
	Commands command = commands_[action];

	//Check for Violent actions
	if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->HasEnemies()) {
		if (command == Commands::Fight)
		{
			Enemy* enemy = Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->Monster;
			std::string attackMessage;
			attackMessage = Hero::Instance()->Attack(enemy);
			if (enemy->GetHealth() < 1 && enemy->GetLevel() == 11) {
				gameIsRunning_ = false;
				return "	With a mighty swing you strike down your final opponent.\n	It was a long journey into depths of almost hell itself!\n	But you succeeded where others did not!\n	Covered in blood, dust and the entrails of foes slain.\n	You walk the final hall towards your prize to secumb to it's glory.\n	This is, the end. \n\n FIN";
			}
			if (enemy->GetHealth() < 1) {
				std::string lvlMessage = Hero::Instance()->IncreaseXp((enemy->GetLevel() * 20));
				Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->RemoveEnemy();
				return attackMessage + lvlMessage +"You've defeaten all enemies here!";
			}
			return attackMessage + AttackHero();
		}
		else if (command == Commands::Flee)
		{
			if (Hero::Instance()->RoomHistory.size() > 1) {
				Hero::Instance()->RoomHistory.pop_back();
				return "";
			}
		}
	}
	else
	{
		//Check for passive actions
		switch (command)
		{
		case Commands::North:
			if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dNorth != nullptr) {
				Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dNorth);
				Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 2)->dNorth->SetVisited(Hero::Instance()->GetDungeonLvl());
				return "";
			}
			break;
		case Commands::East:
			if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dEast != nullptr) {
				Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dEast);
				Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 2)->dEast->SetVisited(Hero::Instance()->GetDungeonLvl());
				return "";
			}
			break;
		case Commands::South:
			if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dSouth != nullptr) {
				Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dSouth);
				Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 2)->dSouth->SetVisited(Hero::Instance()->GetDungeonLvl());
				return "";
			}
			break;
		case Commands::West:
			if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dWest != nullptr) {
				Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dWest);
				Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 2)->dWest->SetVisited(Hero::Instance()->GetDungeonLvl());
				return "";
			}
			break;
		case Commands::Up:
			if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->CanGoUp() || Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->IsStartRoom) {
				if (Hero::Instance()->ToPreviousDungeon())
				{
					Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dUp);
					return "You move back up";
				}
				return "Trying to run before you get any treasure ey? Cowards should just rot in the dungeon.";
			}
			return "";
			break;
		case Commands::Down:
			if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->CanGoDown()) {
				Hero::Instance()->ToNextDungeon();
				Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dDown);
				return "You went further into the depths";
			}
			return "";
			break;
		case Commands::Rest:
			Hero::Instance()->Rest();
			Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->AddEnemy((Hero::Instance()->GetDungeonLvl()+1));
			if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->HasEnemies())
			{
				return "You had a nightmare, you wake up seeing an enemy!";
			}
			return "You slept well, health restored by 10!";
			break;
		case Commands::Search:
			return Hero::Instance()->Search();
			break;
		case Commands::Talisman:
			return Hero::Instance()->UseTalisman();
			break;
		}
	}

	//check for interface commands
	switch (command)
	{
	case Commands::Legend:
		legendEnabled_ = legendEnabled_ ? false : true;
		return "";
		break;
	case Commands::Stats:
		statsEnabled_ = statsEnabled_ ? false : true;
		return "";
		break;
	case Commands::Map:
		mapEnabled_ = mapEnabled_ ? false : true;
		return "";
		break;
	case Commands::ShowConnectedRooms:
		dungeon_->SetDisplayConnectedRooms();
		return "";
		break;
	case Commands::Inventory:
		Hero::Instance()->SetDisplayIventory();
		return "";
		break;
	case Commands::Save:
		return Hero::Instance()->Save();
		break;
	case Commands::Use:
		std::string input;
		Hero::Instance()->PrintInventory();
		std::cout << "\n Which item do you want to use? Please enter the position in the inventory: ";
		std::cin >> input;
		std::string message = Hero::Instance()->UseItem(std::stoi(input));
		return message;
		break;
	}
	return "Invalid Command!";
}

std::string Game::PossibleActions()
{
	return ActionsForRoom();
}

std::string Game::ActionsForRoom()
{
	std::cout << "Description: "+ Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->GetDescription() + "\n";
	Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->PrintPossibleMovements();
	return "";
}

std::string Game::AttackHero()
{
	Hero * hero = Hero::Instance();
	std::string s = Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->Monster->Attack(hero);
	return s;
}

void Game::Setup()
{
	std::cout << "* Welcome By Roguelike! \n";
	std::cout << "* Would you like to open a previous save?(y/n) \n";
	std::string tLoad;
	std::cin >> tLoad;
	if(tLoad == "y" && Hero::Instance()->Load())
	{
		// Silence is golden
	}
	else
	{
		std::cout << "* Let's start! Please enter your name! \n";
		std::string userName;
		std::cin >> userName;

		Hero::Instance()->SetName(userName);
		std::cin.clear();
		std::cout << "* Welcome " << Hero::Instance()->GetName() << ". You're ready to start your adventure! \n";

	}

	std::cout << "*One last thing before we can start the adventure, please enter the prefered dungeon size: \n";
	int size;
	std::cin >> size;

	dungeon_ = new Dungeon(size, 10);
	std::cin.clear();

	Hero::Instance()->RoomHistory.push_back(dungeon_->GetStartRoom());
	gameIsRunning_ = true;
	Refresh();
}

void Game::RunGameSequence()
{
	while (gameIsRunning_)
	{
		std::cout << PossibleActions();
		std::string input = "";
		std::cin >> input;
		//std::getline(std::cin, input);
		std::string output = ExecuteAction(input);
		Refresh();
		std::cout << output;
		std::cin.clear();
	}
}
