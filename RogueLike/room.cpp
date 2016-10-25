#include "stdafx.h"
#include "room.h"

Room::Room()
{
}

std::string Room::GetDescription()
{
	return std::string();
}

void Room::GenerateRoom() {
	std::string sizes[3] { "big room", "normal room", "small room" };
	std::string dirtyness[2]{ "clean", "dirty" };
	std::string furnitures[3]{ "with a table with four chairs", "with a bed", "with nothing" };

	SetSize(sizes[1]);
	SetDirty(dirtyness[1]);
	SetFurniture(furnitures[1]);
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
