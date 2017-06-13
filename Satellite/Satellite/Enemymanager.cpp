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
		if (!PtInRect(&m_rcClient, enemy.m_Pos.GetPOINT())) continue;

		enemy.UpdateDraw();
		//m_imgEnemy.draw(hdc, enemy.GetDrawRECT());
		m_imgEnemy.draw(hdc, enemy.GetDrawRECT(), enemy.m_fRadianUnit);
		enemy.Drawlife(hdc);
	}
}

void CEnemymanager::Update()
{
	for (auto& enemy : m_listEnemys)
	{
		enemy.Update();
	}
}
