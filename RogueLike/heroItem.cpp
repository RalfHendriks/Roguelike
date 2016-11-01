#include "stdafx.h"
#include "heroItem.h"
#include "hero.h"

void HeroItem::UseItem()
{
	SetCharacter();
}

void HeroItem::SetCharacter()
{
	character_ = Hero::Instance();
}
