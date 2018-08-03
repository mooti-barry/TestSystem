#include "../stdafx.h"
#include "Function_obj.h"
#include "../util/util.hpp"

CFunction_obj::CFunction_obj()
{
	_Fun = NULL;
}


CFunction_obj::~CFunction_obj()
{
}

void CFunction_obj::Create(Function p, string strFuncName, string strFuncDescribed)
{
	_Fun = p;
	_func_name = strFuncName;
	_func_described = strFuncDescribed;
}

void CFunction_obj::Print_FuncName()
{
	OP(_func_name.c_str());
}
void CFunction_obj::Print_FuncDescribed()
{
	OP(_func_described.c_str());
}
