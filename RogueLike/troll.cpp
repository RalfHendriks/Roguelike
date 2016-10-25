#include "troll.h"

Troll::Troll()
{
	SetName("Troll");
	SetLevel(6);
	SetAttack(30);
	SetAttackSequence(1);
	SetMinDamage(3);
	SetMaxDamage(30);
	SetDefence(20);
	SetHealth(100);
};

Troll::~Troll()
{
};
