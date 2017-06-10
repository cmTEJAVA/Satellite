#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy()
{
	m_fRadianUnit = 0;
	m_Speed = 1;
	m_isShow = true;
}


CEnemy::~CEnemy()
{
}

void CEnemy::Update()
{
	m_Dir = m_tergetPos- m_Pos;
	m_Dir.normalize();

	m_Pos += m_Dir*m_Speed;
}