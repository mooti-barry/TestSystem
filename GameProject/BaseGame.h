#pragma once
class CBaseGame
{
public:
	CBaseGame();
	~CBaseGame();

public:
	virtual void Play();

protected:
	virtual void Init() = 0;
	virtual void ShowScreen() = 0;
	virtual void DoWithoutInput() = 0;
	virtual void DoWithInput() = 0;

protected:
	//隐藏控制台光标
	void HideCursor();

	//设置光标位置
	void gotoxy(int x, int y);
};

