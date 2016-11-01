#pragma once

#include "item.h"

class ItemFactory
{
protected:
	ItemFactory();
	ItemFactory(const ItemFactory&);
	ItemFactory& operator= (const ItemFactory&);

public:
	~ItemFactory();

	static ItemFactory* Instance()
	{
		static ItemFactory mInstance;
		return &mInstance;
	}

	Item* GetRandomItem();
};