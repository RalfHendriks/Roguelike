#pragma once

#include "item.h"

class HeroItem : public Item
{
public:
	void UseItem();

protected:
	Character* character_;
	virtual void SetCharacter();
};