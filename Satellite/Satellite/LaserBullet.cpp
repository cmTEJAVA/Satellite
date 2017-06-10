#include "stdafx.h"
#include "LaserBullet.h"


LaserBullet::LaserBullet()
{
}


LaserBullet::~LaserBullet()
{
}

void LaserBullet::Update()
{
	m_time++;
	if (m_maxtime <= m_time) {
		isShow = false;
	}

}

