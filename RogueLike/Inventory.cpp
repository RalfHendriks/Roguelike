#include "inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::AddItem(Item * item)
{
	items_.push_back(item);
}

bool Inventory::RemoveItem(Item * item)
{
	return false;
}

std::string Inventory::GetItems()
{
	return std::string();
}
