/*
��Ҫ·��
�����������·�ɣ������㷨·�ɣ����ݽṹ·�ɵȵ�
*/
#pragma once
#include "BaseRoute.h"
#include <map>


class CMain_Route : public CBaseRoute
{
public:
	CMain_Route();
	~CMain_Route();
	virtual void ShowRoute();
	virtual int HandleInputString(std::string str);

protected:
	virtual void OnCreate();

private:
	void CreateChildRoute();
	void DeleteChildRoute();
private:
	std::map<int, CBaseRoute*> _ChildRoute;

	enum sel_type
	{
		type_no_sel = -1,
		type_algorithm = 0,
		tye_datastruct = 1
	}_sel_type;
};