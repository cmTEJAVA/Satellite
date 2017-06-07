#pragma once
#include "Scene.h"
#include "BitmapObject.h"
#include "Button.h"
#define HELP_IMG_N 3
class CHELPScene :
	public CScene
{
	CBitmapObject m_bmpHELP[HELP_IMG_N];
	size_t m_sizeHELPindx;

	Cbutton m_arrbutton[3];//0:< 1:> 2:menu

public:
	CHELPScene();
	virtual ~CHELPScene()override;
	virtual void Update()override;
	virtual void Draw(HDC hDC)override;
	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;
};

