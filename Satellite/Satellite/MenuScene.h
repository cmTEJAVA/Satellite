#pragma once
#include "Scene.h"
class CMenuScene :
	public CScene
{
public:
	CMenuScene();
	virtual ~CMenuScene()override;
	virtual void Update()override;
	virtual void Draw(HDC hDC)override;
	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

};

