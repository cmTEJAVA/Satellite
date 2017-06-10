#pragma once
#include "Point.h"
struct CirBullet
{
	Point m_Pos;
	Point m_Dir;
	float m_Speed;

	bool isShow;

	CirBullet();
	~CirBullet();

	void Oncreat(const Point& pos, const Point& dir,float speed) {
		m_Pos = pos;
		m_Dir = dir;
		m_Speed = speed;
	}
	void Update();
};

