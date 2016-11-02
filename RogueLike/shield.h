#pragma once

#include "heroItem.h"

class Shield : public HeroItem
{
public:
	Shield();
	~Shield();

	std::string UseItem();
};