#pragma once
#include "stdafx.h"
#include "room.h"
#include "hero.h"

class Dungeon {
private:
	std::vector<std::vector<std::vector<Room*>>> dungeon_;
	std::vector<Room*> walls_;
	Room* startRoom_;
	bool showConnectedRooms_ = true;

	void printRoomRow(Room* room, size_t index, size_t subIndex, Hero* player);
	void printPath(Room* room, size_t lvl, size_t index);
	void printMap(Hero* player);

public:
	//init
	Dungeon(int size,int dLevel);
	~Dungeon();

	//Getters
	Room* GetStartRoom();
	Room* GetRandomRoom(int size);
	Room* GetRandomRoom(int size, int lvl);
	bool GetDisplayConnectedRooms();

	//Methods
	void GenerateDungeon(int size, int dLevel);
	void Print(Hero* hero);
	void AddConnectedRooms(Room* current);
	void ShakeDungeon();
	void ConnectRoom(Room* current);
	void PrintLegend();
	void SetDisplayConnectedRooms();
};