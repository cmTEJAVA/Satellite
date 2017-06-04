#pragma once
#include "GameObject.h"
class CBitmapObject :
	public CGameObject
{
protected:

	HBITMAP m_bmp;
	POINT m_bmpsize;
	COLORREF m_delRGB;

public:
	CBitmapObject();
	~CBitmapObject();

	void OnCreatbmp(const HBITMAP& inbmp, COLORREF indel) {
		m_bmp = inbmp;
		m_delRGB = indel;

		BITMAP bit;
		GetObject(m_bmp, sizeof(BITMAP), &bit);
		m_bmpsize.y = bit.bmHeight;
		m_bmpsize.x = bit.bmWidth;
		SetObjRECT(RECT{ -(m_bmpsize.x) / 2,-(m_bmpsize.y) / 2
						,(m_bmpsize.x) / 2,(m_bmpsize.y) / 2 });

	}
	virtual void draw(HDC hdc) override;


};

