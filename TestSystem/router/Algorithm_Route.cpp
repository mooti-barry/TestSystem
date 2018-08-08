#include "../stdafx.h"
#include "Algorithm_Route.h"
#include "../Function/function.h"
#include "../util/util.hpp"

CAlgorithm_Route::CAlgorithm_Route()
{
	_sName = "算法类";
}

CAlgorithm_Route::~CAlgorithm_Route()
{

}

void CAlgorithm_Route::ShowRoute()
{
	OP("序号:\t%20s\t\t函数说明:\t", "执行函数:");
	for (auto it = _Router.begin(); it != _Router.end(); it++)
	{
		OP("%d\t%20s\t\t%s\t ", it->first, it->second.Get_FuncName().c_str(), it->second.Get_FuncDescribed().c_str());
	}
}
int CAlgorithm_Route::HandleInputString(std::string str)
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
void CAlgorithm_Route::OnCreate()
{
	CreateRouter();
}


//private
void CAlgorithm_Route::CreateRouter()
{
	CFunction_obj obj;
	string fun_name, fun_described;

	int nIndex = 0;

	fun_name = "do_quick_sort";
	fun_described = "快速排序算法。";
	obj.Create(&nsp_test_function::do_quick_sort, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_mao_pao";
	fun_described = "冒泡排序算法。";
	obj.Create(&nsp_test_function::do_mao_pao, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_mao_pao_jiwei";
	fun_described = "冒泡鸡尾酒排序算法。";
	obj.Create(&nsp_test_function::do_mao_pao_jiwei, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_selection_sort";
	fun_described = "选择排序算法。";
	obj.Create(&nsp_test_function::do_selection_sort, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_insertion_sort";
	fun_described = "插入排序算法。";
	obj.Create(&nsp_test_function::do_insertion_sort, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_KMP";
	fun_described = "KMP算法。文本串S,和一个模式串P,现在要查找P在S中的第一个位置。";
	obj.Create(&nsp_test_function::do_KMP, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_queen";
	fun_described = "皇后算法。";
	obj.Create(&nsp_test_function::do_queen, fun_name, fun_described);
	_Router[nIndex++] = obj;
}