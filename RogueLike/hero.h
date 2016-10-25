#pragma once

class Hero
{
private:
	int level_;
	int attack_;
	int defence_;
	int exp_;
public:
	std::string Name;
	int Hitpoints;
	int GetExp() { return exp_; }
};