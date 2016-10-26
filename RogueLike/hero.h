#pragma once

#include "character.h"

class Hero : public Character
{
private:
	int xp_, maxHealth_;

protected:
	Hero();
	Hero(const Hero&);
	Hero& operator= (const Hero&);

public:
	~Hero();

	static Hero* Instance()
	{
		static Hero mInstance; // Guaranteed to be destroyed. - Instantiated on first use.
		return &mInstance;
	}

	int GetExp() { return xp_; }
	int GetMaxHealth() { return maxHealth_; }

	void IncreaseLevel();
	void IncreaseXp(const int & exp);
	void IncreaseMaxHealth(const int & h);
};