#include "ork.h"

Ork::Ork()
{
	SetName("Ork");
	SetLevel(3);
	SetAttack(40);
	SetAttackSequence(1);
	SetMinDamage(3);
	SetMaxDamage(7);
	SetDefence(25);
	SetHealth(10);
};

Ork::~Ork()
{
};
