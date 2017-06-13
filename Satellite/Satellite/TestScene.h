#pragma once
#include "Scene.h"
#include "Enemy.h"
#include "operator.h"
class CTestScene :
	public CScene
{
	RECT m_rcClient;
	POINT m_ptMouse;

	CEnemy testEnemy;
	int ID;
	int ID2;
	int maxdistance;


	void insertEnemy() {
		

		Point pos{ 150,150 };
		Point tergetPos{ m_rcClient.right/2,m_rcClient.bottom/2 };

		pos.rotation(tergetPos, (rand() % 628) / 100.0f);

		testEnemy.Oncreat(
			rand() % (ENEMY_MAX_R_SIZE - 10) + 10
			, pos
			, tergetPos, 1, 0.05);

		float tmp = (2 * PI) / DIVIDE_N;
		Point pttmp{ m_rcClient.right,m_rcClient.bottom / 2 };
		Point ptmidtmp{ m_rcClient.right / 2,m_rcClient.bottom / 2 };

		Point enmytmp = testEnemy.m_Pos;
		enmytmp = enmytmp - ptmidtmp;
		float enemytmpradian = (2 * PI + atan2(enmytmp.y, enmytmp.x));
		int asdf = enemytmpradian / tmp;

		asdf %= DIVIDE_N;
		ID = asdf;


		float ID2floatradian = tmp*((float)ID + 0.5f);
		if (enemytmpradian > 2 * PI) {
			enemytmpradian -= 2 * PI;
		}
		//ID2floatradian=int(enemytmpradian*100) % int(2 * PI)*100;
		ID2 = (enemytmpradian < ID2floatradian ? ID - 1 : ID + 1);
		ID2 = (ID2) % DIVIDE_N;


	}

public:
	CTestScene();
	~CTestScene();

	virtual void Update();

	virtual void Draw(HDC hdc);

	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam);

	virtual bool Initialize(CGameFrameWork* pFramework, HWND hWnd);

	virtual void ReleaseObjects();

};

