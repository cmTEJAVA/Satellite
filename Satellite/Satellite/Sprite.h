#pragma once
#include "BitmapObject.h"
class CSprite :
	public CBitmapObject
{
	int m_framenum;
	float m_oneframetime;
	float m_updatetime;
	int m_drawframenum;
	POINT m_spritesize;
public:
	CSprite();
	~CSprite();
	void OnCreatSprite(float rate,int imgN,float frametime) {
		
		//if(!m_bmp){error!}
		//OnCreatCimg먼저 할것

		m_framenum = imgN;
		m_oneframetime = frametime;
		m_spritesize = POINT{ m_bmpsize.x / imgN ,m_bmpsize.y };
		RECT rctmp{ -m_spritesize.x / 2,-m_spritesize.y / 2 ,(m_spritesize.x ) / 2,(m_spritesize.y) / 2 };
		SetObjRECT(rctmp);
		Setsizerate(rate);
	}
	virtual void draw(HDC hdc) override;
	bool Update(float time = 0.2);

	bool drawRotatImage(HDC hdc, double dblAngle);

};

