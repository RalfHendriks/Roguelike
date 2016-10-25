#include "stdafx.h"
#include "room.h"

Room::Room(int s, bool d, bool f)
{
	size = s;
	dirty = d;
	furniture = f;
}

std::string Room::GetDescription()
{
	return std::string();
}
