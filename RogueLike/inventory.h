#pragma once

#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	void AddItem(Item* item);
	bool RemoveItem(Item* item);
	std::string GetItems();

private:
	std::vector<Item*> items_;
};