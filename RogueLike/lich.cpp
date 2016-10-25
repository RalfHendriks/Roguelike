#include "lich.h"

Lich::Lich()
{
	SetName("Lich");
	SetLevel(11);
	SetAttack(90);
	SetAttackSequence(2);
	SetMinDamage(4);
	SetMaxDamage(40);
	SetDefence(60);
	SetHealth(150);
};

Lich::~Lich()
{
};
