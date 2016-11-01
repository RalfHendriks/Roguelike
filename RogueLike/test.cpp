#include "test.h"
#include "inventory.h"
#include "sword.h"
#include "grenade.h"
#include "itemFactory.h"
#include "hero.h"

Test::Test() 
{
	Inventory* inventory = new Inventory();
	ItemFactory* fac = ItemFactory::Instance();
	Item* item1 = fac->GetRandomItem();
	Item* item2 = fac->GetRandomItem();

	inventory->AddItem(item1);
	inventory->AddItem(item2);

	Hero* hero = Hero::Instance();
	
	//inventory->UseItem(0);

	inventory->PrintInventory();

	delete inventory;

	std::string test;
	std::cin >> test;
	
}

Test::~Test() 
{

}