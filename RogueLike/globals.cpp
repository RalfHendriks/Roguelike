#include "stdafx.h"
#include "globals.h"

int Globals::Random(int max)
{
    srand(time(0) * 1000);
	return (rand() % max);
}
