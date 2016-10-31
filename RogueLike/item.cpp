#include "stdafx.h"
#include "item.h"

Item::Item()
{
}

Item::~Item()
{
}

void Item::UseItem(Character* character)
{
}

void Item::SetName(const std::string & n)
{
	name_ = n;
}

void Item::SetDescription(const std::string & desc)
{
	description_ = desc;
}
