#include "stdafx.h"
#include "Enemy.h"
#include "TeslaLaser.h"

CEnemy::CEnemy()
{
	m_fRadianUnit = 0;
	m_Speed = 1;
	m_isShow = true;
	m_isUnitMove = false;
	ID = -1;
	ID2 = -1;


	m_framenum = 0;
	m_oneframetime = 0;
	m_drawframenum = 0;
	m_updatetime = 0;
	m_tergetBullet = nullptr;
	m_isterget = false;
}


CEnemy::~CEnemy()
{
	if (m_tergetBullet) {
		m_tergetBullet->m_isShow = false;
		m_tergetBullet->m_ptrEnemy = nullptr;
	}
}

void CEnemy::Update()
{


	if (m_isUnitMove) {
		m_Pos += m_UnitDir*m_Speed;

		if (m_UnitMovemaxTime == 0) {
			m_isUnitMove = false;
			return;
		}
		m_Dir = m_Pos-m_tergetPos;
		m_Dir.normalize();

		m_Pos += m_Dir*(m_Speed*(1-1.f/(float)m_UnitMovemaxTime));
		m_UnitMovemaxTime=max(0, m_UnitMovemaxTime-1);

	}

	if (!m_isUnitMove) {

		m_Dir = m_tergetPos - m_Pos;
		m_Dir.normalize();

		m_Pos += m_Dir*m_Speed;

		if (ID > 0) {
			if (m_Pos.distance(m_tergetPos) < g_DIVIDE_MAX_SIZE) {
				ID = -1;
			}
		}
	}



	if (m_framenum <= 1) return;
	m_updatetime++;
	if (m_updatetime > m_oneframetime) {
		m_updatetime = 0;
		m_drawframenum++;

	}
	if (m_drawframenum >= m_framenum) {
		m_drawframenum = 0;
		return;

	}
}

void CEnemy::Drawlife(HDC hdc)
{
	HBRUSH oldbr = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
	HPEN hpen = CreatePen(PS_SOLID, 2, RGB(0, 150, 255));
	HPEN oldpen = (HPEN)SelectObject(hdc, hpen);
	POINT tmp = m_Pos.GetPOINT();
	//	tmp.x += 1;
	int size = m_size;
	size = (size / 5) * 3;
	if (m_life != 0) {

		Ellipse(hdc,
			tmp.x - size,
			tmp.y - size,
			tmp.x + size,
			tmp.y + size
			);
	}

	SelectObject(hdc, oldpen);
	DeleteObject(hpen); hpen = nullptr;

	if (m_life < 1) {
		hpen = CreatePen(PS_SOLID, 2, RGB(50 + 204 * (1 - m_life), 0, 0));
		oldpen = (HPEN)SelectObject(hdc, hpen);


		float ftmp = -PI / 2;
		POINT a2{ cos(ftmp + 2 * PI*m_life)*size	,sin(ftmp + 2 * PI*m_life)*size };
		POINT a1{ cos(ftmp + 0)*size				,sin(ftmp + 0)*size };

		Arc(hdc,
			tmp.x - size,
			tmp.y - size,
			tmp.x + size,
			tmp.y + size,
			tmp.x + a1.x,
			tmp.y + a1.y,
			tmp.x + a2.x,
			tmp.y + a2.y
			);




		SelectObject(hdc, oldbr);
		SelectObject(hdc, oldpen);
		DeleteObject(hpen); hpen = nullptr;
	}
}