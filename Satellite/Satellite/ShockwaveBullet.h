#pragma once
#include "Point.h"
struct ShockwaveBullet
{

	Point * m_ptrUnit;
	int m_size;
	bool m_isShow;

	ShockwaveBullet();
	~ShockwaveBullet();

	void Oncreat(Point * unit, int size =50);

	void draw(HDC hdc);
};

