#pragma once

#include "heroItem.h"

class Kamikaza : public HeroItem
{
public:
	Kamikaza();
	~Kamikaza();

	std::string UseItem();
};