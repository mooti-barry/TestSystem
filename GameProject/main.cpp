// GameProject.cpp : Defines the entrx point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	int y = 5;
	int	x = 15;
	bool bfired = false;
	bool bIsKilled = false;

	int ny = 6;
	char input;
	while (1)
	{
		system("cls");

		if (!bIsKilled)
		{
			for (int j = 0; j < ny; j++)
				printf_s(" ");
			printf_s("x\n");
		}

		if (!bfired)
		{
			for (int i = 0; i < x; i++)
				printf_s("\n");
		}
		else
		{
			for (int j = 0; j < x; j++)
			{
				for (int i = 0; i < y; i++)
					printf_s(" ");
				printf_s("  |\n");
			}
			if (y + 2 == ny)
				bIsKilled = true;

			bfired = false;
		}
		


		for (int i = 0; i < y; i++)
			printf_s(" ");
		printf_s("  *\n");

		for (int i = 0; i < y; i++)
			printf_s(" ");
		printf_s("*****\n");
		for (int i = 0; i < y; i++)
			printf_s(" ");
		printf_s(" * *\n");

		input = _getch();
		
		if (input == 'w')
			x--;
		else if (input == 's')
			x++;
		else if (input == 'a')
			y--;
		else if (input == 'd')
			y++;
		else if (input == ' ')
			bfired = true;

		if (y < 0) y = 0;
		if (x < 0) x = 0;
		
		

	}
	
	return 0;
}

