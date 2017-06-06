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
		m_rcobjsize = RECT{ 0,0,m_bmpsize.x,m_bmpsize.y };

		if (m_cimg.GetBPP() == 32)
		{
			unsigned char * pCol = 0;
			long w = m_bmpsize.x;
			long h = m_bmpsize.y;
			for (long y = 0; y < h; y++)
			{
				for (long x = 0; x < w; x++)
				{
					pCol = (unsigned char *)m_cimg.GetPixelAddress(x, y);
					unsigned char alpha = pCol[3];
					if (alpha != 255)
					{
						pCol[0] = ((pCol[0] * alpha) + 128) >> 8;
						pCol[1] = ((pCol[1] * alpha) + 128) >> 8;
						pCol[2] = ((pCol[2] * alpha) + 128) >> 8;
					}
				}
			}
			m_cimg.SetHasAlphaChannel(true);
		}

	}
	virtual void draw(HDC hdc) override;


};

