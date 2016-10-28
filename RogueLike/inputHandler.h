#pragma once
#include "stdafx.h"
#include <algorithm>
#include <unordered_map>

class InputHandler
{
private:
	enum commands {
		BYE = 1,
		CLEAR = 2,
		TABLE = 3,
		TITLE = 4,
	};
	std::unordered_map<std::string, commands> enums_;
	void Clear();

public:
	enum Color {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
		RED = 4,
		BLUE = 1,
		GREEN = 2,
		MAGENTA = 5,
		YELLOW = 6,
		WHITE = 7,
		CYAN = 3,
#endif
#if defined(__APPLE__) || defined(__linux__)
		RED = 31,
		BLUE = 34,
		GREEN = 32,
		MAGENTA = 35,
		YELLOW = 33,
		WHITE = 37,
		CYAN = 36,
#endif
	};
	void setTextColor(int colorCode);
	InputHandler();
	virtual ~InputHandler();
	int handleInput(std::string input);
};
