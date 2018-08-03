#pragma once
#include <vector>
#include <string>
#include "../system_def.h"
class CBaseRoute
{
public:
	CBaseRoute();
	~CBaseRoute();

	virtual bool Create(CBaseRoute* pParent);
	virtual void ShowRoute(){}
	virtual int HandleInputString(std::string str){ return app_system::SD_NO_FIND; }
	std::string GetRouteName();
	CBaseRoute* GetParent();



protected:
	virtual void OnCreate();
	void AddChild(CBaseRoute* pChild);
	void RemoveChild(CBaseRoute* pChild);
	std::string _sName;

private:
	CBaseRoute* _pPartent;
	std::vector<CBaseRoute*> _vChild;
};