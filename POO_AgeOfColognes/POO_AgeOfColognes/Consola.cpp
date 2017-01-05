#include "Consola.h"                      
#include <windows.h>
#include <stdio.h>


Consola::Consola()
{
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);
	hStdin = GetStdHandle(STD_INPUT_HANDLE);;
	hwnd = GetConsoleWindow();
}

void Consola::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hconsola, coord);
}

void Consola::clrscr() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	const COORD startCoords = { 0,0 };
	DWORD dummy;

	GetConsoleScreenBufferInfo(hconsola, &csbi);
	FillConsoleOutputCharacter(hconsola,
		' ',
		csbi.dwSize.X * csbi.dwSize.Y,
		startCoords,
		&dummy);
	FillConsoleOutputAttribute(hconsola,
		csbi.wAttributes,
		csbi.dwSize.X * csbi.dwSize.Y,
		startCoords,
		&dummy);
	gotoxy(0, 0);
}

Consola::~Consola()
{
}
