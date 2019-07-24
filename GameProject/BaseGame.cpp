#include "stdafx.h"
#include "BaseGame.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

CBaseGame::CBaseGame()
{
}


CBaseGame::~CBaseGame()
{
}

//public
void CBaseGame::Play()
{
	Init();
	while (1)
	{
		ShowScreen();
		DoWithoutInput();
		DoWithInput();
	}
}


//protected
void CBaseGame::HideCursor()
{
	CONSOLE_CURSOR_INFO cusor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cusor_info);
}

void CBaseGame::gotoxy(int x, int y)
{
	HANDLE handele = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handele, pos);
}
