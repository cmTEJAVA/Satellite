#pragma once
#include "Scene.h"
#include "BitmapObject.h"


class CLogoScene :
	public CScene
{
public:
	CLogoScene();
	~CLogoScene() override;

	void Update() override;

	void Draw(HDC hDC) override;

	bool Keyboard(UINT message, WPARAM wParam ) override;

	bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	bool Initialize(CGameFrameWork* pFramework, HWND hWnd) override;

	void ReleaseObjects() override;

private:
	float m_fFade{ 0.f };
	float m_fMaxFade{ 2.f };
	
	CBitmapObject	m_bmplogo;

};

