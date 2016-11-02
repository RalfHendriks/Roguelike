#include "stdafx.h"
#include "dungeon.h"

Dungeon::Dungeon(int size, int dLevel)
{
	dungeon_ = std::vector<std::vector<std::vector<Room*>>>();
	GenerateDungeon(size, dLevel);
}

void Dungeon::printRoomRow(Room * room, size_t index, size_t subIndex, Hero * hero)
{
	std::string output = "";

	if (room == hero->RoomHistory.at(hero->RoomHistory.size() - 1)) {
		output.append("P");
	}
	else if (room->HasEnemies()) {
		output.append("E");
	}
	else if (room->CanGoDown() && (room->CanGoUp() || room->IsStartRoom)) {
		output.append("X");
	}
	else if (room->CanGoDown() && room->HasBeenVisited()) {
		output.append("D");
	}
	else if (room->CanGoUp() || room == startRoom_) {
		output.append("U");
	}
	else if (!room->HasBeenVisited()) {
		output.append(".");
	}
	else {
		output.append("N");
	}

	if (subIndex < dungeon_.at(hero->GetDungeonLvl()).at(index).size() - 1) {
		// Check for right
		if (room->dEast != nullptr && showConnectedRooms_) {
			output.append("-");
		}
		else {
			output.append(" ");
		}
	}
	std::cout << output;
}

void Dungeon::printPath(Room * room, size_t lvl, size_t index)
{
	std::string output = "";

	// Out of bounds check for path
	if (index < dungeon_.at(lvl).size() - 1) {
		// Check for right
		if (room->dSouth != nullptr && showConnectedRooms_) {
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
	for (size_t i = 0; i < dungeon_.at(player->GetDungeonLvl()).size(); i++) {
		for (size_t j = 0; j < dungeon_.at(player->GetDungeonLvl()).at(i).size(); j++) {
			Room * room = dungeon_.at(player->GetDungeonLvl()).at(i).at(j);
			printRoomRow(room, i, j, player);

		}
		std::cout << "\n";

		// Calculate between rooms
		for (size_t j = 0; j < dungeon_.at(player->GetDungeonLvl()).at(i).size(); j++) {
			Room* room = dungeon_.at(player->GetDungeonLvl()).at(i).at(j);
			printPath(room, player->GetDungeonLvl(), i);
		}

		if (i < dungeon_.at(player->GetDungeonLvl()).size() - 1) {
			std::cout << "\n";
		}
	}
}

void Dungeon::PrintLegend()
{
	std::cout << "Legend:\n";
	std::cout << "P    : You\n";
	std::cout << "E    : Enemy\n";
	std::cout << "N    : Room\n";
	std::cout << "D    : Stairs down\n";
	std::cout << "U    : Stairs up\n";
	std::cout << "X    : Stairs up and down\n";
	std::cout << ".    : Not yet visited\n";
	std::cout << "\n";
}

void Dungeon::SetDisplayConnectedRooms()
{
	showConnectedRooms_ = showConnectedRooms_ ? false : true;
}


Dungeon::~Dungeon()
{
	walls_.clear();
	startRoom_ = nullptr;
	for (size_t d = 0; d < dungeon_.size(); d++)
	{
		for (size_t i = 0; i < dungeon_.at(d).size(); i++) {
			for (size_t j = 0; j < dungeon_.at(d).at(i).size(); j++) {
				delete dungeon_.at(d).at(i).at(j);
			}
		}
	}

	dungeon_.clear();
	//delete startRoom_;
}

Room * Dungeon::GetStartRoom()
{
	return startRoom_;
}

Room * Dungeon::GetRandomRoom(int size)
{
	/*Room* current = nullptr;
	int rY = rand() % (size);
	int rX = rand() % (size);
	current = map_.at(rY).at(rX);
	return current;*/
	return nullptr;
}

Room * Dungeon::GetRandomRoom(int size, int lvl)
{
	Room* current = nullptr;
	int rY = rand() % (size);
	int rX = rand() % (size);
	current = dungeon_.at(lvl).at(rY).at(rX);
	return current;
}

bool Dungeon::GetDisplayConnectedRooms()
{
	return showConnectedRooms_;
}

void Dungeon::GenerateDungeon(int size,int lvl)
{
	for (int l = 0; l < lvl; l++)
	{
		dungeon_.push_back(std::vector<std::vector<Room*>>());
		for (int i = 0; i < size; i++)
		{
			dungeon_.at(l).push_back(std::vector<Room*>());
			for (int j = 0; j < size; j++)
			{
				Room* room = new Room(lvl);
				dungeon_.at(l).at(i).push_back(room);
				room->x = j;
				room->y = i;
				room->roomLvl = l;
			}
		}
	}
	Room* lastDown = nullptr;
	for (int i = 0; i < lvl; i++)
	{
		Room* current;
		walls_ = std::vector<Room*>();
		current = GetRandomRoom(size, i);

		if (lastDown != nullptr) { current->dUp = lastDown;  lastDown->dDown = current; }
		//Set stairs up
		current->algorithmChecked();
		if (i == 0) { startRoom_ = current; current->IsStartRoom = true; }
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
		lastDown = GetRandomRoom(size, i);
	}

	/*for (int i = 0; i < size; i++) {
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
	current = GetRandomRoom(size,0);

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
	GetRandomRoom(size)->canGoDown = true;*/
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
	int lvl = current->roomLvl;

	size_t North = y - 1;
	if (North >= 0 && North < dungeon_.at(lvl).size()) {
		Room* cNeighbour = dungeon_.at(lvl).at(North).at(x);
		if (cNeighbour->algorithmIsWall()) {
			walls_.push_back(cNeighbour);
			cNeighbour->algorithmIsListed();
		}
	}

	size_t east = x + 1;
	if (east >= 0 && east < dungeon_.at(lvl).size()) {
		Room* cNeighbour = dungeon_.at(lvl).at(y).at(east);
		if (cNeighbour->algorithmIsWall()) {
			walls_.push_back(cNeighbour);
			cNeighbour->algorithmIsListed();
		}
	}

	size_t south = y + 1;
	if (south >= 0 && south < dungeon_.at(lvl).size()) {
		Room* cNeighbour = dungeon_.at(lvl).at(south).at(x);
		if (cNeighbour->algorithmIsWall()) {
			walls_.push_back(cNeighbour);
			cNeighbour->algorithmIsListed();
		}
	}

	size_t west = x - 1;
	if (west >= 0 && west < dungeon_.at(lvl).size()) {
		Room* cNeighbour = dungeon_.at(lvl).at(y).at(west);
		if (cNeighbour->algorithmIsWall()) {
			walls_.push_back(cNeighbour);
			cNeighbour->algorithmIsListed();
		}
	}
}

void Dungeon::ShakeDungeon()
{
}

void Dungeon::ConnectRoom(Room * current)
{
	int x = current->x;
	int y = current->y;
	int lvl = current->roomLvl;
	bool isConnected = false;

	size_t North = y - 1;
	if (North >= 0 && North < dungeon_.at(lvl).size() && !isConnected) {
		Room * cNeighbour = dungeon_.at(lvl).at(North).at(x);
		if (cNeighbour->algorithmIsAdded()) {
			current->dNorth = cNeighbour;
			cNeighbour->dSouth = current;
			isConnected = true;
		}
	}

	size_t east = x + 1;
	if (east >= 0 && east < dungeon_.at(lvl).size() && !isConnected) {
		Room * cNeighbour = dungeon_.at(lvl).at(y).at(east);
		if (cNeighbour->algorithmIsAdded()) {
			current->dEast = cNeighbour;
			cNeighbour->dWest = current;
			isConnected = true;
		}
	}

	size_t south = y + 1;
	if (south >= 0 && south < dungeon_.at(lvl).size() && !isConnected) {
		Room * cNeighbour = dungeon_.at(lvl).at(south).at(x);
		if (cNeighbour->algorithmIsAdded()) {
			current->dSouth = cNeighbour;
			cNeighbour->dNorth = current;
			isConnected = true;
		}
	}

	size_t west = x - 1;
	if (west >= 0 && west < dungeon_.at(lvl).size() && !isConnected) {
		Room * cNeighbour = dungeon_.at(lvl).at(y).at(west);
		if (cNeighbour->algorithmIsAdded()) {
			current->dWest = cNeighbour;
			cNeighbour->dEast = current;
			isConnected = true;
		}
	}
}
