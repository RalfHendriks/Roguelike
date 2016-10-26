#include "stdafx.h"
#include "dungeon.h"

Dungeon::Dungeon(int size, int dLevel)
{
	map_ = std::vector<std::vector<Room*>>();
	GenerateDungeon(size, dLevel);
}

Dungeon::~Dungeon()
{
	for (size_t i = 0; i < map_.size(); i++) {
		for (size_t j = 0; j < map_.at(i).size(); j++) {
			delete map_.at(i).at(j);
		}
	}
}

Room * Dungeon::GetStartRoom()
{
	return nullptr;
}

void Dungeon::GenerateDungeon(int size,int lvl)
{
	for (int i = 0; i < size; i++) {
		map_.push_back(std::vector<Room*>());
		for (int j = 0; j < size; j++) {
			Room* room = new Room(lvl);
			map_.at(i).push_back(room);
			room->x = j;
			room->y = i;
		}
	}
}

void Dungeon::Print(Hero * hero)
{
}
