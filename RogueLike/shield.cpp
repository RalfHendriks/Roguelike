#include "shield.h"

Shield::Shield()
{
	SetName("Protection Shield");
	SetDescription("This shield will protect you better agains enemies and increases your defence by 10 points.");
};

Shield::~Shield()
{
};

std::string Shield::UseItem()
{
	HeroItem::UseItem();
	character_->IncreaseDefence(10);

	return "You have used a Shield and increased your defence by 10.";
}