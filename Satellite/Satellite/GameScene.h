#pragma once
#include "Scene.h"
#include "Player.h"
#include "Button.h"
#include "BulletManager.h"
#include "Enemymanager.h"
#include "MoneyManager.h"
#include <list>
#include <vector>

#define DAMAGE_SHAKE_TIME (3*PI*2)
#define DAMAGE_SHAKE_TERM 0.7

#define MAX_TIME_STAGE_LEVEL_UP 20
#define MAX_LEVEL_SPEED 5.f

class Sound_Func;

class CGameScene :
	public CScene
{
	Sound_Func			*snd_game;

	CImage				m_bmp_backimg;

	CPlayer				m_test_player;

	LPCTSTR				m_arrUnitszPath[int(ENUM_UNIT::END)];
	std::list<CUnit>	m_listUnits;

	CBulletManager  	m_BulletManager;
	CEnemymanager	 	m_EnemyManager;
	CMoneyManager	 	m_MoneyManager;



	std::vector<int>	m_vOrbit;
	std::vector<int>	m_vOrbitUnitN;

	unsigned char		m_stageLevel;
	unsigned char		m_time_stageLevel_UP;// SHAKE_TIME;



	float				m_shake_radian;// SHAKE_TIME;

	Cbutton				m_arrbutton[2];
	RECT				m_rcClient;

	bool				m_bPause;

	size_t m_Gametime;
	size_t m_Gametime_for_stage;

	void plusUnit(ENUM_UNIT ID, const Point& pos);

	void plusBullet(ENUM_BULLET id, const Point& pos, const Point& dir) {
		m_BulletManager.insertbullet(id, pos, dir, 5.f);
	}
	void plusEnemy() {
		m_EnemyManager.insertEnemy(rand()%5/10+0.5f+((float)m_stageLevel/ (float)MAX_TIME_STAGE_LEVEL_UP)*MAX_LEVEL_SPEED);
	}

	void Update_stageLevel();


public:
	CGameScene();
	virtual ~CGameScene();
	virtual void Update() override;

	virtual void Draw(HDC hDC)override;
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd)override;

	virtual void ReleaseObjects()override;

	virtual void snd_init(Sound_Func *ptrs) override;
};

