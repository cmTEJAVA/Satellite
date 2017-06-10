#pragma once
#include "ChildScene.h"
#include <vector>
#include "Button.h"
#include "BitmapObject.h"
#include "GameFrameWork.h"

class CGameOverScene :
	public CChildScene
{
	RECT m_rcClient;
	CBitmapObject m_back;
	Cbutton m_button[2];
	CGameFrameWork m_FrameWork;

public:
	CGameOverScene();
	virtual ~CGameOverScene() override;

	virtual void Update() override;

	virtual void Draw(HDC hDC) override;

	//메세지가 처리 되지 않았으면 false가 반환
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CScene* pparentScene, HWND hWnd) override;

};

