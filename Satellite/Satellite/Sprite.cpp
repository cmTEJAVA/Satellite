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
	HDC memDC;
	HBITMAP hOldBitmap;

	memDC = CreateCompatibleDC(hdc);
	hOldBitmap = (HBITMAP)SelectObject(memDC, m_bmp);


	RECT rctmp = GetObjRECT();
	TransparentBlt(hdc,
		rctmp.left, rctmp.top,
		rctmp.right - rctmp.left, rctmp.bottom - rctmp.top
		, memDC
		, m_spritesize.x*(m_drawframenum), 0
		, m_spritesize.x, m_spritesize.y
		, m_delRGB);

	SelectObject(memDC, hOldBitmap);
	DeleteDC(memDC);





}

void CSprite::draw(HDC hdc, POINT q)
{
	HDC memDC;
	HBITMAP hOldBitmap;

	memDC = CreateCompatibleDC(hdc);
	hOldBitmap = (HBITMAP)SelectObject(memDC, m_bmp);


	RECT rctmp = GetObjRECT();
	TransparentBlt(hdc,
		q.x+rctmp.left, q.y+rctmp.top,
		rctmp.right - rctmp.left, rctmp.bottom - rctmp.top
		, memDC
		, m_spritesize.x*(m_drawframenum), 0
		, m_spritesize.x, m_spritesize.y
		, m_delRGB);

	SelectObject(memDC, hOldBitmap);
	DeleteDC(memDC);
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