#include "../stdafx.h"
#include <iostream>
#include <string>
#include <stdarg.h>
#include <ctime>
#include <conio.h>
#include "../system_def.h"
using namespace std;
using namespace app_system;

const int MAX_SPLIT = 1024;

static void GetNext(const char*d, int *next)
{
	int dLen = strlen(d);

	next[0] = -1;
	int i = 0;
	int k = -1;

	while (i < dLen - 1)
	{
		if (k == -1 || d[i] == d[k])
		{
			i++;
			next++;
			next[i] = k;
		}
		else
			k = next[k];
	}
}
static int KMP(const char* s, const char* d)
{
	int sLen = strlen(s);
	int dLen = strlen(d);

	if (sLen == 0 || dLen == 0)
	{
		return SD_ERROR;	//输入有误
	}

	int *next = new int[dLen];
	memset(next, -2, dLen);
	GetNext(d, next);

	int i = 0, j = 0;

	while (i < sLen && j < dLen)
	{
		if (j == -1 || s[i] == d[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	if (j == dLen)
		return i - j;

	return SD_NO_FIND;	//没找到
}




/*
类似Format用法，会自动加\n
*/
#define MAX_FORMAT_LEN 1024
static char stdio_msg_buf_[MAX_FORMAT_LEN];

/*
原函数名：OutPut
功能类似Format，接收多个参数
自动增加 \n,在控制台实现自动换行
*/
static int OP(const char *format, ...)
{
	memset(stdio_msg_buf_, 0, MAX_FORMAT_LEN);

	va_list args;
	int len = 0;

	va_start(args, format);
	vsnprintf_s(stdio_msg_buf_, MAX_FORMAT_LEN, &format[0], args);
	va_end(args);

	len = strlen(stdio_msg_buf_);

	printf_s(stdio_msg_buf_);
	printf_s("\n");

	return len;
}

static void SystemPause()
{
	OP("请按任意键继续...");
	//string s;
	//getline(cin, s);
	_getch();	//包含头#include <conio.h>
}

static void  Delay(int  time)
{
	clock_t  now = clock();

	while (clock() - now < time);
}

static void ShowTime()
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	OP("Time: %02d-%02d-%02d %02d:%02d:%02d", timeinfo.tm_year + 1900,
		timeinfo.tm_mon + 1, timeinfo.tm_mday, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
}

/*
@ssource	(in)	待切割的string
@dev		(in)	分割字符串
@splitCount（out）	切割个数 

e.g. :

string s = "absc siodna csss";
string dev = " ";
string *array = NULL;
int nCount = 0;
array = Split(s,dev,nCount);
for (int i = 0; i < nCount;i++)
	array[i];
delete []array;
*/
static string* Split(const string& ssource, const string dev, int &splitCount)
{
	string stemp = ssource;
	string sSplit;
	int nPos = 0,nCount = 0;
	string strArray[MAX_SPLIT];

	while ((nPos = KMP(stemp.c_str(), dev.c_str())) != SD_NO_FIND)
	{
		if (nPos != 0)
		{
			sSplit = stemp.substr(0, nPos);
			strArray[nCount++] = sSplit;
		}
		stemp = stemp.substr(nPos + dev.length(), stemp.length());
	}


	strArray[nCount++] = stemp;
	splitCount = nCount;


	string *p = new string[nCount];
	for (int i = 0; i < nCount; i++)
	{
		p[i] = strArray[i];
	}
	return p;

}

/*
获取随机数组
*/
static void GetRandomArray(int p[], int nCOunt = 10, int nbegin = 0, int nend = 100)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < nCOunt; i++)
	{
		p[i] = rand() % (nend - nbegin) + nbegin;
	}
}