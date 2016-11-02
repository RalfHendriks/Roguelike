// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once
#include "game.h"
#include "itemFactory.h"
#include "enemyFactory.h"
#include <process.h>

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

	_cexit();
	_CrtDumpMemoryLeaks();
    return 0;
}