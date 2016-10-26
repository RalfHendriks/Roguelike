#include "stdafx.h"
#include "room.h"
#include "globals.h"

Room::Room(int dungeonLvl)
{
	roomLvl = dungeonLvl;
	GenerateRoom();
}

Room::~Room()
{
	delete Enemy;
}

std::string Room::GetDescription()
{
	return "A " + dirty_ + " " + size_ + " " + furniture_;
}

bool Room::HasBeenSearched()
{
	return hasBeenSearched_;
}

void Room::GenerateRoom() {
	std::string sizes[3] { "big room", "normal room", "small room" };
	std::string dirtyness[2]{ "clean", "dirty" };
	std::string furnitures[3]{ "with a table with four chairs", "with a bed", "with nothing" };

	SetSize(sizes[Globals::Random(2)]);
	SetDirty(dirtyness[Globals::Random(1)]);
	SetFurniture(furnitures[Globals::Random(2)]);
}

void Room::SetSize(const std::string & s) {
	size_ = s;
}

void Room::SetDirty(const std::string & d) {
	dirty_ = d;
}

void Room::SetFurniture(const std::string & f) {
	furniture_ = f;
}

void Room::SetVisited()
{
	hasBeenVisited_ = true;
	AddEnemy();
}

void Room::PrintPossibleMovements()
{
	if (Enemy != nullptr) {
		std::cout << "These enemies are in the room:\n";

		std::cout << "\n";
		std::cout << "[Fight] Fight against " + Enemy->GetName() + " enemies\n";
		std::cout << "[Flee] Flee from this place like a coward!\n";
	}
	else {
		if (dWest != nullptr) {
			std::cout << "[West] Go west\n";
		}
		if (dNorth != nullptr) {
			std::cout << "[North] Go north\n";
		}
		if (dEast != nullptr) {
			std::cout << "[East] Go east\n";
		}
		if (dSouth != nullptr) {
			std::cout << "[South] Go south\n";
		}
		if (canGoUp) {
			std::cout << "[Up] Go up to the entrance\n";
		}
		if (canGoDown) {
			std::cout << "[Down] Go deeper to the monsters lair\n";
		}
		if (!hasBeenVisited_) {
			std::cout << "[Search] Look for an item in this room\n";
		}
		std::cout << "[Rest] Restores HP but monsters might find you\n";

	}
}

void Room::AddEnemy()
{
	if (!canGoDown && !canGoUp)
	{
		if (Enemy == nullptr)
		{
			int chance;
			if (!hasBeenVisited_)
			{
				chance = rand() % (3);
			}
			else
			{
				chance = rand() % (20);
			}
			if (chance != 0) {
				Enemy = new Rat();
			}
		}
	}
}
