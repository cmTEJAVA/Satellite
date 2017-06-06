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
	drawRotatImage(hdc, 10);
	return;
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


bool CSprite::drawRotatImage(HDC hdc, float fradian)
{
	RECT rcSorce = GetObjRECT();
	POINT arr[3];
	NewFunction(rcSorce, arr, fradian);

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
	auto old = SelectObject(testdc, testbmp);

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
		(SelectObject(testdc, testbmp))
		;
	DeleteDC(testdc);


	DeleteObject
		(SelectObject(testdc, old))
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

void CSprite::NewFunction(RECT rcSorce, POINT  *arr, const float& fradian)
{

	POINT ptsorcepos{ rcSorce.right + rcSorce.left
		,rcSorce.bottom + rcSorce.top };
	ptsorcepos.x /= 2;
	ptsorcepos.y /= 2;
	rcSorce.left -= ptsorcepos.x;
	rcSorce.right -= ptsorcepos.x;
	rcSorce.top -= ptsorcepos.y;
	rcSorce.bottom -= ptsorcepos.y;

	arr[0] = POINT{ rcSorce.left,rcSorce.top };
	arr[1] = POINT{ rcSorce.right,rcSorce.top };
	arr[2] = POINT{ rcSorce.left,rcSorce.bottom };

	float cosx = cos(fradian);
	float sinx = sin(fradian);
	for (int i = 0; i < 3; i++) {
		auto tmp = arr[i];
		arr[i].x = tmp.x*cosx + tmp.y*sinx;
		arr[i].y = -tmp.x*sinx + tmp.y*cosx;
	}

	for (int i = 0; i < 3; i++) {
		arr[i] = arr[i] + ptsorcepos;
	}
}
