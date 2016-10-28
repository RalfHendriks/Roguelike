#include "stdafx.h"
#include "hero.h"

Hero::Hero() {
	level_ = 1;
	health_ = 10;
	maxHealth_ = 10;
	xp_ = 0;
	attack_ = 2;
	defence_ = 2;
}

Hero::~Hero() {
	RoomHistory.clear();
}

void Hero::IncreaseLevel()
{
	level_++;
	IncreaseAttack(1);
	IncreaseDefence(1);
	IncreaseMaxHealth(10);
	std::cout << "Congratulations! You just increased in combat! You're now level " << level_;
}

void Hero::IncreaseMaxHealth(const int & h)
{
	maxHealth_ += h;
}

void Hero::IncreaseXp(const int & exp)
{
	xp_ += exp;

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
