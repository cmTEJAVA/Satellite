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

	//�޼����� ó�� ���� �ʾ����� false�� ��ȯ
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CScene* pparentScene, HWND hWnd) override;

};

