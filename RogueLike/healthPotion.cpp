#include "healthPotion.h"

HealthPotion::HealthPotion()
{
	SetName("Health Potion");
	SetDescription("Gives the hero 10 extra health points.");
};

HealthPotion::~HealthPotion()
{
};

std::string HealthPotion::UseItem()
{
	HeroItem::UseItem();
	character_->AddHealth(10);

	return "You have used a Health Potion and increased your health by 10.";
}