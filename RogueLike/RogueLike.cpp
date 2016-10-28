// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Hero.h"
#include "dungeon.h"
#include "character.h"
#include "spider.h"
#include "enemyFactory.h"

int main()
{
	/*std::cout << "* Welcome By Roguelike! \n"
		<< "* Let's start! Please enter your name! \n";
	std::string userName;
	std::cin >> userName;

	Hero::Instance()->SetName(userName);
	std::cout << "* Welcome " << userName << ". You're ready to start your adventure! \n";
	std::cin.clear();

	std::cout << "*One last thing before we can start the adventure, please enter the prefered dungeon size: \n";
	int size;
	std::cin >> size;

	Dungeon* d = new Dungeon(10,1);
	Hero::Instance()->RoomHistory.push_back(d->GetStartRoom());
	d->Print(Hero::Instance());

	Hero::Instance()->~Hero();
	delete d;*/
	
	Enemy* enemy = EnemyFactory::Instance()->GetMonser(1);
	EnemyFactory::Instance()->~EnemyFactory();

	delete enemy;

	_CrtDumpMemoryLeaks();
    return 0;
}

