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
	//���ؿ���̨���
	void HideCursor();

	//���ù��λ��
	void gotoxy(int x, int y);
};

