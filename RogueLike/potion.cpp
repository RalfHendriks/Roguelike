#include "potion.h"

Potion::Potion()
{
	SetName("HealthPotion");
	SetDescription("Heals 10 lifepoints");
};

Potion::~Potion()
{
};

void Potion::UseItem(Character* character) 
{
	character->AddHealth(10);
}