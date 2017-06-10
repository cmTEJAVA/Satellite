#pragma once
#include "Point.h"
#include "Unit.h"
struct LaserBullet
{

	Point * m_ptrUnit;
	int m_maxtime;
	int m_time;
	bool isShow;

	LaserBullet();
	~LaserBullet();

	void Oncreat(Point * unit,int maxtime=10) {
		m_time = 0;
		m_maxtime = maxtime;
		m_ptrUnit = unit;
	}
	void Update();
};

