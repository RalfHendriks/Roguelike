#include "rat.h"

Rat::Rat()
{
	SetName("Rat");
	SetLevel(1);
	SetAttack(20);
	SetAttackSequence(1);
	SetMinDamage(1);
	SetMaxDamage(2);
	SetDefence(20);
	SetHealth(2);
};

Rat::~Rat()
{
};
