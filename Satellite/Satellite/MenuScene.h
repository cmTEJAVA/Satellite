#pragma once
#include "Scene.h"
#include "BitmapObject.h"
class CMenuScene :
	public CScene
{
	CBitmapObject m_backbmp;
public:
	CMenuScene();
	virtual ~CMenuScene()override;
	virtual void Update()override;
	virtual void Draw(HDC hDC)override;
	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

};

