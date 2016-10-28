#include "inventory.h"
#include <algorithm>

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < items_.size(); i++) {
		delete items_.at(i);
	}
	items_.clear();
}

void Inventory::AddItem(Item * item)
{
	items_.push_back(item);
}

bool Inventory::RemoveItem(Item * item)
{
	items_.erase(std::remove(items_.begin(), items_.end(), item), items_.end());
	delete item;
	return true;
}

std::vector<Item*> Inventory::GetItems()
{
	return items_;
}
