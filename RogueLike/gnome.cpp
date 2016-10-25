#include "gnome.h"

Gnome::Gnome()
{
	SetName("Gnome");
	SetLevel(1);
	SetAttack(30);
	SetAttackSequence(1);
	SetMinDamage(0);
	SetMaxDamage(3);
	SetDefence(10);
	SetHealth(3);
};

Gnome::~Gnome()
{
};
