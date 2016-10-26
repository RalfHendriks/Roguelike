// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Hero.h"
#include "dungeon.h"

int main()
{
	/*std::cout << "* Welcome By Roguelike! \n"
		<< "* Let's start! Please enter your name! \n";
	std::string userName;
	std::cin >> userName;

	Hero::Instance()->SetName(userName);
	std::cout << "* Welcome " << userName << ". You're ready to start your adventure! \n";
	std::cin.clear();*/

	Dungeon* d = new Dungeon(10,1);
	delete d;
	_CrtDumpMemoryLeaks();
    return 0;
}

