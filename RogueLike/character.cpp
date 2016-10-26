#include "stdafx.h"
#include "character.h"

Character::Character()
{
}

Character::~Character()
{
}

void Character::SetName(const std::string & n)
{
	name_ = n;
}

void Character::SetLevel(const int & lvl)
{
	level_ = lvl;
}

void Character::SetAttack(const int & att) {
	attack_ = att;
}

void Character::SetDefence(const int & def) {
	defence_ = def;
}

void Character::SetHealth(const int & h) {
	health_ = h;
}

void Character::LowerHealth(const int & h)
{
	health_ -= h;
}

void Character::AddHealth(const int & h)
{
	health_ += h;
}

void Character::IncreaseAttack(const int & att)
{
	attack_ += att;
}

void Character::IncreaseDefence(const int & def)
{
	defence_ += def;
}

bool Character::Attack(Character* otherCharacter) {
	if (!CouldDefend(otherCharacter)) {
		int damage = rand() % (3 + GetAttack() / 10);
		otherCharacter->LowerHealth(damage);
		return true;
	}
	else {
		return false;
	}
}

bool Character::CouldDefend(Character* otherCharacter) {
	if (otherCharacter->GetDefence() > GetAttack()) {
		int successRating = otherCharacter->GetDefence() / GetAttack();
		double success = (rand() % successRating);
		if (success > 1)
			return true;
		else 
			return false;
	}
	return false;
}