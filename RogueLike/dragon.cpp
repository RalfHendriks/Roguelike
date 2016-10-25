#include "dragon.h"

Dragon::Dragon()
{
	SetName("Dragon");
	SetLevel(11);
	SetAttack(65);
	SetAttackSequence(4);
	SetMinDamage(3);
	SetMaxDamage(30);
	SetDefence(50);
	SetHealth(500);
};

Dragon::~Dragon()
{
};
