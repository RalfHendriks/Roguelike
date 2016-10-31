#include "stdafx.h"
#include "hero.h"

Hero::Hero() {
	level_ = 1;
	health_ = 10;
	maxHealth_ = 10;
	xp_ = 0;
	attack_ = 2;
	defence_ = 2;
	dungeonLvl_ = 0;
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

void Hero::ToNextDungeon()
{
	if (dungeonLvl_ < 9) { dungeonLvl_++; }
}

bool Hero::ToPreviousDungeon()
{
	if (dungeonLvl_ > 0) { dungeonLvl_--; return true; }
	return false;
}

void Hero::PrintStats()
{
	std::cout << ("<-" + name_ + "->\n");
	std::cout << ("Level: " + std::to_string(level_) + "\n");

	if (level_ != 10) {
		std::cout << ("Experience Points: " + std::to_string(xp_) + "\n");
	}
	else {
		std::cout << ("Experience Points: MAX \n");
	}
	std::cout << ("HP: " + std::to_string(health_) + "/" + std::to_string(maxHealth_) + "\n");
	std::cout << ("Attack: " + std::to_string(attack_) + "\n");
	std::cout << ("Defence: " + std::to_string(defence_) + "\n");
}

void Hero::Rest()
{
	AddHealth(10);
	if (maxHealth_ < health_) { health_ = maxHealth_; }
}

std::string Hero::Search()
{
	Room* room = RoomHistory.at(RoomHistory.size() - 1);
	if (!room->HasBeenSearched()) {
		std::string output = "You search the room\n";
		double rValue = rand() % 10;

		if (rValue > 8 ) {
			output.append("You found something!\n");
			/*
				Input code for new found item;;
			*/
		}
		else {
			output.append("You couldn't find anything useful\n");
		}
		room->SetSearched();

		return output;
	}
	else {
		return "All that's left in this room is a pile of dust";
	}
}

std::string Hero::AttackActions()
{
	std::string output = "";
	output += "You are in a fight with:\n";

	Enemy* enemy = RoomHistory.at(RoomHistory.size() - 1)->Monster;
	output += enemy->GetName() + "(" + std::to_string(enemy->GetHealth()) + " HP)" + "\n";

	output += "\n";
	output += "[Fight] Fight against this enemy!\n";
	output += "[Flee] Flee from this fight\n";

	return output;
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
