#pragma once
#include "stdafx.h"
#include "room.h"
#include "hero.h"

class Dungeon {
private:
	std::vector<std::vector<Room*>> map_;

public:
	//init
	Dungeon(int size,int dLevel);
	~Dungeon();

	//Getters
	Room* GetStartRoom();

	//Methods
	void GenerateDungeon(int size, int dLevel);
	void Print(Hero* hero);

};