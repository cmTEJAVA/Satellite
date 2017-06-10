#include "stdafx.h"
#include "BitmapObject.h"


CBitmapObject::CBitmapObject()
{
	m_delRGB = RGB(255, 0, 255);
	m_isBMP = false;
}


CBitmapObject::~CBitmapObject()
{
	m_cimg.Destroy();//명시적해제
}

void CBitmapObject::drawalpha(HDC hdc, BYTE ifalpha)
{

	RECT rctmp = GetObjRECT();
	RECT rcrsc{ 0,0,m_bmpsize.x,m_bmpsize.y };

	m_cimg.AlphaBlend(hdc, rctmp,rcrsc, ifalpha,0);

}

void CBitmapObject::draw(HDC hdc)
{

	RECT rctmp = GetObjRECT();
	if (m_isBMP) {
		m_cimg.TransparentBlt(hdc, rctmp, m_delRGB);
	}
	else {

	m_cimg.Draw(hdc, rctmp);
	}
}

void CBitmapObject::draw(HDC hdc, RECT rectDest)
{
	if (m_isBMP) {
		m_cimg.TransparentBlt(hdc, rectDest, m_delRGB);
	}
	else {

		m_cimg.Draw(hdc, rectDest);
	}
}
