#pragma once
#include "Scene.h"
#include "Sprite.h"
class CTestScene :
	public CScene
{
	CSprite m_test_sprite;
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

