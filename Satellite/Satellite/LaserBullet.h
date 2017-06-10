#pragma once
#include "Point.h"
#include "Unit.h"
struct LaserBullet
{

	CUnit * m_ptrUnit;
	bool isShow;

	LaserBullet();
	~LaserBullet();

	void Oncreat(CUnit * unit) {
		m_ptrUnit = unit;
	}
	void Update();
};

