#pragma once
#include "Scene.h"
#include "Player.h"
#include "Button.h"
#include "BulletManager.h"
#include "Enemymanager.h"
#include "MoneyManager.h"
#include <list>
#include <vector>

class Sound_Func;

class CGameScene :
	public CScene
{
	Sound_Func			*snd_game;

	CBitmapObject		m_bmp_backimg;

	CPlayer				m_test_player;

	LPCTSTR				m_arrUnitszPath[int(ENUM_UNIT::END)];
	std::list<CUnit>	m_listUnits;

	CBulletManager  	m_BulletManager;
	CEnemymanager	 	m_EnemyManager;
	CMoneyManager	 	m_MoneyManager;


	std::vector<int>	m_vOrbit;
	std::vector<int>	m_vOrbitUnitN;

	unsigned char		m_stageLevel;

	Cbutton				m_arrbutton[2];
	RECT				m_rcClient;

	bool m_bPause;

	size_t m_Gametime;
	size_t m_Gametime_for_stage;

	void plusUnit(ENUM_UNIT ID, const Point& pos);

	void plusBullet(ENUM_BULLET id, const Point& pos, const Point& dir) {
		m_BulletManager.insertbullet(id, pos, dir, 5.f);
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

