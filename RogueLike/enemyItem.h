#pragma once

#include "item.h"

class EnemyItem : public Item
{
public:
	std::string UseItem();

protected:
	Character* character_;
	virtual void SetCharacter();
	bool CheckIfCharacterIsSet();
};