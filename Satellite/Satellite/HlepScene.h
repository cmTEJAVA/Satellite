#pragma once
#include "Scene.h"
#include "BitmapObject.h"
#define HLEP_IMG_N 3
class CHlepScene :
	public CScene
{
	CBitmapObject m_bmphlep[HLEP_IMG_N];
	size_t m_sizehlepindx;
public:
	CHlepScene();
	virtual ~CHlepScene()override;
	virtual void Update()override;
	virtual void Draw(HDC hDC)override;
	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;
	void InitSScene(CScene *pt) {
		m_ptparentScene = pt;
	}
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;
};

