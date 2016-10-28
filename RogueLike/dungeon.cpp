#include "stdafx.h"
#include "dungeon.h"

Dungeon::Dungeon(int size, int dLevel)
{
	map_ = std::vector<std::vector<Room*>>();
	GenerateDungeon(size, dLevel);
}

void Dungeon::printRoomRow(Room * room, size_t index, size_t subIndex, Hero * hero)
{
	std::string output = "";

	if (room == hero->RoomHistory.at(hero->RoomHistory.size() - 1)) {
		output.append("P");
	}
	else if (!room->HasBeenVisited()) {
		output.append("?");
	}
	else if (room->HasEnemies()) {
		output.append("E");
	}
	else if (room->canGoDown && room->canGoUp) {
		output.append("X");
	}
	else if (room->canGoDown) {
		output.append("D");
	}
	else if (room->canGoUp) {
		output.append("U");
	}
	else {
		output.append("N");
	}

	if (subIndex < map_.at(index).size() - 1) {
		// Check for right
		if (room->dEast != nullptr) {
			output.append("-");
		}
		else {
			output.append(" ");
		}
	}
	std::cout << output;
}

void Dungeon::printPath(Room * room, size_t index)
{
	std::string output = "";

	// Out of bounds check for path
	if (index < map_.size() - 1) {
		// Check for right
		if (room->dSouth != nullptr) {
			output.append("| ");
		}
		else {
			output.append("  ");
		}
	}

	std::cout << output;
}

void Dungeon::printMap(Hero * player)
{
	for (size_t i = 0; i < map_.size(); i++) {
		for (size_t j = 0; j < map_.at(i).size(); j++) {
			Room * room = map_.at(i).at(j);
			printRoomRow(room, i, j, player);

		}
		std::cout << "\n";

		// Calculate between rooms
		for (size_t j = 0; j < map_.at(i).size(); j++) {
			Room* room = map_.at(i).at(j);
			printPath(room, i);
		}

		if (i < map_.size() - 1) {
			std::cout << "\n";
		}
	}
}

void Dungeon::PrintLegend()
{
	std::cout << "Legenda:\n";
	std::cout << "P    : You\n";
	std::cout << "|    : Path\n";
	std::cout << "E    : Enemy\n";
	std::cout << "N    : Room\n";
	std::cout << "D    : Stairs down\n";
	std::cout << "U    : Stairs up\n";
	std::cout << "X    : Stairs up and down\n";
	std::cout << "?    : Not yet visited\n";
	std::cout << "\n";
}


Dungeon::~Dungeon()
{
	walls_.clear();
	startRoom_ = nullptr;
	for (size_t i = 0; i < map_.size(); i++) {
		for (size_t j = 0; j < map_.at(i).size(); j++) {
			delete map_.at(i).at(j);
		}
	}
	map_.clear();
	//delete startRoom_;
}

Room * Dungeon::GetStartRoom()
{
	return startRoom_;
}

Room * Dungeon::GetRandomRoom(int size)
{
	Room* current = nullptr;
	int rY = rand() % (size);
	int rX = rand() % (size);
	current = map_.at(rY).at(rX);
	return current;
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

	Room* current;
	walls_ = std::vector<Room*>();
	current = GetRandomRoom(size);

	//Set stairs up
	current->canGoUp = true;
	current->algorithmChecked();
	startRoom_ = current;
	AddConnectedRooms(current);

	//start algorithm
	while (walls_.size() > 0) {
		//Get random wall
		int rLoc = rand() % (walls_.size());
		current = walls_.at(rLoc);
		//remove wall from list
		walls_.erase(walls_.begin() + rLoc);
		//add current neighbour rooms to list which aren't connected yet.
		AddConnectedRooms(current);
		//connect current room to a nearby room
		ConnectRoom(current);
		current->algorithmChecked();
	}

	//Set stairs down
	GetRandomRoom(size)->canGoDown = true;
}

void Dungeon::Print(Hero * hero)
{
	printMap(hero);
	std::cout << "\n";
}

void Dungeon::AddConnectedRooms(Room * current)
{
	int x = current->x;
	int y = current->y;

	size_t North = y - 1;
	if (North >= 0 && North < map_.size()) {
		Room* cNeighbour = map_.at(North).at(x);
		if (cNeighbour->algorithmIsWall()) {
			walls_.push_back(cNeighbour);
			cNeighbour->algorithmIsListed();
		}
	}

	size_t east = x + 1;
	if (east >= 0 && east < map_.size()) {
		Room* cNeighbour = map_.at(y).at(east);
		if (cNeighbour->algorithmIsWall()) {
			walls_.push_back(cNeighbour);
			cNeighbour->algorithmIsListed();
		}
	}

	size_t south = y + 1;
	if (south >= 0 && south < map_.size()) {
		Room* cNeighbour = map_.at(south).at(x);
		if (cNeighbour->algorithmIsWall()) {
			walls_.push_back(cNeighbour);
			cNeighbour->algorithmIsListed();
		}
	}

	size_t west = x - 1;
	if (west >= 0 && west < map_.size()) {
		Room* cNeighbour = map_.at(y).at(west);
		if (cNeighbour->algorithmIsWall()) {
			walls_.push_back(cNeighbour);
			cNeighbour->algorithmIsListed();
		}
	}
}

void Dungeon::ConnectRoom(Room * current)
{
	int x = current->x;
	int y = current->y;
	bool isConnected = false;

	size_t North = y - 1;
	if (North >= 0 && North < map_.size() && !isConnected) {
		Room * cNeighbour = map_.at(North).at(x);
		if (cNeighbour->algorithmIsAdded()) {
			current->dNorth = cNeighbour;
			cNeighbour->dSouth = current;
			isConnected = true;
		}
	}

	size_t east = x + 1;
	if (east >= 0 && east < map_.size() && !isConnected) {
		Room * cNeighbour = map_.at(y).at(east);
		if (cNeighbour->algorithmIsAdded()) {
			current->dEast = cNeighbour;
			cNeighbour->dWest = current;
			isConnected = true;
		}
	}

	size_t south = y + 1;
	if (south >= 0 && south < map_.size() && !isConnected) {
		Room * cNeighbour = map_.at(south).at(x);
		if (cNeighbour->algorithmIsAdded()) {
			current->dSouth = cNeighbour;
			cNeighbour->dNorth = current;
			isConnected = true;
		}
	}

	size_t west = x - 1;
	if (west >= 0 && west < map_.size() && !isConnected) {
		Room * cNeighbour = map_.at(y).at(west);
		if (cNeighbour->algorithmIsAdded()) {
			current->dWest = cNeighbour;
			cNeighbour->dEast = current;
			isConnected = true;
		}
	}
}
