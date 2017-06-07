#pragma once
#include "Scene.h"
#include "BitmapObject.h"
#include "Cbutton.h"
#include <vector>

class CMenuScene :
	public CScene
{
	CBitmapObject m_backbmp;
	CBitmapObject m_titletextpng;

	std::vector<Cbutton> m_listbutton;

	float m_fradian;
	
public:
	CMenuScene();
	virtual ~CMenuScene()override;
	virtual void Update()override;
	virtual void Draw(HDC hDC)override;
	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

};

