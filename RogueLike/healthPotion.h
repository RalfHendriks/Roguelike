#pragma once

#include "heroItem.h"

class HealthPotion : public HeroItem
{
public:
	HealthPotion();
	~HealthPotion();

	std::string UseItem();
};