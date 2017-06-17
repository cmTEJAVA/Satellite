#include "stdafx.h"
#include <math.h>
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
	//drawRotatImage(hdc, 10);
	//return;
	RECT rctmp = GetObjRECT();

	if (m_isBMP) {
		m_cimg.TransparentBlt(hdc,
			rctmp.left, rctmp.top,
			rctmp.right - rctmp.left, rctmp.bottom - rctmp.top

			, m_spritesize.x*(m_drawframenum), 0
			, m_spritesize.x, m_spritesize.y
			,m_delRGB
			);

	}

	else
	m_cimg.Draw(hdc,
		rctmp.left, rctmp.top,
		rctmp.right - rctmp.left, rctmp.bottom - rctmp.top

		, m_spritesize.x*(m_drawframenum), 0
		, m_spritesize.x, m_spritesize.y
		);




}

void CSprite::draw(HDC hdc, RECT rectDest, size_t frameN)
{

	if (m_isBMP) {
		m_cimg.TransparentBlt(hdc,
			rectDest.left, rectDest.top,
			rectDest.right - rectDest.left, rectDest.bottom - rectDest.top

			, m_spritesize.x*(frameN), 0
			, m_spritesize.x, m_spritesize.y
			,m_delRGB
		);
	}
	else
	m_cimg.Draw(hdc,
		rectDest.left, rectDest.top,
		rectDest.right - rectDest.left, rectDest.bottom - rectDest.top

		, m_spritesize.x*(frameN), 0
		, m_spritesize.x, m_spritesize.y
		
		);
}

bool CSprite::Update(float time)
{
	if (m_framenum <= 1) return true;
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


bool CSprite::drawRotatImage(HDC hdc, float fradian)
{
	RECT rcSorce = GetObjRECT();
	POINT arr[3];
	NewFunction(rcSorce, arr, fradian);
	if (m_isBMP) {
		HDC transhdc = CreateCompatibleDC(hdc);
		HBITMAP transhbmp = CreateCompatibleBitmap(hdc, WIDTH, HEIGHT);
		HBITMAP oldbmp = (HBITMAP)SelectObject(transhdc, transhbmp);
		HBRUSH ff00ffbr = CreateSolidBrush(m_delRGB);
		HBRUSH oldbr = (HBRUSH)SelectObject(transhdc, ff00ffbr);

		RECT tmp{ 0,0, WIDTH, HEIGHT };
		
		FillRect(transhdc, &tmp, ff00ffbr);
		m_cimg.PlgBlt(transhdc, arr, m_spritesize.x*(m_drawframenum), 0
			, m_spritesize.x, m_spritesize.y);
		TransparentBlt(hdc, 0, 0, WIDTH, HEIGHT, transhdc, 0, 0, WIDTH, HEIGHT, m_delRGB);


		SelectObject(transhdc, oldbmp);
		SelectObject(transhdc, oldbr);
		DeleteObject(ff00ffbr);
		DeleteObject(transhbmp);
		DeleteDC(transhdc);
		//		m_cimg.TransparentBlt(hdc,)
		return true;
	}
	/*
	MoveToEx(hdc, arr[0].x, arr[0].y, nullptr);
	LineTo(hdc, arr[1].x, arr[1].y);
	MoveToEx(hdc, arr[0].x, arr[0].y, nullptr);
	LineTo(hdc, arr[2].x, arr[2].y);
	MoveToEx(hdc, arr[2].x + arr[1].x - arr[0].x,
	arr[2].y + arr[1].y - arr[0].y, nullptr);
	LineTo(hdc, arr[2].x, arr[2].y);

	*/

	RECT rcbacktmp = NewFunction2(arr);
	POINT ptbacktmpsize{ rcbacktmp.right - rcbacktmp.left,rcbacktmp.bottom - rcbacktmp.top };
	POINT backarr[3];
	NewFunction(rcbacktmp, backarr, -fradian);
	RECT rctmptest = NewFunction2(backarr);
	//±×¸®±â

	HDC testdc = CreateCompatibleDC(hdc);
	HBITMAP testbmp = CreateCompatibleBitmap(hdc, ptbacktmpsize.x, ptbacktmpsize.y);
	auto testold = SelectObject(testdc, testbmp);

	BitBlt(testdc, 0, 0, ptbacktmpsize.x, ptbacktmpsize.y, hdc, rcbacktmp.left, rcbacktmp.top, SRCCOPY);


	HDC drawSdc = CreateCompatibleDC(hdc);
	HBITMAP drawSbmp = CreateCompatibleBitmap(hdc, rcSorce.right - rcSorce.left, rcSorce.bottom - rcSorce.top);
	auto drawold = SelectObject(drawSdc, drawSbmp);


	{

		RECT asdf = NewFunction2(backarr);

		POINT pttmp{ rcSorce.right - rcSorce.left,rcSorce.bottom - rcSorce.top };
		pttmp = POINT{ asdf.right - asdf.left,asdf.bottom - asdf.top }-pttmp;
		pttmp.x /= 2;
		pttmp.y /= 2;
		pttmp.x += rctmptest.left;
		pttmp.y += rctmptest.top;

		for (int i = 0; i < 3; i++) {
			backarr[i] = backarr[i] - pttmp;
		}

	}

	PlgBlt(drawSdc, backarr, testdc, 0, 0, ptbacktmpsize.x, ptbacktmpsize.y, 0, 0, 0);



	m_cimg.Draw(drawSdc, 0, 0, rcSorce.right - rcSorce.left, rcSorce.bottom - rcSorce.top, m_spritesize.x*(m_drawframenum), 0, m_spritesize.x, m_spritesize.y);



	HDC hdcfff = CreateCompatibleDC(hdc);
	HBITMAP hbmpfff = CreateCompatibleBitmap(hdc, WIDTH, HEIGHT);
	auto oldfff = SelectObject(hdcfff, hbmpfff);



	PlgBlt(hdcfff, arr, drawSdc, 0, 0, rcSorce.right - rcSorce.left, rcSorce.bottom - rcSorce.top, 0, 0, 0);

	HPEN hpen2 = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	auto oldpen2 = SelectObject(hdcfff, hpen2);

	MoveToEx(hdcfff, arr[0].x, arr[0].y, nullptr);
	LineTo(hdcfff, arr[1].x, arr[1].y);
	MoveToEx(hdcfff, arr[0].x, arr[0].y, nullptr);
	LineTo(hdcfff, arr[2].x, arr[2].y);
	MoveToEx(hdcfff, arr[2].x + arr[1].x - arr[0].x,
		arr[2].y + arr[1].y - arr[0].y, nullptr);
	LineTo(hdcfff, arr[2].x, arr[2].y);

	DeleteObject(SelectObject(hdcfff, oldpen2));

	TransparentBlt(hdc, 0, 0, WIDTH, HEIGHT, hdcfff, 0, 0, WIDTH, HEIGHT, RGB(0, 0, 0));

	DeleteObject
		(SelectObject(hdcfff, oldfff)
			);
	DeleteDC(hdcfff);



	DeleteObject
		(SelectObject(drawSdc, drawold))
		;
	DeleteDC(drawSdc);


	DeleteObject
		(SelectObject(testdc, testold))
		;
	DeleteDC(testdc);



	//PlgBlt(hdc, arr, hdc, rcSorce.left, rcSorce.top, rcSorce.right - rcSorce.left, rcSorce.bottom - rcSorce.top, 0, 0, 0);





	return false;
}

const RECT CSprite::NewFunction2(POINT  *arr)
{
	RECT tmp{ MAXLONG,MAXLONG ,-MAXLONG,  -MAXLONG };
	POINT pttmp[4];
	for (int i = 0; i < 3; i++) {
		pttmp[i] = arr[i];
	}
	pttmp[3] = pttmp[2] + pttmp[1] - pttmp[0];
	//POINT{ arr[2].x + arr[1].x - arr[0].x
	//		,	arr[1].y + arr[2].y - arr[0].y };

	for (int i = 0; i < 4; i++) {
		if (pttmp[i].x < tmp.left) {
			tmp.left = pttmp[i].x;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (pttmp[i].x > tmp.right) {
			tmp.right = pttmp[i].x;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (pttmp[i].y < tmp.top) {
			tmp.top = pttmp[i].y;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (pttmp[i].y > tmp.bottom) {
			tmp.bottom = pttmp[i].y;
		}
	}
	return tmp;
}
