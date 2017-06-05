#include "stdafx.h"
#include "Sprite.h"


CSprite::CSprite()
{

	m_framenum = 0;
	m_oneframetime = 0;
	m_drawframenum = 0;
	m_updatetime = 0;
}


CSprite::~CSprite()
{
}

void CSprite::draw(HDC hdc)
{
	RECT rctmp = GetObjRECT();

	m_cimg.Draw(hdc,
		rctmp.left, rctmp.top,
		rctmp.right - rctmp.left, rctmp.bottom - rctmp.top

		, m_spritesize.x*(m_drawframenum), 0
		, m_spritesize.x, m_spritesize.y
		);




}

bool CSprite::Update(float time)
{
	m_updatetime += time;
	if (m_updatetime > m_oneframetime) {
		m_updatetime = 0;
		m_drawframenum++;

	}
	if (m_drawframenum >= m_framenum) {
		m_drawframenum = 0;
		return false;

	}
	return true;
}