#pragma once

#ifndef CONSOLA_H
#define CONSOLA_H

#include <windows.h>

class Consola
{
	static HANDLE hconsola;
	static HANDLE hStdin;
	static HWND hwnd;
public:
	Consola();
	void gotoxy(int x, int y);
	void clrscr();

	~Consola();
};

#endif