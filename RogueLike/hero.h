#pragma once

class Hero
{
private:
	int level_;
	int attack_;
	int defence_;
	int xp_;
	int hp_;
	int maxhp_;
	std::string name_;

public:

	Hero(std::string name);
	~Hero();

	const int GetExp()		{ return xp_; }
	const int GetLevel()	{ return level_; }
	const int GetAttack()	{ return attack_; }
	const int GetDefence()	{ return defence_; }
	const int GetHP()		{ return hp_; }
	std::string GetName()	{ return name_; }

	void IncreaseLevel();
	void RemoveHP(int value);
	void AddHealth(int value);
	void IncreaseMaxHp(int value);
	void IncreaseXp(int value);
	void IncreaseAttack(int value);
	void IncreaseDefence(int value);
};