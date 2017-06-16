#pragma once
#include "Point.h"
#include "Enemy.h"
class TeslaLaser
{
	CEnemy * m_ptrEnemy;//End;
	Point m_pos;
	float m_speed;
public:
	bool m_isShow;
	TeslaLaser();
	~TeslaLaser();
	void draw(HDC hdc);
	void update();
};

