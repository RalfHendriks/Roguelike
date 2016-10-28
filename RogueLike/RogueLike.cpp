// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once

#include "game.h"

int main()
{
	Game* newGame = new Game();
	newGame->Start();
	delete newGame;
	_CrtDumpMemoryLeaks();
    return 0;
}

