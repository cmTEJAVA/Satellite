#pragma once
#include "Point.h"

class Sound_Func;


struct ShockwaveBullet
{

	Point * m_ptrUnit;
	int m_size;
	bool m_isShow;

	float m_fradian;

	Sound_Func* m_ptrSound;


	ShockwaveBullet();
	~ShockwaveBullet();

	void Oncreat(Sound_Func* ptrS,Point * unit, int size =50);
	void Update();
	void draw(HDC hdc);
};

