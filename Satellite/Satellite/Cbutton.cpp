#include "stdafx.h"
#include "Cbutton.h"


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
		m_cimg.Draw(hdc, rctmp);
	}

}
