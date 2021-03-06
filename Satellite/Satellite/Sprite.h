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

	const RECT NewFunction2(POINT  *arr);

public:
	CSprite();
	~CSprite();
	void OnCreatSprite(float rate,int imgN,float frametime) {
		
		//if(!m_bmp){error!}
		//OnCreatCimg���� �Ұ�

		m_framenum = imgN;
		m_oneframetime = frametime;
		m_spritesize = POINT{ m_bmpsize.x / imgN ,m_bmpsize.y };
		RECT rctmp{ -m_spritesize.x / 2,-m_spritesize.y / 2 ,(m_spritesize.x ) / 2,(m_spritesize.y) / 2 };
		SetObjRECT(rctmp);
		Setsizerate(rate);
	}
	virtual void draw(HDC hdc) override;
	void draw(HDC hdc,RECT rectDest,size_t frameN);
	bool Update(float time = 0.2);

	bool drawRotatImage(HDC hdc, float fradian);
	POINT GetspriteWH() {
		return m_spritesize;
	}
};

