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

bool CEnemymanager::damageCirBullet(CirBullet * ptrbullet) {
	for (auto &enemy : m_listEnemys) {
		if (!PtInRect(&m_rcClient, enemy.m_Pos.GetPOINT())) continue;
		if (!enemy.istrueOnID(ptrbullet->ID))continue;
		float tmpdistance;
		tmpdistance = ptrbullet->m_Pos.distance(enemy.m_Pos);
		if (tmpdistance <= enemy.m_size) {
			enemy.damage(0.2);
			return true;
		}


	}
	return false;
}

void CEnemymanager::damageLaserBullet(Point bullet) {
	Point midpt{ WIDTH / 2,HEIGHT / 2 };
	Point bullettmppos{ bullet };
	bullet = bullet - midpt;
	bullet.normalize();
	for (auto &enemy : m_listEnemys) {
		if (!PtInRect(&m_rcClient, enemy.m_Pos.GetPOINT())) continue;

		Point tmp = enemy.m_Pos;
		tmp = tmp - bullettmppos;
		//tmp.normalize();
		if (tmp.inner(bullet) < 0) continue;


		tmp = enemy.m_Pos;
		tmp = tmp - midpt;

		float distance = abs(bullet.y*tmp.x - bullet.x*tmp.y);

		//if (!enemy.istrueOnID(ptrbullet->ID))continue;
		//float tmpdistance;
		//tmpdistance = ptrbullet->m_Pos.distance(enemy.m_Pos);
		if (distance <= enemy.m_size) {
			enemy.damage(0.02);
		}


	}
}
