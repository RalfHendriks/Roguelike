#include "stdafx.h"
#include "heroSaveData.h"
#include "hero.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

HeroSaveData::HeroSaveData()
{
}

HeroSaveData::~HeroSaveData()
{
}

bool HeroSaveData::LoadHero()
{
	std::string line;
	std::ifstream file("../hero.txt");
	if (!file.is_open())
		return false;

	while (file.good()) {
		getline(file, line);
		ParseLine(line);
	}
	file.close();

	return false;
}

bool HeroSaveData::SaveHero()
{
	std::ofstream outputFile;
	outputFile.open("../hero.txt", std::ofstream::out | std::ofstream::trunc);

	if (!outputFile.is_open())
		return false;

	outputFile << "HERO | RogueLike SaveData \n\n";
	outputFile << "[name;" << Hero::Instance()->GetName() << "]" << "\n";
	outputFile << "[level;" << Hero::Instance()->GetLevel() << "]" << "\n";
	outputFile << "[attack;" << Hero::Instance()->GetAttack() << "]" << "\n";
	outputFile << "[defence;" << Hero::Instance()->GetDefence() << "]" << "\n";
	outputFile << "[health;" << Hero::Instance()->GetHealth() << "]" << "\n";
	outputFile << "[exp;" << Hero::Instance()->GetExp() << "]" << "\n";
	outputFile << "[maxhealth;" << Hero::Instance()->GetMaxHealth() << "]" << "\n";

	outputFile.close();
	return true;
}

void HeroSaveData::ParseLine(std::string & line)
{
	if (line == "")
		return;

	if (line.at(0) != '[')
		return;

	line.erase(line.begin());
	line.erase(line.end());

	std::stringstream ss(line);
	std::string item;
	std::string items[2];
	int i = 0;
	while (getline(ss, item, ';')) {
		items[i] = item;
		i++;
	}

	ParseDataToHero(items);

}

void HeroSaveData::ParseDataToHero(std::string data[]) {

	if (data[0] == "name")
		Hero::Instance()->SetName(data[1]);

	if (data[0] == "level")
		Hero::Instance()->SetLevel(std::stoi(data[1]));

	if (data[0] == "attack")
		Hero::Instance()->SetAttack(std::stoi(data[1]));

	if (data[0] == "defence")
		Hero::Instance()->SetDefence(std::stoi(data[1]));

	if (data[0] == "health")
		Hero::Instance()->SetHealth(std::stoi(data[1]));

	if (data[0] == "exp")
		Hero::Instance()->SetXp(std::stoi(data[1]));

	if (data[0] == "maxhealth")
		Hero::Instance()->SetMaxHealth(std::stoi(data[1]));

}