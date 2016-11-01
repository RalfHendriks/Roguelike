#include "stdafx.h"
#include "room.h"
#include "enemy.h"
#include "globals.h"

Room::Room(int dungeonLvl)
{
	roomLvl = dungeonLvl;
	isAdded_ = false;
	isWall_ = true;
	GenerateRoom();
}

Room::~Room()
{
	delete Monster;
}

bool Room::algorithmIsWall()
{
	return isWall_;
}

void Room::algorithmChecked()
{
	isAdded_ = true;
}

bool Room::algorithmIsAdded()
{
	return isAdded_;
}

void Room::algorithmIsListed()
{
	isWall_ = false;
}

std::string Room::GetDescription()
{
	return "A " + dirty_ + " " + size_ + " " + furniture_;
}

bool Room::HasBeenSearched()
{
	return hasBeenSearched_;
}

bool Room::HasBeenVisited()
{
	return hasBeenVisited_;
}

bool Room::HasEnemies()
{
	return Monster != nullptr ? true : false;
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

void Room::SetVisited(int lvl)
{
	AddEnemy((lvl+1));
	hasBeenVisited_ = true;
}

void Room::SetSearched()
{
	hasBeenSearched_ = true;
}

void Room::PrintPossibleMovements()
{
	if (Monster != nullptr) {
		std::cout << "These enemies are in the room: " + Monster->GetName() + "\n";

		std::cout << "\n";
		std::cout << "[Fight] Fight against " + Monster->GetName() + " \n";
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
		if (CanGoUp() || IsStartRoom) {
			std::cout << "[Up] Go up to the entrance\n";
		}
		if (CanGoDown()) {
			std::cout << "[Down] Go deeper to the monsters lair\n";
		}
		if (!hasBeenSearched_) {
			std::cout << "[Search] Look for an item in this room\n";
		}
		std::cout << "[Rest] Restores HP but monsters might find you\n";

	}
}

void Room::AddEnemy(int lvl)
{
	if (!CanGoDown() && !CanGoUp())
	{
		if (Monster == nullptr)
		{
			int chance;
			if (!hasBeenVisited_)
			{
				chance = rand() % (20);
			}
			else
			{
				chance = rand() % (3);
			}
			if (chance == 0) {
				Monster = EnemyFactory::Instance()->GetMonser(lvl);
			}
		}
	}
}

void Room::RemoveEnemy()
{
	delete Monster;
	Monster = nullptr;
}
