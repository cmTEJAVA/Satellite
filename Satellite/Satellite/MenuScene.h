#pragma once
#include "Scene.h"
#include "BitmapObject.h"
#include "Cbutton.h"
class CMenuScene :
	public CScene
{
	CBitmapObject m_backbmp;
	CBitmapObject m_titletextpng;

	Cbutton m_testbutt;

	float m_fradian;
	
public:
	CMenuScene();
	virtual ~CMenuScene()override;
	virtual void Update()override;
	virtual void Draw(HDC hDC)override;
	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

};

