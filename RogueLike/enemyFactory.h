#pragma once

#include "enemy.h"

class EnemyFactory
{
private:
	std::vector<Enemy*> Enemies = std::vector<Enemy*>();
	void ParseFile(const std::string & path);
	void ParseLine(const std::string & line);
	void ParseDataToMonster(std::string data[]);

protected:
	EnemyFactory();
	EnemyFactory(const EnemyFactory&);
	EnemyFactory& operator= (const EnemyFactory&);

public:
	~EnemyFactory();

	static EnemyFactory* Instance()
	{
		static EnemyFactory mInstance;
		return &mInstance;
	}

	Enemy* GetMonser(const int & lvl);
};