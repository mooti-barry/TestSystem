#include "../stdafx.h"
#include "baseroute.h"

CBaseRoute::CBaseRoute()
{
	_pPartent = NULL;
}
CBaseRoute::~CBaseRoute()
{
	if (_pPartent)
		_pPartent->RemoveChild(this);
}
bool CBaseRoute::Create(CBaseRoute* pParent)
{
	if (pParent)
	{
		pParent->AddChild(this);
		_pPartent = pParent;
	}
	OnCreate();
		
	return true;
}
CBaseRoute* CBaseRoute::GetParent()
{
	return _pPartent;
}
std::string CBaseRoute::GetRouteName()
{
	return _sName;
}

//protected
void CBaseRoute::OnCreate()
{

}
void CBaseRoute::AddChild(CBaseRoute* pChild)
{
	if (find(_vChild.begin(), _vChild.end(), pChild) != _vChild.end())
		_vChild.push_back(pChild);
}
void CBaseRoute::RemoveChild(CBaseRoute* pChild)
{
	auto it = find(_vChild.begin(), _vChild.end(), pChild);
	if (it != _vChild.end())
		_vChild.erase(it);
}

