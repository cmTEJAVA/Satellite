#include "stdafx.h"
#include "Enemymanager.h"


CEnemymanager::CEnemymanager()
{
}


CEnemymanager::~CEnemymanager()
{
}

void CEnemymanager::draw(HDC hdc)
{

	for (auto& enemy : m_listEnemys)
	{
		//m_imgEnemy.SetPos(enemy.m_Pos);
		m_imgEnemy.draw(hdc, enemy.GetDrawRECT(), enemy.m_fRadianUnit);
	}
}

void CEnemymanager::Update()
{
	for (auto& enemy : m_listEnemys)
	{
		enemy.Update();
	}
}
