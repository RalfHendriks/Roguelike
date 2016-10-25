#include "golem.h"

Golem::Golem()
{
	SetName("Golem");
	SetLevel(9);
	SetAttack(50);
	SetAttackSequence(2);
	SetMinDamage(5);
	SetMaxDamage(50);
	SetDefence(20);
	SetHealth(300);
};

Golem::~Golem()
{
};
