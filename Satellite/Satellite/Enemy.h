#pragma once
#include "Point.h"
class CEnemy 
{

	float		m_fradianspeed;
	Point		m_Dir;
	Point		m_tergetPos;
	float		m_Speed;

public:
	bool m_isShow;
	int			m_size;
	Point		m_Pos;
	float		m_fRadianUnit;
	CEnemy();
	~CEnemy();

	void Oncreat(int size,const Point& pos, const Point& tergetPos, float speed
		, float radianspeed = 0.01
		) {
		m_fradianspeed = radianspeed;
		m_Pos = pos;
		m_tergetPos = tergetPos;
		m_Speed = speed;
		m_size = size;
	}
	void SetTergetPos(const Point& pos) {
		m_tergetPos = pos;
	}
	void Update();
	RECT GetDrawRECT() {
		return RECT{
			LONG(m_Pos.x-m_size),
			LONG(m_Pos.y-m_size),
			LONG(m_Pos.x+m_size),
			LONG(m_Pos.y+m_size)

		};
	}

};

