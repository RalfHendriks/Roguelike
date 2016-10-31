// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once
#include "game.h"

int main()
{
	Game* game = new Game();
	try
	{
		game->Start();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what();
	}
	delete game;
	_CrtDumpMemoryLeaks();
    return 0;
}

