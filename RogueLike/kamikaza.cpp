#include "kamikaza.h"

Kamikaza::Kamikaza()
{
	SetName("Kamikaza");
	SetDescription("This item will drop your health to zero.");
};

Kamikaza::~Kamikaza()
{
};

std::string Kamikaza::UseItem()
{
	HeroItem::UseItem();
	character_->SetHealth(0);

	return "You comitted suicide.";
}