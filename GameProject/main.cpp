// GameProject.cpp : Defines the entrx point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>

#include "plane/plane.h"

template<class T>
class MyGame
{
public:
	MyGame();
	~MyGame(){};

public:
	void Play();
private:
	T* _pGame;
};

template<class T>
MyGame<T>::MyGame()
{
	_pGame = new T;
}

template<class T>
void MyGame<T>::Play()
{
	_pGame->Play();
}



void GetNext(int next[],const  char* d)
{
	int dLen = strlen(d);
	next[0] = -1;
	int k = -1;
	int i = 0;
	while ( i < dLen)
	{
		if (k == -1 || d[k] == d[i])
		{
			k++;
			i++;
			next[i] = k;
		}
		else
			k = next[k];
	}
}
int KMP(const char* s,const char* d)
{
	int sLen = strlen(s);
	int dLen = strlen(d);
	int *next = new int[dLen];
	memset(next, 0, dLen * sizeof(int));
	GetNext(next, d);

	int i = 0,j = 0;
	while ( i < sLen && j <dLen)
	{
		if (j == -1 || d[j] == s[i])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}

	if (j == dLen)
		return i - j;

	return -1;
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	//CPlane plane;
	//plane.Play();

	//MyGame<CPlane> g;
	//g.Play();

	std::string s = "wo bu shi huang rong";
	std::string d = "bu";
	int a = KMP(s.c_str(),d.c_str());



	return 0;
}

