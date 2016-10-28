#pragma once

#include "room.h"

class Hero
{
private:
	int level_;
	int attack_;
	int defence_;
	int xp_;
	int hp_;
	int maxhp_;

protected:
	Hero();
	Hero(const Hero&);
	Hero& operator= (const Hero&);

public:
	std::string Name;

	~Hero();

	static Hero* Instance()
	{
		static Hero mInstance; // Guaranteed to be destroyed. - Instantiated on first use.
		return &mInstance;
	}

	std::vector<Room*> RoomHistory = std::vector<Room*>();
	const int GetExp()		{ return xp_; }
	const int GetLevel()	{ return level_; }
	const int GetAttack()	{ return attack_; }
	const int GetDefence()	{ return defence_; }
	const int GetHP()		{ return hp_; }

	void IncreaseLevel();
	void RemoveHP(int value);
	void AddHealth(int value);
	void IncreaseMaxHp(int value);
	void IncreaseXp(int value);
	void IncreaseAttack(int value);
	void IncreaseDefence(int value);
	void SetName(std::string value);
};