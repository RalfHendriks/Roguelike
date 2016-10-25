#include "goblin.h"

Goblin::Goblin()
{
	SetName("Goblin");
	SetLevel(2);
	SetAttack(30);
	SetAttackSequence(1);
	SetMinDamage(1);
	SetMaxDamage(5);
	SetDefence(20);
	SetHealth(5);
};

Goblin::~Goblin()
{
};
