#pragma once

#include "item.h"

class HeroItem : public Item
{
public:
	std::string UseItem();

protected:
	Character* character_;
	virtual void SetCharacter();
};