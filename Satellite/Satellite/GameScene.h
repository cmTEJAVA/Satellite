#pragma once
#include "Scene.h"
#include "Player.h"
#include "Button.h"
#include "BulletManager.h"
#include "Enemymanager.h"
#include <list>
#include <vector>

class CGameScene :
	public CScene
{
	CBitmapObject		m_bmp_backimg;

	CPlayer				m_test_player;

	LPCTSTR				m_arrUnitszPath[int(ENUM_UNIT::END)];
	std::list<CUnit>	m_listUnits;
	CBulletManager  	m_BulletManager;
	CEnemymanager	 	m_EnemyManager;
	std::vector<int>	m_vOrbit;

	Cbutton				m_arrbutton[2];
	RECT				m_rcClient;

	size_t m_Gametime;

	void plusUnit(ENUM_UNIT ID,const Point& pos) {

		switch (ID)
		{
		case ENUM_UNIT::BULLET_UNIT:
			m_listUnits.push_back(CUnit{});
			m_listUnits.back().OnCreatUnit(pos,
				Point{ m_rcClient.right / 2 ,m_rcClient.bottom / 2 },
				m_arrUnitszPath[int(ENUM_UNIT::BULLET_UNIT)],
				0.8f, 1, 0.6f, 0.01f, 0.02f
				);
			m_listUnits.back().SetID(ENUM_UNIT::BULLET_UNIT);
			break;
		case ENUM_UNIT::TESLA_UNIT:
			m_listUnits.push_back(CUnit{});
			m_listUnits.back().OnCreatUnit(pos,
				Point{ m_rcClient.right / 2 ,m_rcClient.bottom / 2 },
				m_arrUnitszPath[int(ENUM_UNIT::TESLA_UNIT)],
				0.7f, 1, 0.6f, 0.01f, 0.02f
				);
			m_listUnits.back().SetID(ENUM_UNIT::TESLA_UNIT);
			break;
		default:
			break;
		}
	}

	void plusBullet(ENUM_BULLET id,const Point& pos, const Point& dir) {
		m_BulletManager.insertbullet(id, pos, dir,5.f);
		//m_listBullets.push_back(CBulletManager{});
		//m_listBullets.back().OnCreate();
		//m_listBullets.back().m_bulletimg.SetPos(Point{ rand() % m_rcClient.right,rand() % m_rcClient.bottom });
	}
	void plusEnemy() {
		m_EnemyManager.insertEnemy(rand()%5/10+0.5f);
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

