#pragma once
#include "Scene.h"
#include "Player.h"
#include "Button.h"
#include "Bullet.h"
#include <list>

class CGameScene :
	public CScene
{
	CBitmapObject		m_bmp_backimg;

	CPlayer				m_test_player;
	CPlayer				m_destroyed_player;

	LPCTSTR				m_arrUnitszPath[int(ENUM_UNIT::END)];
	std::list<CUnit>	m_listUnits;
	std::list<CBullet>	m_listBullets;

	Cbutton				m_arrbutton[2];
	RECT				m_rcClient;


public:
	CGameScene();
	virtual ~CGameScene();
	virtual void Update() override;

	virtual void Draw(HDC hDC)override;
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

	virtual void ReleaseObjects()override;
};

