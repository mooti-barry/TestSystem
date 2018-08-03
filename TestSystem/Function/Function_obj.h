#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef void(*Function)();
class CFunction_obj
{
public:
	CFunction_obj();
	~CFunction_obj();
	
	void Create(Function p,string strFuncName, string strFuncDescribed);
	void Print_FuncName();
	void Print_FuncDescribed();

	Function Get_Func(){ return _Fun; }
	string Get_FuncDescribed(){ return _func_described; }
	string Get_FuncName(){ return _func_name; }

private:
	string _func_name; 
	string _func_described;
	Function _Fun;
};

