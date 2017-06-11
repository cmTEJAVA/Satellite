#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy()
{
	m_fRadianUnit = 0;
	m_Speed = 1;
	m_isShow = true;
}


CEnemy::~CEnemy()
{
}

void CEnemy::Update()
{
	m_Dir = m_tergetPos- m_Pos;
	m_Dir.normalize();

	m_Pos += m_Dir*m_Speed;
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