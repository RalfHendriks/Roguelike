#pragma once

#include "item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void AddItem(Item* item);
	bool RemoveItem(Item* item);
	void PrintInventory();
	void UseItem(const int & n);

private:
	std::vector<Item*> items_;
};