#pragma once
#include "dungeon.h"
#include "stdafx.h"
#include "hero.h"
#include "inputHandler.h"

class Game {
private:
	Dungeon* dungeon_;
	InputHandler inputHandler_;
	bool gameIsRunning_;
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