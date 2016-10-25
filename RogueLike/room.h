#pragma once

class Room
{
	int size;
	bool dirty;
	bool furniture;

public:
	Room(int size,bool dirty,bool furniture);
	std::string GetDescription();
};