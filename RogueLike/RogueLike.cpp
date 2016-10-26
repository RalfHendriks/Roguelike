// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "inventory.h"
#include "potion.h"
#include "enemy.h"
#include "rat.h"
#include "room.h"


int main()
{
	Room* room = new Room();

	std::cout << room->GetDescription();

	while (true)
	{

	}

	_CrtDumpMemoryLeaks();
    return 0;
}

