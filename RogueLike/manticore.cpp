#include "manticore.h"

Manticore::Manticore()
{
	SetName("Manticore");
	SetLevel(8);
	SetAttack(45);
	SetAttackSequence(3);
	SetMinDamage(2);
	SetMaxDamage(20);
	SetDefence(45);
	SetHealth(120);
};

Manticore::~Manticore()
{
};
