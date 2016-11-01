#pragma once

#include "item.h"

class EnemyItem : public Item
{
public:
	void UseItem();

protected:
	Character* character_;
	virtual void SetCharacter();
	bool CheckIfCharacterIsSet();
};