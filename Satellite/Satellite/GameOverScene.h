#pragma once
#include "Scene.h"
#include "BitmapObject.h"
#include "Button.h"

#define GameOver_IMG_N 2

class CGameOverScene :
	public CScene
{
	CBitmapObject m_bmpGameOver;
	size_t m_sizeGameOverindx;

	Cbutton m_arrbutton[2];//0:menu 1:exit

	RECT rcClient;


public:
	CGameOverScene();
	virtual ~CGameOverScene()override;
	virtual void Update()override;
	virtual void Draw(HDC hDC)override;
	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;
};
