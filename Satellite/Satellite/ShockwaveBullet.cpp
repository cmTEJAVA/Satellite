#include "stdafx.h"
#include "ShockwaveBullet.h"
#include "operator.h"

ShockwaveBullet::ShockwaveBullet()
{
	m_isShow = true;
}


ShockwaveBullet::~ShockwaveBullet()
{
}

void ShockwaveBullet::Oncreat(Point * unit, int size)
{
	m_ptrUnit = unit;
	m_size = size;
	m_isShow = true;
}
void ShockwaveBullet::draw(HDC hdc)
{
	HBRUSH oldbr = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

	HPEN hpen = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
	HPEN oldpen = (HPEN)SelectObject(hdc, hpen);

	RECT tmp{ -m_size ,-m_size ,m_size ,m_size };
	tmp += m_ptrUnit->GetPOINT();

	Ellipse(hdc, tmp.left, tmp.top, tmp.right, tmp.bottom);


	SelectObject(hdc, oldpen);
	DeleteObject(hpen);

	SelectObject(hdc, oldbr);

}
