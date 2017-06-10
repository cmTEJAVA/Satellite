#include "stdafx.h"
#include "CirBullet.h"


CirBullet::CirBullet()
{
	m_Speed = 1.f;
	isShow = true;
}


CirBullet::~CirBullet()
{
}

void CirBullet::Update()
{
	m_Pos += m_Dir*m_Speed;

}
