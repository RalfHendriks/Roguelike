#include "grenade.h"

Grenade::Grenade()
{
	SetName("Grenade");
	SetDescription("40 damage against an enemy.");
};

Grenade::~Grenade()
{
};

std::string Grenade::UseItem()
{
	EnemyItem::UseItem();

	if (CheckIfCharacterIsSet()) {
		character_->LowerHealth(40);
		return "You have used a Grenade and damaged your enemy with 40 points.";
	}
}