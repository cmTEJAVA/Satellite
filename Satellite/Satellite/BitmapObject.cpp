#include "stdafx.h"
#include "BitmapObject.h"


CBitmapObject::CBitmapObject():m_bmp(nullptr)
{
}


CBitmapObject::~CBitmapObject()
{
	if (m_bmp)DeleteObject(m_bmp);
}

void CBitmapObject::draw(HDC hdc)
{


	HDC memDC;
	HBITMAP hOldBitmap;

	memDC = CreateCompatibleDC(hdc);
	hOldBitmap = (HBITMAP)SelectObject(memDC, m_bmp);

	RECT rctmp = GetObjRECT();
	FillRect(hdc, &rctmp, (HBRUSH)GetStockObject(GRAY_BRUSH));
	TransparentBlt(hdc
		, rctmp.left, rctmp.top
		, rctmp.right- rctmp.left, rctmp.bottom- rctmp.top
		, memDC
		, 0, 0
		, m_bmpsize.x, m_bmpsize.y
		, m_delRGB 
	);

	
	SelectObject(memDC, hOldBitmap);
	DeleteDC(memDC);
}
