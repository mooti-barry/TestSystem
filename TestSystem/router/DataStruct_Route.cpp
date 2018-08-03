#include "../stdafx.h"
#include "DataStruct_Route.h"
#include "../Function/function.h"
#include "../util/util.hpp"

CDataStruct_Route::CDataStruct_Route()
{
	_sName = "数据结构类";
}

CDataStruct_Route::~CDataStruct_Route()
{

}

void CDataStruct_Route::ShowRoute()
{
	OP("序号:\t%20s\t\t函数说明:\t", "执行函数:");
	for (auto it = _Router.begin(); it != _Router.end(); it++)
	{
		OP("%d\t%20s\t\t%s\t ", it->first, it->second.Get_FuncName().c_str(), it->second.Get_FuncDescribed().c_str());
	}
}
int CDataStruct_Route::HandleInputString(std::string str)
{
	int nIn = atoi(str.c_str());

	if (nIn >= 0 && nIn < (int)_Router.size())
	{
		Function pFun = _Router[nIn].Get_Func();
		pFun();
		return nIn;
	}

	return SD_NO_FIND;
}

//protected
void CDataStruct_Route::OnCreate()
{
	CreateRouter();
}


//private
void CDataStruct_Route::CreateRouter()
{
	CFunction_obj obj;
	string fun_name, fun_described;

	int nIndex = 0;
	fun_name = "show_PtrArray";
	fun_described = "指针数组的随机值演示";
	obj.Create(&nsp_test_function::show_PtrArray, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "show_ArrayPtr";
	fun_described = "数组指针的随机值演示。";
	obj.Create(&nsp_test_function::show_ArrayPtr, fun_name, fun_described);
	_Router[nIndex++] = obj;
}