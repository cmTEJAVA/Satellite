#pragma once
#include "Point.h"
#include "TeslaLaser.h"
#include <list>
struct Tesla
{

	Point * m_ptrUnit;//���� ���� ����
	int m_size;
	//float m_fradian;//���� ���� �� ����


	Tesla();
	~Tesla();
	void Oncreat(Point * unit, int size = 50);
};

