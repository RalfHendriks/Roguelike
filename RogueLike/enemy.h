#pragma once

class Enemy
{
public:
	Enemy();
	~Enemy();

	// Getters
	std::string GetName() { return name_; }
	int GetLevel() { return level_; }
	int GetAttack() { return attack_; }
	int GetAttackSequence() { return attackSequence_; }
	int GetMinDamage() { return minDamage_; }
	int GetMaxDamage() { return maxDamage_; }
	int GetDefence() { return defence_; }
	int GetHealth() { return health_; }

	//Setters
	void SetName(const std::string & n);
	void SetLevel(const int & lvl);
	void SetAttack(const int & att);
	void SetAttackSequence(const int & attSeq);
	void SetMinDamage(const int & minDam);
	void SetMaxDamage(const int & maxDam);
	void SetDefence(const int & def);
	void SetHealth(const int & h);

	// Methods
	void Attack();

protected:
	std::string name_;
	int level_;
	int attack_;
	int attackSequence_;
	int minDamage_;
	int maxDamage_;
	int defence_;
	int health_;
};