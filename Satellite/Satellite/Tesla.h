#pragma once
#include "Point.h"
#include "TeslaLaser.h"
#include <list>
struct Tesla
{

	Point * m_ptrUnit;//공격 시작 지점
	int m_size;
	//float m_fradian;//공격 가능 각 범위


	Tesla();
	~Tesla();
	void Oncreat(Point * unit, int size = 50);
};

