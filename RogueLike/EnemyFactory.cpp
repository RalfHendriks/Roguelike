#include "stdafx.h"
#include "enemyFactory.h"
#include "globals.h"
#include <fstream>
#include <sstream>
#include <algorithm>

EnemyFactory::EnemyFactory() {
	ParseFile("../monsters.txt");
}

EnemyFactory::~EnemyFactory() {

}

void EnemyFactory::Destroy()
{
	for (size_t i = 0; i < Enemies.size(); i++) {
		delete Enemies.at(i);
	}
	Enemies.clear();
}

void EnemyFactory::ParseFile(const std::string & path) {
	std::string line;
	std::ifstream file(path);
	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			ParseLine(line);
		}
		file.close();
	}
}

void EnemyFactory::ParseLine(std::string & line) {
	if (line == "")
		return;

	if (line.at(0) != '[')
		return;

	line.erase(line.begin());
	line.erase(line.end() - 1);

	std::stringstream ss(line);
	std::string item;
	std::string items[6];
	int i = 0;
	while (getline(ss, item, ';')) {
		items[i] = item;
		i++;
	}

	ParseDataToMonster(items);
}

void EnemyFactory::ParseDataToMonster(std::string data[]) {

	Enemy* monster = new Enemy();

	// Name
	monster->SetName(data[0]);

	// Level
	if (data[1] == "BAAS")
		data[1] = "11";

	monster->SetLevel(std::stoi(data[1]));

	// Attack and AttackSequence
	std::stringstream ss(data[2]);
	std::string item;
	std::string items[2];
	int i = 0;
	while (getline(ss, item, 'x')) {
		items[i] = item;
		i++;
	}

	monster->SetAttack(std::stoi(items[0]));
	monster->SetAttackSequence(std::stoi(items[1])); 

	// MinDamage and MaxDamage
	std::stringstream ss2(data[3]);
	i = 0;
	while (getline(ss2, item, '-')) {
		items[i] = item;
		i++;
	}

	monster->SetMinDamage(std::stoi(items[0]));
	monster->SetMaxDamage(std::stoi(items[1]));

	// Defence
	monster->SetDefence(std::stoi(data[4]));

	// Health
	monster->SetHealth(std::stoi(data[5]));

	// Add enemy to vector
	Enemies.push_back(monster);
}

Enemy* EnemyFactory::GetMonser(const int & lvl) {

	std::random_shuffle ( Enemies.begin(), Enemies.end(), Globals::Random);

	for (size_t i = 0; i < Enemies.size(); i++) {
		if (Enemies.at(i)->GetLevel() == lvl) {
			return Enemies.at(i)->Clone();
		}
	}

	return Enemies.at(0)->Clone();
}