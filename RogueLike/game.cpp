#include "game.h"

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
		inputHandler_.setTextColor(inputHandler_.YELLOW);
		dungeon_->PrintLegenda();
	}
	if (Hero::Instance() != nullptr) {
		/*inputHandler_.setTextColor(inputHandler_.MAGENTA);
		Hero::Instance()->printStats();
		inputHandler_.setTextColor(inputHandler_.CYAN);
		Hero::Instance()->printItems();*/
	}
	inputHandler_.setTextColor(inputHandler_.WHITE);
}

std::string Game::ExecuteAction(std::string action)
{
	return std::string();
}

std::string Game::CanDoAction(std::string action)
{
	return std::string();
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
		std::string input;
		std::cin >> input;
		std::cin.clear();
		Refresh();
	}
}
