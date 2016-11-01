#include "kamikaza.h"

Kamikaza::Kamikaza()
{
	SetName("Kamikaza");
	SetDescription("It wouldn't be smart to use this item... it will kill your hero.");
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