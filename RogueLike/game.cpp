#include "game.h"
#include <iostream>

Game::Game()
{
	dungeon_ = nullptr;
	inputHandler_ = InputHandler();
}

Game::~Game()
{
	delete dungeon_;
	Hero::Instance()->~Hero();
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
		inputHandler_.setTextColor(inputHandler_.GREEN);
		dungeon_->Print(Hero::Instance());
	}
	if (Hero::Instance() != nullptr) {
		/*inputHandler_.setTextColor(inputHandler_.MAGENTA);
		Hero::Instance()->printStats();
		inputHandler_.setTextColor(inputHandler_.CYAN);
		Hero::Instance()->printItems();*/
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
		//Hero::Instance()->Prints();
	}
}

std::string Game::ExecuteAction(std::string action)
{
	std::string output = "";
	output = CanDoAction(action) + "\n";
	if (Hero::Instance()->GetHealth() < 1) {
		return output + "	Struck down by the terrors of the dungeon.\n	You lie bleeding on the ground with your body losing all color except from the blood on your skin.\n	The last thing you feel is the knawing of rats on your almost lifeless body.\n	This is the end... \n\n FIN \n\n";
	}
	return output;
}

std::string Game::CanDoAction(std::string action)
{
	if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->HasEnemies()) {
		if (action == "Fight") {
			//mGameState = GameStates::ATTACK;
			return "";
		}
		else {
			if (action == "Flee") {
				if (Hero::Instance()->RoomHistory.size() > 1) {
					Hero::Instance()->RoomHistory.pop_back();
					return "";
				}
			}
		}
	}
	else {
		if (action == "Rest") {
			Hero::Instance()->Rest();
			Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->AddEnemy();
			if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->HasEnemies())
			{
				return "You had a nightmare, you wake up seeing an enemy!";
			}
			return "You slept well, health restored by 10!";
		}
		else {
			if (action == "Search") {
				return Hero::Instance()->Search();
			}
			else {
				if (action == "West") {
					if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dWest != nullptr) {
						Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dWest);
						Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 2)->dWest->SetVisited();
						return "";
					}
				}
				else {
					if (action == "North") {
						if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dNorth != nullptr) {
							Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dNorth);
							Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 2)->dNorth->SetVisited();
							return "";
						}
					}
					else {
						if (action == "East") {
							if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dEast != nullptr) {
								Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dEast);
								Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 2)->dEast->SetVisited();
								return "";
							}
						}
						else {
							if (action == "South") {
								if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dSouth != nullptr) {
									Hero::Instance()->RoomHistory.push_back(Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->dSouth);
									Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 2)->dSouth->SetVisited();
									return "";
								}
							}
							else {
								if (action == "Up") {
									if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->canGoUp) {
										/*if (Hero::Instance()->To()) {
											setup();
											saveGame();
											return "You move back up";
										}
										else {
											return "Trying to run before you get any treasure ey? Cowards should just rot in the dungeon.";
										}*/
									}
									return "";
								}
								else {
									if (action == "Down") {
										if (Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->canGoDown) {
											/*if (Hero::Instance()->toNextDungeon()) {
												setup();
												saveGame();
											}
											return "You went further into the depths";*/
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return "You can't do this!";
}

std::string Game::PossibleActions()
{
	return ActionsForRoom();
}

std::string Game::ActionsForRoom()
{
	std::cout << Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->GetDescription() + "\n";
	Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->PrintPossibleMovements();
	return "";
}

void Game::Setup()
{
	std::cout << "* Welcome By Roguelike! \n" << "* Let's start! Please enter your name! \n";
	std::string userName;
	std::cin >> userName;

	Hero::Instance()->SetName(userName);
	std::cin.clear();
	std::cout << "* Welcome " << Hero::Instance()->GetName() << ". You're ready to start your adventure! \n";


	std::cout << "*One last thing before we can start the adventure, please enter the prefered dungeon size: \n";
	int size;
	std::cin >> size;

	dungeon_ = new Dungeon(size, 1);
	std::cin.clear();

	Hero::Instance()->RoomHistory.push_back(dungeon_->GetStartRoom());
	gameIsRunning_ = true;
}

void Game::RunGameSequence()
{
	while (gameIsRunning_)
	{
		Refresh();
		std::cout << PossibleActions();
		std::string input = "";
		std::getline(std::cin, input);
		std::string output = ExecuteAction(input);
	}
}
