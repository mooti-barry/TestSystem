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


int _tmain(int argc, _TCHAR* argv[])
{
	//CPlane plane;
	//plane.Play();

	MyGame<CPlane> g;
	g.Play();


	return 0;
}

