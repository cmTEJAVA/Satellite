#include "stdafx.h"
#include "GameObject.h"

CGameObject::CGameObject()
{
}

CGameObject::~CGameObject()
{
}

void CGameObject::Paint_Nemo(HDC hdc, int color)
{
	
	Rectangle(hdc, m_x - m_sizex, m_y - m_sizey
		, m_x + m_sizex, m_y + m_sizey);

}

void CGameObject::Rotate(float center_x, float center_y
	, float center_size_x, float center_size_y)
{
	m_x = center_x + (center_size_x * cos(RADIAN(angle)));
	m_y = center_y + (center_size_y * sin(RADIAN(angle)));
}

void CGameObject::Update(float frame_time)
{
	m_x += dir_x * frame_time * m_spd;
	m_y += dir_y * frame_time * m_spd;
}
