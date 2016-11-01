#pragma once

#include "enemyItem.h"

class Grenade : public EnemyItem
{
public:
	Grenade();
	~Grenade();

	void UseItem();
};