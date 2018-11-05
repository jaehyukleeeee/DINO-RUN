#include <Windows.h>
#include "Screen.h"

int Screen::s_Index;
HANDLE Screen::s_Screen[2];

void Screen::Init() {
	CONSOLE_CURSOR_INFO cci;

	// 가상의 콘솔창 2개를 만든다.
	s_Screen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	s_Screen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서 숨기기
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(s_Screen[0], &cci);
	SetConsoleCursorInfo(s_Screen[1], &cci);
}

void Screen::Flipping() {
	Sleep(10);
	SetConsoleActiveScreenBuffer(s_Screen[s_Index]);
	s_Index = !s_Index;
}

void Screen::Clear() {
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(s_Screen[s_Index], ' ', 80 * 25, Coor, &dw);
}

void Screen::Release() {
	CloseHandle(s_Screen[0]);
	CloseHandle(s_Screen[1]);
}

void Screen::Print(int x, int y, char *string)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(s_Screen[s_Index], CursorPosition);
	WriteFile(s_Screen[s_Index], string, strlen(string), &dw, NULL);
}

// 1 ~ 15 까지 색상 설정가능
void Screen::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(s_Screen[s_Index], color);
}