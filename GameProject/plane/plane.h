#pragma once


class CPlane
{
public:
	CPlane();
	~CPlane();

public:
	void Play(); 

private:
	void HideCursor();
	void Init();
	void ShowScreen();
	void DoWithoutInput();
	void DoWithInput();
	void gotoxy(int x, int y);

private:
	int _plane_x;			//飞机所处行
	int _plane_y;			//飞机所处列
	
	int _enemy_x;			//敌军所在行
	int _enemy_y;			//敌军所在列

	int _bullet_x;			//子弹所在行
	int _bullet_y;			//子弹所在列

	int _nWidth;			//画布宽
	int _nHeight;			//画布高

	int _score;				//得分

	int _different;			//难度系数
};