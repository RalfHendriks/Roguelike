#pragma once

#include "character.h"

class Item
{
public:
	Item();
	~Item();

	virtual void UseItem(Character* character);
	void SetName(const std::string & n);
	void SetDescription(const std::string & desc);
	std::string GetDescription() { return description_; }
	std::string GetName() { return name_; }

protected:
	std::string name_;
	std::string description_;
};