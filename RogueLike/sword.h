#pragma once

#include "heroItem.h"

class Sword : public HeroItem
{
public:
	Sword();
	~Sword();

	std::string UseItem();
};