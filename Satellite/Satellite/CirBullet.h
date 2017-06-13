#pragma once
#include "Point.h"
struct CirBullet
{
	Point m_Pos;
	Point m_Dir;
	float m_Speed;

	bool isShow;

	char ID;


	CirBullet();
	~CirBullet();

	void Oncreat(const Point& pos, const Point& dir,float speed) {
		m_Pos = pos;
		m_Dir = dir;
		m_Speed = speed;

		float enemytmpradian = (2 * PI + atan2(dir.y, dir.x));
		int asdf = enemytmpradian / DIVIDE_RADIAN;

		asdf %= DIVIDE_N;
		ID = asdf;
	}
	void Update();
};

