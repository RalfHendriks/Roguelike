#pragma once

class Room
{
public:
	Room();
	~Room();

	// Getters
	std::string GetDescription();

	// Setters
	void SetSize(const std::string & s);
	void SetDirty(const std::string & d);
	void SetFurniture(const std::string & f);

private:
	std::string size_;
	std::string dirty_;
	std::string furniture_;
	std::string type_;

	// Methods
	void GenerateRoom();
};