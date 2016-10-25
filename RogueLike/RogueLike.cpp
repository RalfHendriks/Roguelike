// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "inventory.h"
#include "potion.h"

int main()
{
	Inventory* i = new Inventory();
	Potion* p = new Potion();
	i->AddItem(p);
	_CrtDumpMemoryLeaks();
    return 0;
}

