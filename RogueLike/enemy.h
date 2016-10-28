#pragma once

#include "character.h"

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();

	// Getters
	int GetAttackSequence() { return attackSequence_; }
	int GetMinDamage() { return minDamage_; }
	int GetMaxDamage() { return maxDamage_; }

	//Setters
	void SetAttackSequence(const int & attSeq);
	void SetMinDamage(const int & minDam);
	void SetMaxDamage(const int & maxDam);

protected:
	int attackSequence_, minDamage_, maxDamage_;
};