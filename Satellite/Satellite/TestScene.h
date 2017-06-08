#pragma once
#include "Scene.h"
#include "Player.h"
#include "Button.h"
class CTestScene :
	public CScene
{
	CBitmapObject		m_bmp_backimg;
	CSprite				m_test_sprite;
	CPlayer				m_test_player;

	Cbutton				m_arrbutton[2];
	RECT				m_rcClient;
public:
	CTestScene();
	virtual ~CTestScene();
	virtual void Update() override;

	virtual void Draw(HDC hDC)override;
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

	virtual void ReleaseObjects()override;
};

