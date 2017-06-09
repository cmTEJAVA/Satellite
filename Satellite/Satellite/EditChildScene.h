#pragma once
#include "ChildScene.h"
#include <vector>
#include "Button.h"

enum class ENUM_CHILD_MESSGE
{
	SETORBITMAX,
	SETORBITSIZE,
	SETUNITMAX,
	SETUNITPATH,
	FLASE
};

class CEditChildScene :
	public CChildScene
{
	RECT m_rcClient;
	RECT m_rcEditWindow;

	std::vector<RECT> m_vOrbit;
	
	std::vector<Cbutton>m_vUnits;

	

public:
	CEditChildScene();
	virtual ~CEditChildScene() override;

	virtual void Update() override;

	virtual void Draw(HDC hDC) override;

	virtual bool Keyboard(UINT message, WPARAM wParam) override;

	//�޼����� ó�� ���� �ʾ����� false�� ��ȯ
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CScene* pparentScene, HWND hWnd) override;

	virtual UINT GetSceneMessge(ENUM_CHILD_MESSGE message, WPARAM wParam, LPARAM lParam) override;

};

