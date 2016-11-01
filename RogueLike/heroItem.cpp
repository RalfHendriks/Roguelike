#include "stdafx.h"
#include "heroItem.h"
#include "hero.h"

std::string HeroItem::UseItem()
{
	SetCharacter();
	return "";
}

void HeroItem::SetCharacter()
{
	character_ = Hero::Instance();
}
