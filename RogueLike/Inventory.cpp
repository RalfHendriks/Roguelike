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
	// Todo: Check if item is in list
	items_.erase(std::remove(items_.begin(), items_.end(), item), items_.end());
	delete item;
	return true;
}

void Inventory::PrintInventory()
{
	std::cout << "Inventory:\n";

	for (size_t i = 0; i < items_.size(); i++) {
		std::cout << "[" << i << "] " << items_.at(i)->GetName() << "\t : " << items_.at(i)->GetDescription() << "\n";
	}

	std::cout << "\n";
}

std::string Inventory::UseItem(const int & n)
{
	if (n < items_.size()) {
		// Todo: check if item exists
		Item* item = items_.at(n);
		std::string output = item->UseItem();
		RemoveItem(item);
		return output;
	}
	else {
		return "Sorry, you can't use the item on index " + std::to_string(n) + " because it doesn't exists.\n";
	}
}


