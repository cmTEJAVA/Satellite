#include "stdafx.h"
#include "ShockwaveBullet.h"
#include "operator.h"

ShockwaveBullet::ShockwaveBullet()
{
	m_isShow = true;
	m_fradian = 0;
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
void ShockwaveBullet::Update()
{
	m_fradian += 0.2;
	if (m_fradian >= PI * 2) m_fradian = 0;
}
void ShockwaveBullet::draw(HDC hdc)
{
	HBRUSH oldbr = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

	HPEN hpen = CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
	HPEN oldpen = (HPEN)SelectObject(hdc, hpen);

	int sinsize = 1+sin(m_fradian)*6;
	RECT tmp{ -(m_size+sinsize) ,-(m_size + sinsize) ,(m_size + sinsize) ,(m_size + sinsize) };
	tmp += m_ptrUnit->GetPOINT();

	Ellipse(hdc, tmp.left, tmp.top, tmp.right, tmp.bottom);


	SelectObject(hdc, oldpen);
	DeleteObject(hpen);

	SelectObject(hdc, oldbr);

}
