#include "../stdafx.h"
#include "Main_Route.h"
#include "../util/util.hpp"
#include "Algorithm_Route.h"
#include "DataStruct_Route.h"
#include "../system_def.h"

CMain_Route::CMain_Route()
{
	_sName = "主路由";
	_sel_type = type_no_sel;
}
CMain_Route::~CMain_Route()
{
	DeleteChildRoute();
}
void CMain_Route::ShowRoute()
{
	OP("\n");
	switch (_sel_type)
	{
	case CMain_Route::type_no_sel:
	{
		OP("序号:\t类目:\t");
		for (auto it = _ChildRoute.begin(); it != _ChildRoute.end(); it++)
		{
			OP("%d\t%s\t", it->first, it->second->GetRouteName().c_str());
		}
	}
	break;
	case CMain_Route::type_algorithm:
	{
		_ChildRoute[type_algorithm]->ShowRoute();
		OP("输入..返回上一级");
	}
	break;
	case CMain_Route::tye_datastruct:
	{
		_ChildRoute[tye_datastruct]->ShowRoute();
		OP("输入..返回上一级");
	}
	break;
	default:
		OP("Main_Route::ShowRoute找不到对应值");
		break;
	}

}
int CMain_Route::HandleInputString(std::string str)
{
	if (str == ".." || str == "。。")
	{
		_sel_type = type_no_sel;
		return type_no_sel;
	}

	switch (_sel_type)
	{
	case CMain_Route::type_no_sel:
	{
		int nIndex = atoi(str.c_str());
		switch (nIndex)
		{
		case CMain_Route::type_algorithm:
			_sel_type = type_algorithm;
			return type_algorithm;
		case CMain_Route::tye_datastruct:
			_sel_type = tye_datastruct;
			return tye_datastruct;
		default:
			return app_system::SD_NO_FIND;
		}
	}
		break;
	case CMain_Route::type_algorithm:
		return _ChildRoute[type_algorithm]->HandleInputString(str);
	case CMain_Route::tye_datastruct:
		return _ChildRoute[tye_datastruct]->HandleInputString(str);
	default:
		return app_system::SD_NO_FIND;
	}

	return app_system::SD_NO_FIND;
}

//protected
void CMain_Route::OnCreate()
{
	CreateChildRoute();
}

//private
void CMain_Route::CreateChildRoute()
{
	CBaseRoute* pRoute = new CAlgorithm_Route;
	pRoute->Create(this);
	_ChildRoute[type_algorithm] = pRoute;


	pRoute = new CDataStruct_Route;
	pRoute->Create(this);
	_ChildRoute[tye_datastruct] = pRoute;
}
void CMain_Route::DeleteChildRoute()
{
	for (auto it = _ChildRoute.begin(); it != _ChildRoute.end(); it++)
	{
		delete it -> second;
	}
	_ChildRoute.clear();
}
