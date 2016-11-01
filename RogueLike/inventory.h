#pragma once

#include "item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();
	void AddItem(Item* item);
	bool RemoveItem(Item* item);
	std::vector<Item*> GetItems();

private:
	std::vector<Item*> items_;
};