#pragma once
#include "Point.h"
#include "Unit.h"

#define lasermaxtime 50

struct LaserBullet
{

	Point * m_ptrUnit;
	int m_maxtime;
	int m_time;
	bool isShow;

	LaserBullet();
	~LaserBullet();

	void Oncreat(Point * unit);
	void Update();
};

