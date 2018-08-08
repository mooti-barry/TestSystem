#include "../stdafx.h"
#include "Algorithm_Route.h"
#include "../Function/function.h"
#include "../util/util.hpp"

CAlgorithm_Route::CAlgorithm_Route()
{
	_sName = "�㷨��";
}

CAlgorithm_Route::~CAlgorithm_Route()
{

}

void CAlgorithm_Route::ShowRoute()
{
	OP("���:\t%20s\t\t����˵��:\t", "ִ�к���:");
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
	fun_described = "���������㷨��";
	obj.Create(&nsp_test_function::do_quick_sort, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_mao_pao";
	fun_described = "ð�������㷨��";
	obj.Create(&nsp_test_function::do_mao_pao, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_mao_pao_jiwei";
	fun_described = "ð�ݼ�β�������㷨��";
	obj.Create(&nsp_test_function::do_mao_pao_jiwei, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_selection_sort";
	fun_described = "ѡ�������㷨��";
	obj.Create(&nsp_test_function::do_selection_sort, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_insertion_sort";
	fun_described = "���������㷨��";
	obj.Create(&nsp_test_function::do_insertion_sort, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_KMP";
	fun_described = "KMP�㷨���ı���S,��һ��ģʽ��P,����Ҫ����P��S�еĵ�һ��λ�á�";
	obj.Create(&nsp_test_function::do_KMP, fun_name, fun_described);
	_Router[nIndex++] = obj;

	fun_name = "do_queen";
	fun_described = "�ʺ��㷨��";
	obj.Create(&nsp_test_function::do_queen, fun_name, fun_described);
	_Router[nIndex++] = obj;
}