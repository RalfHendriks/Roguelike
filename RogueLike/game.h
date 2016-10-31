#pragma once
#include "dungeon.h"
#include "stdafx.h"
#include "hero.h"
#include "inputHandler.h"
#include "commands.h"
#include <map>

class Game {
	enum GameStates {
		Main = 0,
		Room = 1,
		Attack = 2
	};
private:
	Dungeon* dungeon_;
	InputHandler inputHandler_;
	std::map<std::string, Commands> commands_;
	bool gameIsRunning_;
	GameStates gameStatus_ = Main;
	bool legendEnabled_ = false;
	bool statsEnabled_ = false;
	bool mapEnabled_ = true;
	bool showConnectedRooms_ = true;
	void Setup();
	void RunGameSequence();

public:
	Game();
	~Game();
	void Start();
	void Refresh();
	void GetLegend();
	void GetHeroStats();
	std::string ExecuteAction(std::string action);
	std::string CanDoAction(std::string action);
	std::string PossibleActions();
	std::string ActionsForRoom();
};