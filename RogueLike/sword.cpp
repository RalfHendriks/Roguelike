#include "sword.h"

Sword::Sword()
{
	SetName("Sword");
	SetDescription("Gives the hero 10 extra attack points.");
};

Sword::~Sword()
{
};

void Sword::UseItem()
{
	HeroItem::UseItem();
	character_->IncreaseAttack(10);
}