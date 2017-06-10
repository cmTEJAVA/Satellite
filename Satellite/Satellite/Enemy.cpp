#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy()
{
	m_fRadianUnit = 0;
	m_Speed = 1;
}


CEnemy::~CEnemy()
{
}

void CEnemy::Update()
{
	m_fRadianUnit += m_fradianspeed;
	if (m_fRadianUnit >= PI * 2) {
		m_fRadianUnit = 0;
	}

	m_Dir = m_tergetPos- m_Pos;
	m_Dir.normalize();

	m_Pos += m_Dir*m_Speed;
}
