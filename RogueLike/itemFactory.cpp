#include "stdafx.h"
#include "itemFactory.h"
#include "globals.h"
#include "item.h"
#include "sword.h"
#include "grenade.h"
#include "kamikaza.h"

ItemFactory::ItemFactory()
{
}

ItemFactory::~ItemFactory()
{
}

Item * ItemFactory::GetRandomItem()
{
	Item* item = nullptr;
	int random = 0 + (rand() % (int)(2 - 0 + 1));

	switch (random)
	{
	case 0:
		item = new Sword();
		break;
	case 1:
		item = new Grenade();
		break;
	case 2:
		item = new Kamikaza();
		break;
	default:
		item = new Sword();
		break;
	}
	return item;
}

