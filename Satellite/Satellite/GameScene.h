#pragma once
#include "Scene.h"
#include "Player.h"
#include "Button.h"
#include "Bullet.h"
#include <list>
#include <vector>

class CGameScene :
	public CScene
{
	CBitmapObject		m_bmp_backimg;

	CPlayer				m_test_player;

	LPCTSTR				m_arrUnitszPath[int(ENUM_UNIT::END)];
	std::list<CUnit>	m_listUnits;
	std::list<CBullet>	m_listBullets;
	std::vector<int>	m_vOrbit;

	Cbutton				m_arrbutton[2];
	RECT				m_rcClient;

	void plusUnit(ENUM_UNIT ID,int sizeOrbit) {
		switch (ID)
		{
		case ENUM_UNIT::BULLET_UNIT:
			m_listUnits.push_back(CUnit{});
			m_listUnits.back().OnCreatUnit(
				Point{ m_rcClient.right / 2 ,m_rcClient.bottom / 2 }, sizeOrbit,
				m_arrUnitszPath[int(ENUM_UNIT::BULLET_UNIT)],
				0.8f, 1, 0.6f, 0.01f, 0.02f
				);
			break;
		case ENUM_UNIT::TESLA_UNIT:
			m_listUnits.push_back(CUnit{});
			m_listUnits.back().OnCreatUnit(
				Point{ m_rcClient.right / 2 ,m_rcClient.bottom / 2 }, sizeOrbit,
				m_arrUnitszPath[int(ENUM_UNIT::TESLA_UNIT)],
				0.7f, 1, 0.6f, 0.01f, 0.02f
				);
			break;
		default:
			break;
		}
	}

public:
	CGameScene();
	virtual ~CGameScene();
	virtual void Update() override;

	virtual void Draw(HDC hDC)override;
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

	virtual void ReleaseObjects()override;
};

