#pragma once

class HeroSaveData
{
public:
	HeroSaveData();
	~HeroSaveData();
	
	bool LoadHero();
	bool SaveHero();

private:
	void ParseLine(std::string & line);
	void ParseDataToHero(std::string data[]);

};