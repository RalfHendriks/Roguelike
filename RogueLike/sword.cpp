#include "sword.h"

Sword::Sword()
{
	SetName("Sword");
	SetDescription("Gives the hero 10 extra attack points.");
};

Sword::~Sword()
{
};

std::string Sword::UseItem()
{
	HeroItem::UseItem();
	character_->IncreaseAttack(10);

	return "You have used your Sword and increased your attack by 10.";
}