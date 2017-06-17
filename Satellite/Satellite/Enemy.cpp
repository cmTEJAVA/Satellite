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
	m_isTesla = false;
}


CEnemy::~CEnemy()
{
	if (m_tergetBullet) {
		m_tergetBullet->m_isShow = false;
		m_tergetBullet->m_ptrEnemy = nullptr;
	}
}

void CEnemy::Oncreat(int size, const Point & pos, const Point & tergetPos, float speed, float radianspeed)
{
	m_fradianspeed = radianspeed;
	m_Pos = pos;
	m_tergetPos = tergetPos;
	m_Speed = speed;
	m_size = size;
	m_life = 1;

	SetSprite(20, 2);
	SetSprite_Tesla(5, 2);

	Point enmytmp = m_Pos;
	enmytmp = enmytmp - m_tergetPos;
	float enemytmpradian = (2 * PI + atan2(enmytmp.y, enmytmp.x));
	int asdf = enemytmpradian / DIVIDE_RADIAN;

	asdf %= DIVIDE_N;
	ID = asdf;


	float ID2floatradian = DIVIDE_RADIAN*((float)ID + 0.5f);
	if (enemytmpradian > 2 * PI) {
		enemytmpradian -= 2 * PI;
	}

	ID2 = (enemytmpradian < ID2floatradian ? ID - 1 : ID + 1);
	ID2 = (ID2 + DIVIDE_N) % DIVIDE_N;

	m_isterget = false;


}

void CEnemy::Update()
{
	if (m_isTesla) {
		
		damage(0.003);

		if (m_Shockframenum >= 1) {
			
			m_Shockupdatetime++;
			if (m_Shockupdatetime > m_Shockoneframetime) {
				m_Shockupdatetime = 0;
				m_Shockdrawframenum++;

			}
			if (m_Shockdrawframenum >= m_Shockframenum) {
				m_Shockdrawframenum = 0;
				m_ShockMaxTime--;
				if (m_ShockMaxTime <= 0) {
					m_isTesla = false;
				}
				return;

			}
		}
	}
	
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

		if (m_life > 0.5&&(a1.x <= a2.x|| a1.y >= a2.y)) {

		}
		else {


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

		}



		SelectObject(hdc, oldbr);
		SelectObject(hdc, oldpen);
		DeleteObject(hpen); hpen = nullptr;
	}
}

void CEnemy::SetTeslaShock() {
	//PlaySound(L"sound/tesla sound.wav", NULL, SND_ASYNC);
	m_isTesla = true;
	m_ShockMaxTime = 4;
}