#pragma once
#include "../stdafx.h"
typedef void(*Func)(int[], int);
namespace nsp_test_function
{	
	//////////////////////////////////////////////////////////////////////////

	//算法类
	void do_KMP();						//KMP算法
	void do_quick_sort();				//快速排序
	void do_mao_pao();					//冒泡法
	void do_mao_pao_jiwei();			//冒泡鸡尾酒
	void do_selection_sort();			//选择排序
	void do_insertion_sort();			//插入排序 

	void do_queen();					//皇后算法



	//数据结构类
	void show_PtrArray();
	void show_ArrayPtr();



	//////////////////////////////////////////////////////////////////////////


	//实现函数
	void Sort_Func_Template(Func pFunc, std::string sFunStart);
	void quick_sort(int num[], int l, int r);
	void mao_pao(int num[], int len);
	void mao_pao_jiwei(int num[], int len);
	void selection_sort(int num[],int len);
	void insertion_sort(int num[], int len);
	void insertion_dichotomy_sort(int num[], int len);
	void insertion_shell_sort(int num[], int len);
	void queen(int row, int ncount,int &total,int p[]);
}