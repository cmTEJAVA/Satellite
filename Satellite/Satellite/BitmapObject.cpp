#include "stdafx.h"
#include "BitmapObject.h"


CBitmapObject::CBitmapObject()
{
}


CBitmapObject::~CBitmapObject()
{
	m_cimg.Destroy();//명시적해제
}

void CBitmapObject::draw(HDC hdc)
{


	RECT rctmp = GetObjRECT();
	m_cimg.Draw(hdc, rctmp);
}
