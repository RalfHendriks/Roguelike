#pragma once
#include "dungeon.h"
#include "stdafx.h"
#include "hero.h"
#include "inputHandler.h"
#include "commands.h"
#include <map>

class Game {
	enum GameStates {
		Peacefully = 0,
		Violent = 1
	};
private:
	Dungeon* dungeon_;
	InputHandler inputHandler_;
	std::map<std::string, Commands> commands_;
	GameStates currentGameState_ = GameStates::Peacefully;
	bool gameIsRunning_;
	bool legendEnabled_ = false;
	bool statsEnabled_ = false;
	bool mapEnabled_ = true;
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
	std::string AttackHero();
};