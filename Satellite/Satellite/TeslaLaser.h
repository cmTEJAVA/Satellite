#pragma once
#include "Point.h"
#include "Enemy.h"
class TeslaLaser
{
	Point m_pos;
	float m_speed;
public:
	CEnemy *m_ptrEnemy;//End;
	bool m_isShow;
	TeslaLaser();
	~TeslaLaser();
	void OnCreat(CEnemy * ptrEnemy, Point pos, float speed) {
		m_ptrEnemy = ptrEnemy;
		m_pos = pos;
		m_speed = speed;
		m_isShow = true;
	}
	void draw(HDC hdc);
	void update();
};

