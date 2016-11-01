#include "stdafx.h"
#include "item.h"
#include "hero.h"

std::string Item::UseItem()
{
	return "";
}

void Item::SetName(const std::string & n)
{
	name_ = n;
}

void Item::SetDescription(const std::string & desc)
{
	description_ = desc;
}
