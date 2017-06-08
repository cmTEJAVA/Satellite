#pragma once
#include "ChildScene.h"
class CEditChildScene :
	public CChildScene
{
	RECT m_rcClinet;
public:
	CEditChildScene();
	virtual ~CEditChildScene() override;

	virtual void Update() override;

	virtual void Draw(HDC hDC) override;

	virtual bool Keyboard(UINT message, WPARAM wParam) override;

	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CScene* pparentScene, HWND hWnd) override;

};

