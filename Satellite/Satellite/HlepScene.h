#pragma once
#include "Scene.h"
#include "BitmapObject.h"
#include "Button.h"
#define HLEP_IMG_N 3
class CHlepScene :
	public CScene
{
	CBitmapObject m_bmphlep[HLEP_IMG_N];
	size_t m_sizehlepindx;

	Cbutton m_arrbutton[3];//0:< 1:> 2:menu

public:
	CHlepScene();
	virtual ~CHlepScene()override;
	virtual void Update()override;
	virtual void Draw(HDC hDC)override;
	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;
};

