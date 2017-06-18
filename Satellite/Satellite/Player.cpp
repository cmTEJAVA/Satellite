#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	m_isDamage = false;
}


CPlayer::~CPlayer()
{
}

void CPlayer::draw(HDC hdc)
{
	CUnit::draw(hdc);


	HBRUSH oldbr = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
	HPEN hpen = CreatePen(PS_SOLID, 2, RGB(0, 150, 255));
	HPEN oldpen = (HPEN)SelectObject(hdc, hpen);
	POINT tmp = m_imgUnit.Getpos().GetPOINT();
//	tmp.x += 1;
	int size = m_imgUnit.GetspriteWH().x;
	size /= 2;
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

void CPlayer::Update()
{
	CUnit::Update();
}
