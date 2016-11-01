#pragma once

#include "heroItem.h"

class Sword : public HeroItem
{
public:
	Sword();
	~Sword();

	void UseItem();
};