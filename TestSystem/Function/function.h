#pragma once
#include "../stdafx.h"
typedef void(*Func)(int[], int);
namespace nsp_test_function
{	
	//////////////////////////////////////////////////////////////////////////

	//�㷨��
	void do_KMP();						//KMP�㷨
	void do_quick_sort();				//��������
	void do_mao_pao();					//ð�ݷ�
	void do_mao_pao_jiwei();			//ð�ݼ�β��
	void do_selection_sort();			//ѡ������
	void do_insertion_sort();			//�������� 

	void do_queen();					//�ʺ��㷨



	//���ݽṹ��
	void show_PtrArray();
	void show_ArrayPtr();



	//////////////////////////////////////////////////////////////////////////


	//ʵ�ֺ���
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