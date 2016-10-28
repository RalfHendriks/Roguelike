#pragma once
#include "stdafx.h"
#include "room.h"
#include "hero.h"

class Dungeon {
private:
	std::vector<std::vector<Room*>> map_;
	std::vector<Room*> walls_;
	Room* startRoom_;

	void printRoomRow(Room* room, size_t index, size_t subIndex, Hero* player);
	void printPath(Room* room, size_t index);
	void printMap(Hero* player);

public:
	//init
	Dungeon(int size,int dLevel);
	~Dungeon();

	//Getters
	Room* GetStartRoom();
	Room* GetRandomRoom(int size);

	//Methods
	void GenerateDungeon(int size, int dLevel);
	void Print(Hero* hero);
	void AddConnectedRooms(Room* current);
	void ConnectRoom(Room* current);
	void PrintLegenda();

};