// RogueLike.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "inventory.h"
#include "potion.h"
#include "enemy.h"
#include "rat.h"

int main()
{
	Enemy* rat = new Rat();

	rat->SetName("Rat");

	std::cout << rat->GetName() << "\n";

	rat->SetName("Ratteke");

	std::cout << rat->GetName();

	delete rat;

	_CrtDumpMemoryLeaks();
    return 0;
}

