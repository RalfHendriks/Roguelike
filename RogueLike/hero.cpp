#include "stdafx.h"
#include "hero.h"
#include "heroSaveData.h"

Hero::Hero() {
	level_ = 1;
	health_ = 10;
	maxHealth_ = 10;
	xp_ = 0;
	attack_ = 2;
	defence_ = 2;

	inventory_ = new Inventory();
	saveData_ = new HeroSaveData();
}

Hero::~Hero() {
	RoomHistory.clear();
	delete inventory_;
	delete saveData_;
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

void Hero::SetMaxHealth(const int & h)
{
	maxHealth_ = h;
}

void Hero::SetXp(const int & exp)
{
	xp_ = exp;
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

void Hero::Save()
{
	if(saveData_->SaveHero())
		std::cout << "You succesfully saved your hero '" << name_ << "'";
	else
		std::cout << "Oops, something went wrong while saving your hero '" << name_ << "'";
}

void Hero::Load()
{
	if(saveData_->LoadHero())
		std::cout << "You succesfully loaded your hero '" << name_ << "'";
	else
		std::cout << "Oops, something went wrong while loading your hero '" << name_ << "'";
}
