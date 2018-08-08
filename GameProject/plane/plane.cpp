#include "../stdafx.h"
#include "plane.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
CPlane::CPlane()
{

}

CPlane::~CPlane()
{

}

void CPlane::Play()
{
	Init();
	while (1)
	{
		ShowScreen();
		DoWithoutInput();
		DoWithInput();
	}
}



//private:
void CPlane::HideCursor()
{
	CONSOLE_CURSOR_INFO cusor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cusor_info);
}
void CPlane::gotoxy(int x, int y)
{
	HANDLE handele = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handele, pos);
}
void CPlane::Init()
{
	_nWidth = 30;
	_nHeight = 18;
	
	_plane_x = _nWidth / 2;
	_plane_y = _nHeight / 2;

	_bullet_x = -1;
	_bullet_y = _plane_y;

	_score = 0;

	_enemy_x = 0;
	_enemy_y = _plane_y;
	
	_different = 0;

	HideCursor();
}
void CPlane::ShowScreen()
{
	gotoxy(0, 0);
	for (int i = 0; i < _nHeight; i++)
	{
		for (int j = 0; j < _nWidth; j++)
		{
			printf_s(" ");
			if ((i == _plane_x) && (j == _plane_y))
				printf_s("*");
			if ((i == _enemy_x) && (j == _enemy_y))
				printf_s("@");
			if ((i == _bullet_x) && (j == _bullet_y))
				printf_s("|");
		}
		printf_s("\n");
	}

	printf_s("得分：%d", _score);

}
void CPlane::DoWithoutInput()
{
	if ((_bullet_x == _enemy_x) && (_bullet_y == _enemy_y))
	{
		_score++;
		_bullet_x = -1;
		_enemy_y = rand() % _nWidth;
		_enemy_y == _nWidth ? _nWidth - 1 : _enemy_y;
		_enemy_x = 0;
	}

	if (_bullet_x > -1)
		_bullet_x--;

	
	if (_different < 10)
		_different++;
	else
	{
		_enemy_x++;
		if (_enemy_x > _nHeight)
		{
			_enemy_y = rand() % _nWidth;
			_enemy_y == _nWidth ? _nWidth - 1 : _enemy_y;
			_enemy_x = 0;
		}
		
		if (_score > 5)
			_different = 3;
		else if (_score > 10)
			_different = 7;
		else if (_score > 12)
			_different = 10;
		else 
			_different = 0;
	}	
}
void CPlane::DoWithInput()
{
	if (_kbhit())
	{
		char input = _getch();
		if (input == 'a')
			_plane_y--;
		else if (input == 'd')
			_plane_y++;
		else if (input == 'w')
			_plane_x--;
		else if (input == 's')
			_plane_x++;
		else if (input == ' ')
		{
			_bullet_x = _plane_x - 1;
			_bullet_y = _plane_y;
		}
			
	}
}
