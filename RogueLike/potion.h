#pragma once

#include "item.h"

class Potion: public Item
{
public:
	Potion();
	~Potion();

	void UseItem(Character * character);
};