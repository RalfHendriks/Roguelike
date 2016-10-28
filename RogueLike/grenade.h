#pragma once

#include "item.h"

class Grenade : public Item
{
public:
	Grenade();
	~Grenade();

	void UseItem(Character * character);
};