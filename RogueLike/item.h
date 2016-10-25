#pragma once

class Item
{
public:
	Item();
	~Item();

	void UseItem();
	void SetName(const std::string & n);
	void SetDescription(const std::string & n);
	std::string GetDescription() { return description_; }
	std::string GetName() { return name_; }

protected:
	std::string name_;
	std::string description_;
};