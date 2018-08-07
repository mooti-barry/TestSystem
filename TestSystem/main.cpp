#include "stdafx.h"



#include<iostream>
#include<cmath>
#include <string>
#include<map>
#include <ctime>

#include "util/util.hpp"
#include "Function/Function_obj.h"
#include "Function/function.h"
#include "system_def.h"
#include "router/Main_Route.h"

using namespace std;
using namespace app_system;

int main()
{
	ShowTime();
	OP("Welcome to The Test System!");
	
	OP("Initing,Please Wait····");
	CMain_Route mainRoute;
	mainRoute.Create(NULL);
	OP("Init Has Done.");

	OP("输入exit退出,输入-h显示帮助");
	while (true)
	{
		mainRoute.ShowRoute();
		string str;
		OP("\n请输入序号:");
		getline(cin, str);

		if (str == "exit")
		{
			OP("See You~ ");
			ShowTime();
			Delay(1500);
			break;
		}
		else if (str == "-h" || str == "-H")
		{
			OP("Sorry, Building ~");
			SystemPause();
			continue;
		} 
		else if (str == "time")
		{
			ShowTime();
			continue;
		}
			
		
		if (SD_NO_FIND == mainRoute.HandleInputString(str))
		{
			OP("无效的输入 ");
			SystemPause();
		}
	}

	return 0;
}