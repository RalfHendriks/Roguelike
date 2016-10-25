#include "hero.h"

Hero::Hero(std::string name)
{
	name_ = name;
	level_ = 1;
	hp_ = 10;
	xp_ = 0;
	attack_ = 2;
	defence_ = 2;
}

Hero::~Hero()
{
}

void Hero::IncreaseLevel()
{
	level_ += 1;
}

void Hero::RemoveHP(int value)
{
	hp_ -= value;
}

void Hero::AddHealth(int value)
{
	hp_ += value;
	if (maxhp_ < hp_) { hp_ = maxhp_; }
}

void Hero::IncreaseMaxHp(int value)
{
	maxhp_ += value;
}

void Hero::IncreaseXp(int value)
{
	xp_ += value;

	if (level_ == 1 && xp_ > 20) {
		IncreaseLevel();
	}
	else if (level_ == 2 && xp_ > 50) {
		IncreaseLevel();
	}
	else if (level_ == 3 && xp_ > 90) {
		IncreaseLevel();
	}
	else if (level_ == 4 && xp_ > 140) {
		IncreaseLevel();
	}
	else if (level_ == 5 && xp_ > 200) {
		IncreaseLevel();
	}
	else if (level_ == 6 && xp_ > 400) {
		IncreaseLevel();
	}
	else if (level_ == 7 && xp_ > 800) {
		IncreaseLevel();
	}
	else if (level_ == 8 && xp_ > 1600) {
		IncreaseLevel();
	}
	else if (level_ == 9 && xp_ > 3200) {
		IncreaseLevel();
	}
	else if (level_ == 10 && xp_ > 6400) {
		IncreaseLevel();
	}
}

void Hero::IncreaseAttack(int value)
{
	attack_ += value;
}

void Hero::IncreaseDefence(int value)
{
	defence_ += value;
}
