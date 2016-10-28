// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once

#include "game.h"
#include "inventory.h"
#include "item.h"

int main()
{
	/*Game* newGame = new Game();
	newGame->Start();
	delete newGame;*/

	Inventory* inventory = new Inventory();

	Item* item = new Item();
	item->SetName("test");

	Item* item2 = new Item();
	item2->SetName("test2");

	Item* item3 = new Item();
	item3->SetName("test3");

	inventory->AddItem(item);
	inventory->AddItem(item2);
	inventory->AddItem(item3);

	inventory->RemoveItem(item);
	inventory->RemoveItem(item2);
	inventory->RemoveItem(item3);

	delete inventory;

	_CrtDumpMemoryLeaks();
    return 0;
}

