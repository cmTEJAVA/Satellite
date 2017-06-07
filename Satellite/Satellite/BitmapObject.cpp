#include "stdafx.h"
#include "BitmapObject.h"


CBitmapObject::CBitmapObject()
{
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
	m_cimg.Draw(hdc, rctmp);
}
