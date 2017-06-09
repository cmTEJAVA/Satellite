#include "stdafx.h"
#include "Button.h"


Cbutton::Cbutton():m_bon(false),m_bselect(false)
{
}


Cbutton::~Cbutton()
{
}

void Cbutton::draw(HDC hdc)
{
	auto rctmp = GetObjRECT();


	if(m_cimg.IsNull())
		FillRect(hdc, &rctmp, (HBRUSH)GetStockObject(GRAY_BRUSH));
	else {
		CBitmapObject::draw(hdc);
	}

}

void Cbutton::SetMouseMove(const POINT & mouse)
{
	RECT tmp = GetObjRECT();
	SetOn(false);

	if (PtInRect(&tmp, mouse)) {
		SetOn(true);
	}
}

void Cbutton::SetMouseLUp(const POINT & mouse)
{
	RECT tmp = GetObjRECT();
	SetOn(false);
	Setselect(false);

	if (PtInRect(&tmp, mouse)) {
		SetOn(true);
		Setselect(true);
	}
}
