#pragma once
#include "GameObject.h"
#include <atlimage.h>
class CBitmapObject :
	public CGameObject
{
protected:
	CImage m_cimg;

	POINT m_bmpsize;

public:
	CBitmapObject();
	~CBitmapObject();

	void OnCreatCimg(const LPCTSTR& pStream) {

		m_cimg.Load(pStream);
		m_bmpsize.x = m_cimg.GetWidth();
		m_bmpsize.y = m_cimg.GetHeight();

	}
	virtual void draw(HDC hdc) override;


};

