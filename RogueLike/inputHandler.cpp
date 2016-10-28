#include "inputHandler.h"
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <Windows.h>
#endif

void InputHandler::setTextColor(int colorCode)
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, colorCode);
#endif

#if defined(__APPLE__) || defined(__linux__)
	if (colorCode < 40) {
		cout << "\x1B[" << colorCode << "m";
	}
#endif
}

InputHandler::InputHandler()
{
	enums_.emplace("BYE!", BYE);
	enums_.emplace("BYE", BYE);
	enums_.emplace("TITLE", TITLE);
	enums_.emplace("CLEAR", CLEAR);
	enums_.emplace("TABLE", TABLE);
}

InputHandler::~InputHandler()
{
}

int InputHandler::handleInput(std::string input)
{
	int handleMessage = 1;
	std::transform(input.begin(), input.end(), input.begin(), ::toupper);
	commands enumCode = enums_[input];
	switch (enumCode) {
	case BYE:
		handleMessage = -1;
		std::cout << "\n";
		break;
	case CLEAR:
		handleMessage = 0;
		Clear();
		break;
	case TABLE:
		handleMessage = 0;
		break;
	default:
		handleMessage = 1;
		break;
	}
	return handleMessage;
}

void InputHandler::Clear()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
#endif
#if defined(__APPLE__) || defined(__linux__)
	std::cout << "\x1B[2J\x1B[H";
#endif
}
