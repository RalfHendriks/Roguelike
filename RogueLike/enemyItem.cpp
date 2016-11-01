#include "stdafx.h"
#include "enemyItem.h"
#include "hero.h"

std::string EnemyItem::UseItem()
{
	SetCharacter();
	return "";
}

void EnemyItem::SetCharacter()
{
	character_ = Hero::Instance()->RoomHistory.at(Hero::Instance()->RoomHistory.size() - 1)->Monster;
}

bool EnemyItem::CheckIfCharacterIsSet()
{
	if (character_ == nullptr) {
		std::cout << "You can't use this item because there is no enemy in the room.";
		return false;
	}
	else {
		return true;
	}
}
