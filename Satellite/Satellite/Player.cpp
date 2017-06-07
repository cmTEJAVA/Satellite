#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::draw(HDC hdc)
{
	m_imgplayer.drawRotatImage(hdc, m_fradianplayer);

	HBRUSH oldbr = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
	HPEN hpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldpen = (HPEN)SelectObject(hdc, hpen);
	POINT tmp = m_imgplayer.Getpos().GetPOINT();
	tmp.x += 1;
	int size = m_imgplayer.GetspriteWH().x;
	size /= 2;
	size = (size / 5) * 4;
	Ellipse(hdc,
		tmp.x - size,
		tmp.y - size,
		tmp.x + size,
		tmp.y + size
		);

	SelectObject(hdc, oldbr);
	SelectObject(hdc, oldpen);
	DeleteObject(hpen); hpen = nullptr;

	if (m_life < 1) {
	hpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	oldpen = (HPEN)SelectObject(hdc, hpen);


	float ftmp = -PI / 2;
	POINT a2{ cos(ftmp+2 * PI*m_life)*size	,sin(ftmp+2 * PI*m_life)*size	};
	POINT a1{ cos(ftmp+0)*size				,sin(ftmp+0)*size				};
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


	SelectObject(hdc, oldpen);
	DeleteObject(hpen); hpen = nullptr;
	}

}

void CPlayer::Update()
{
	m_fradianplayer += m_fspeed;
	if (m_fradianplayer >= PI * 2) {
		m_fradianplayer = 0;
	}
	m_imgplayer.Update();
}
