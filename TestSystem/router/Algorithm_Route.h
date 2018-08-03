/*
算法类型的路由器

*/

#pragma once
#include "BaseRoute.h"
#include "../Function/Function_obj.h"
#include <map>

class CAlgorithm_Route : public CBaseRoute
{
public:
	CAlgorithm_Route();
	~CAlgorithm_Route();
	virtual void ShowRoute();
	virtual int HandleInputString(std::string str);

protected:
	virtual void OnCreate();

private:
	void CreateRouter();

private:
	map<int, CFunction_obj> _Router;
};