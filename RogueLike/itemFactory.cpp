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
	int random = 0 + (rand() % (int)(1 - 0 + 1));

	switch (random)
	{
	case 0:
		item = new Kamikaza();
		break;
	case 1:
		item = new Kamikaza();
		break;
	default:
		item = new Kamikaza();
		break;
	}
	return item;
}

