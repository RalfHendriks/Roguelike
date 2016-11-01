// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once
#include "game.h"

#include "test.h"

int main()
{
	/*Game* game = new Game();
	try
	{
		game->Start();
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what();
	}
	delete game;*/

	Hero::Instance();

	Test* test = new Test();

	delete test;

	_CrtDumpMemoryLeaks();
    return 0;
}