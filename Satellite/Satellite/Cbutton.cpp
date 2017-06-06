#include "stdafx.h"
#include "Cbutton.h"


Cbutton::Cbutton()
{
}


Cbutton::~Cbutton()
{
}

void Cbutton::draw(HDC hdc)
{
	auto rctmp = GetObjRECT();
	FillRect(hdc, &rctmp, (HBRUSH)GetStockObject(GRAY_BRUSH));



}
