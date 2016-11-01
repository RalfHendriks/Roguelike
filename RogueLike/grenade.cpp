#include "grenade.h"

Grenade::Grenade()
{
	SetName("Grenade");
	SetDescription("40 damage against an enemy.");
};

Grenade::~Grenade()
{
};

void Grenade::UseItem()
{
	EnemyItem::UseItem();

	if(CheckIfCharacterIsSet())
		character_->LowerHealth(40);
}