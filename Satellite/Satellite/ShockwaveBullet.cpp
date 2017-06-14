#include "stdafx.h"
#include "ShockwaveBullet.h"


ShockwaveBullet::ShockwaveBullet()
{
	m_isShow = true;
}


ShockwaveBullet::~ShockwaveBullet()
{
}

void ShockwaveBullet::Oncreat(Point * unit, int size)
{
	m_ptrUnit = unit;
	m_size = size;
	m_isShow = true;
}
