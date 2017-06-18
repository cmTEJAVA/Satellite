#include "stdafx.h"
#include "LaserBullet.h"


LaserBullet::LaserBullet()
{
	isShow = true;
}


LaserBullet::~LaserBullet()
{
}

void LaserBullet::Oncreat(Point * unit)
{
	m_time = 0;
	m_maxtime = lasermaxtime;
	m_ptrUnit = unit;
	isShow = true;
}

void LaserBullet::Update()
{
	m_time++;
	if (m_maxtime <= m_time) {
		isShow = false;
	}

}

