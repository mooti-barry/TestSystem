/*
数据结构路由
*/

#pragma once
#include "BaseRoute.h"
#include "../Function/Function_obj.h"
#include <map>

class CDataStruct_Route : public CBaseRoute
{
public:

	CDataStruct_Route();
	~CDataStruct_Route();
	virtual void ShowRoute();
	virtual int HandleInputString(std::string str);

protected:
	virtual void OnCreate();

private:
	void CreateRouter();

private:
	map<int, CFunction_obj> _Router;
};