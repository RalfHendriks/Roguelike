#pragma once

#include "room.h"
#include "character.h"
#include "inventory.h"
#include "heroSaveData.h"

class Hero : public Character
{
private:
	int xp_, maxHealth_;
	Inventory* inventory_;
	HeroSaveData* saveData_;

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

	std::vector<Room*> RoomHistory = std::vector<Room*>();
	const int GetExp()		{ return xp_; }
	int GetMaxHealth() { return maxHealth_; }

	void IncreaseLevel();
	void IncreaseXp(const int & exp);
	void IncreaseMaxHealth(const int & h);
	void SetMaxHealth(const int & h);
	void SetXp(const int & exp);
	void Rest();
	std::string Search();
	void Save();
	void Load();
};