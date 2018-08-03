#include "../stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

#include "function.h"
#include "../util/util.hpp"
void nsp_test_function::Sort_Func_Template(Func pFunc, string sFunStart)
{
	OP("输入整形数组,以空格分隔,以回车完成输入");

	string str;
	getline(cin, str);
	if (str == "")
	{
		goto ERROE;
	}

	string* strArray = NULL;
	int nCount = 0;
	strArray = Split(str, " ", nCount);
	if (strArray && nCount > 0)
	{
		int *pIntArray = new int[nCount];
		for (int i = 0; i < nCount; i++)
		{
			pIntArray[i] = atoi(strArray[i].c_str());
		}
		delete[] strArray;
		OP(sFunStart.c_str());
		pFunc(pIntArray, nCount);
		OP("final result:");
		for (int i = 0; i < nCount; i++)
		{
			std::cout << pIntArray[i] << ' ';
		}
		OP(" ");
		delete[]pIntArray;
	}
	else
	{
	ERROE:
		OP("parse failed.");
	}

	SystemPause();
}
void nsp_test_function::quick_sort(int num[], int l, int r)
{
	if (l < r)
	{
		int i = l, k = r;
		int x = num[i];

		while (i < k)
		{
			while (i<k && num[k]>x)
				k--;

			if (i < k)
				num[i++] = num[k];

			while (i < k && num[i] < x)
				i++;

			if (i < k)
				num[k--] = num[i];
		}

		num[i] = x;

		for (int i = 0; i <= r;i++)
		{
			std::cout << num[i] << ' ';
		}
		OP(" ");

		quick_sort(num, l, i - 1);
		quick_sort(num, i + 1, r);
	}
}
void nsp_test_function::mao_pao(int num[], int len)
{
	string str = "思路：从第一个数开始左往右，大数沉淀。再到下一个数，继续从左往右，大数沉淀。依次进行";
	OP(str.c_str());

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (num[i] > num[j])
			{
				int a = num[i];
				num[i] = num[j];
				num[j] = a;
			}
		}

		for (int k = 0; k < len; k++)
		{
			std::cout << num[k] << ' ';
		}
		OP(" ");
	}
}
void nsp_test_function::mao_pao_jiwei(int num[], int len)
{
	string str = "思路：先从左往右,大数沉淀。再从右往左,小数上浮。依次进行";
	OP(str.c_str());

	int l = 0;
	int r = len - 1;

	while (l < r)
	{
		for (int i = l; i < r; i++)
		{
			if (num[i] > num[i + 1])
			{
				int temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
		}

		for (int i = 0; i < len; i++)
		{
			std::cout << num[i] << ' ';
		}
		OP(" ");

		r--;

		for (int i = r; i > l; i--)
		{
			if (num[i] < num[i - 1])
			{
				int temp = num[i];
				num[i] = num[i - 1];
				num[i - 1] = temp;
			}
		}
		l++;

		for (int i = 0; i < len; i++)
		{
			std::cout << num[i] << ' ';
		}
		OP(" ");
	}
}
void nsp_test_function::selection_sort(int num[], int len)
{
	string str = "思路：i从0到len-1,j从i+1到len,找出num[j]<num[i],并且num[j]最小的那个与num[i]交换位置";
	OP(str.c_str());

	int i = 0,j;
	int nIndex;
	while (i < len - 1)
	{
		nIndex = i;
		j = i + 1;
		while (j < len)
		{
			if (num[j] < num[nIndex])
			{
				nIndex = j;
			}
			j++;
		}
		
		if (nIndex != i)
		{
			num[i] = num[i] + num[nIndex];
			num[nIndex] = num[i] - num[nIndex];
			num[i] = num[i] - num[nIndex];
		}


		for (int k = 0; k< len;k++)
		{
			std::cout << num[k] << ' ';
		}
		OP(" ");

		i++;
	}
}
void nsp_test_function::insertion_sort(int num[], int len)
{
	string str = "思路：对于未排序数据(右手抓到的牌)，在已排序序列(左手已经排好序的手牌)中从后向前扫描，找到相应位置并插入。";
	for (int i = 1; i < len;i++)
	{
		int get = num[i];
		int j = i - 1;
		while (num[j] > get && j >= 0)
		{
			num[j + 1] = num[j];
			j--;
		}

		num[j + 1] = get;

		for (int k = 0; k < len; k++)
		{
			std::cout << num[k] << ' ';
		}
		OP(" ");
	}
}

//namespace：
void nsp_test_function::do_quick_sort()
{
	OP("输入整形数组,以空格分隔,以回车完成输入");

	string str;
	getline(cin, str);
	if (str == "")
	{
		goto ERROE;
	}
	
	string* strArray = NULL;
	int nCount = 0;
	strArray = Split(str, " ", nCount);
	if (strArray && nCount > 0)
	{
		int *pIntArray = new int[nCount];
		for (int i = 0; i < nCount; i++)
		{
			pIntArray[i] = atoi(strArray[i].c_str());
		}
		delete[] strArray;
		OP("quick_sort start");
		quick_sort(pIntArray, 0, nCount - 1);
		OP("final result:");
		for (int i = 0; i < nCount; i++)
		{
			std::cout << pIntArray[i] << ' ';
		}
		OP(" ");
		delete[]pIntArray;
	}
	else
	{
	ERROE:
		OP("parse failed.");
	}

	SystemPause();
}
void nsp_test_function::do_mao_pao()
{
	Sort_Func_Template(&nsp_test_function::mao_pao, "mao_pao start");
}
void nsp_test_function::do_mao_pao_jiwei()
{
	Sort_Func_Template(&nsp_test_function::mao_pao_jiwei, "mao_pao_jiwei start");
}
void nsp_test_function::do_selection_sort()
{
	Sort_Func_Template(&nsp_test_function::selection_sort, "selection_sort start");
}
void nsp_test_function::do_insertion_sort()
{
	Sort_Func_Template(&nsp_test_function::insertion_sort, "insertion_sort start");
}
void nsp_test_function::do_KMP()
{
	OP("输入文本串：");
	string sSource,sDev;
	getline(cin, sSource);

	OP("输入模式串：");
	getline(cin, sDev);

	OP("KMP start");
	int pos = KMP(sSource.c_str(), sDev.c_str());
	if (pos == SD_NO_FIND)
		OP("文本串匹配不到模式串");
	else
	{
		OP("文本串匹配到模式串,模式串最早出现的位置是:%d", pos);
	}

	SystemPause();
}
void nsp_test_function::show_PtrArray()
{
	OP("演示指针数组例子");

	srand((unsigned)time(NULL));
	const int arrayCount = 10;

	//数组方式
	int *p[arrayCount];
	for (int i = 0; i < arrayCount; i++)
	{
		p[i] = new int(rand() % 100);
		OP("p[%d]:%d,*p[%d]:%d", i, p[i], i, *p[i]);
	}

	//动态生成方式
	int **pptr = new int *[arrayCount];
	for (int i = 0; i < arrayCount; i++)
	{
		pptr[i] = new int(rand() % 100 + 100);
		OP("pptr[%d]:%d,*pptr[%d]:%d", i, pptr[i], i, *pptr[i]);
	}


	//释放内存
	for (int i = 0; i < arrayCount; i++)
	{
		delete p[i];
		delete pptr[i];
	}

	delete[]pptr;

	SystemPause();
}
void nsp_test_function::show_ArrayPtr()
{

	OP("演示数组指针例子");

	srand((unsigned)time(NULL));
	const int arrayCount = 10;
	//
	int a[arrayCount] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int(*p)[arrayCount] = &a;
	for (int i = 0; i < arrayCount; i++)
	{
		(*p)[i] = rand() % 10;
		OP("p[%d]:%d,(*p)[%d]:%d", i, p[i], i, (*p)[i]);
	}

	//动态方式
	int *pptr = new int[arrayCount];
	for (int i = 0; i < arrayCount; i++)
	{
		pptr[i] = rand() % 10 + 10;
		OP("pptr[%d]:%d", i, pptr[i]);
	}


	//释放内存
	delete[] pptr;

	SystemPause();
}
