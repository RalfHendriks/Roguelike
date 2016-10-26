#pragma once

class Character {

public:
	Character();
	~Character();

	// Getters
	std::string GetName() { return name_; }
	int GetLevel() { return level_; }
	int GetAttack() { return attack_; }
	int GetDefence() { return defence_; }
	int GetHealth() { return health_; }

	// Setters
	void SetName(const std::string & n);
	void SetLevel(const int & lvl);
	void SetAttack(const int & att);
	void SetDefence(const int & def);
	void SetHealth(const int & h);

	// Methods
	void LowerHealth(const int & h);
	void AddHealth(const int & h);
	void IncreaseAttack(const int & att);
	void IncreaseDefence(const int & def);
	bool CouldDefend(Character* otherCharacter);
	bool Attack(Character* otherCharacter);

protected:
	std::string name_;
	int level_, attack_, defence_, health_;
};