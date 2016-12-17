#pragma once

#include "room.h"
#include "character.h"
#include "inventory.h"
#include "heroSaveData.h"

class Hero : public Character
{
private:
	int xp_, maxHealth_, dungeonLvl_;
	bool showInventory_ = false;
	Inventory* inventory_;
	HeroSaveData* saveData_;

protected:
	Hero();

public:
	~Hero();
	void Destroy();
	static Hero* Instance()
	{
		static Hero mInstance;
		return &mInstance;
	}

	std::vector<Room*> RoomHistory = std::vector<Room*>();
	int GetExp()		{ return xp_; }
	int GetDungeonLvl()	{ return (dungeonLvl_ ); }
	int GetMaxHealth()	{ return maxHealth_; }



	void IncreaseMaxHealth(const int & h);
	void SetMaxHealth(const int & h);
	void SetXp(const int & exp);
	void Rest();
	std::string Save();
	bool Load();
	void ToNextDungeon();
	bool ToPreviousDungeon();
	void PrintStats();
	std::string UseItem(const int & n);
	void PrintInventory();
	void SetDisplayIventory();
	bool GetDisplayInventory() { return showInventory_; }
	std::string IncreaseXp(const int & exp);
	std::string IncreaseLevel();
	std::string Search();
	std::string AttackActions();
	std::string UseTalisman();
};