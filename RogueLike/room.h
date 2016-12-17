#pragma once
#include "stdafx.h"
#include "rat.h"
#include "enemyfactory.h"

class Room
{
private:
	bool hasBeenVisited_ = false;
	bool hasBeenSearched_ = false;
	bool isAdded_;
	bool isWall_;

	std::string size_;
	std::string dirty_;
	std::string furniture_;
	std::string type_;

	// Methods
	void GenerateRoom();
public:
	Room(int dungeonLvl);
	~Room();

	Room* dNorth = nullptr;
	Room* dEast = nullptr;
	Room* dSouth = nullptr;
	Room* dWest = nullptr;
	Room* dDown = nullptr;
	Room* dUp = nullptr;
	Enemy* Monster = nullptr;
	int x, y, roomLvl;
	bool IsStartRoom = false;
	bool algorithmIsWall();
	void algorithmChecked();
	bool algorithmIsAdded();
	void algorithmIsListed();
	void RemoveAlgorithmChecked();

	// Getters
	std::string GetDescription();
	bool HasBeenSearched();
	bool HasBeenVisited();
	bool HasEnemies();
	// Setters
	void SetSize(const std::string & s);
	void SetDirty(const std::string & d);
	void SetFurniture(const std::string & f);
	void SetVisited(int lvl);
	void SetSearched();
	bool CanGoDown() { return dDown == nullptr ? false : true; }
	bool CanGoUp() { return dUp == nullptr ? false : true; }

	//Methods
	void PrintPossibleMovements();
	void AddEnemy(int lvl);
	void RemoveEnemy();

};