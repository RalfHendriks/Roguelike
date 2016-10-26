#include "stdafx.h"
#include "room.h"
#include "globals.h"

Room::Room()
{
	GenerateRoom();
}

std::string Room::GetDescription()
{
	return "A " + dirty_ + " " + size_ + " " + furniture_;
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
