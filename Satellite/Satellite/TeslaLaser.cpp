#include "stdafx.h"
#include "TeslaLaser.h"


TeslaLaser::TeslaLaser()
{
//	m_isShow = true;
	m_speed = 2;

}


TeslaLaser::~TeslaLaser()
{
}

void TeslaLaser::draw(HDC hdc)
{
	if (!m_isShow) return;

	HPEN hpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldpen = (HPEN)SelectObject(hdc, hpen);

	MoveToEx(hdc, m_pos.x, m_pos.y, nullptr);
	Point tmp = m_ptrEnemy->m_Pos - m_pos;
	tmp.normalize();
	tmp = tmp * 10;
	tmp = tmp + m_pos;

	LineTo(hdc, tmp.x, tmp.y);

	SelectObject(hdc, oldpen);
	DeleteObject(hpen);
}

void TeslaLaser::update()
{
	if (!m_isShow) return;

	Point dir = m_ptrEnemy->m_Pos - m_pos;
	if (dir.length()<10) {
		m_isShow = false;
		m_ptrEnemy->m_isterget = false;
		m_ptrEnemy->m_tergetBullet = nullptr;
		m_ptrEnemy->damage(0.02);
		return;
	}
	dir.normalize();
	dir = dir*m_speed;
	m_pos = m_pos + dir;

}
