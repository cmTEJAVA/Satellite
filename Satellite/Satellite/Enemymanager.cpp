#include "stdafx.h"
#include "Enemymanager.h"
#include "Point3.h"
#include "Sound.h"


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
		m_imgEnemy.draw(hdc, enemy.GetDrawRECT(),enemy.m_drawframenum);
		//m_imgEnemy.draw(hdc, enemy.GetDrawRECT(), enemy.m_fRadianUnit);
		enemy.Drawlife(hdc);
		if (enemy.m_isTesla) {
			m_imgEnemyTesla.draw(hdc, enemy.GetDrawRECT(), enemy.m_Shockdrawframenum);
		}
	}
}

void CEnemymanager::Update()
{
	for (auto& enemy : m_listEnemys)
	{
		enemy.Update();

		if (enemy.GetTeslaSound()) {
			m_ptrSound->Play_effect(ENUM_SOUND::TESLA);
		}

	}
	auto tmp = m_listEnemys.size();
	m_listEnemys.remove_if([](CEnemy& enemy) {return !enemy.m_isShow; });
	tmp -= m_listEnemys.size();
	if (tmp > 0)
		m_ptrSound->Play_effect(ENUM_SOUND::EXPLOSION);
	m_delN += tmp;
	//m_listEnemys.remove_if([](CEnemy& enemy) {return !enemy.m_isShow; });

}

bool CEnemymanager::damageCirBullet(CirBullet * ptrbullet) {
	for (auto &enemy : m_listEnemys) {
		if (!PtInRect(&m_rcClient, enemy.m_Pos.GetPOINT())) continue;
		if (!enemy.istrueOnID(ptrbullet->ID))continue;
		float tmpdistance;
		tmpdistance = ptrbullet->m_Pos.distance(enemy.m_Pos);
		if (tmpdistance <= enemy.m_size) {
			enemy.damage(ATK_UNIT_B);
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
			enemy.damage(ATK_UNIT_L);
		}


	}
}

void CEnemymanager::damageShockBullet(Point bullet, int size)
{

	for (auto &enemy : m_listEnemys) {
		if (!PtInRect(&m_rcClient, enemy.m_Pos.GetPOINT())) continue;

		float tmpdistance;
		tmpdistance = bullet.distance(enemy.m_Pos);
		if (tmpdistance <= enemy.m_size+ size) {
			enemy.damage(ATK_UNIT_S);
			Point3 tmpdir;
			tmpdir.x = enemy.m_Pos.x- m_tergetPos.x;
			tmpdir.y= enemy.m_Pos.y- m_tergetPos.y;
			tmpdir=tmpdir.cross(Point3{ 0.f,0.f,1.f });
			enemy.SetUnitMove(Point{ tmpdir.x,tmpdir.y }, 20);
			continue;
		}


	}
	return;
}

void CEnemymanager::targetTeslaBullet(Point bullet, int size, std::list<TeslaLaser>* v_laser)
{
	Point midpt{ WIDTH / 2,HEIGHT / 2 };
	Point bullettmppos{ bullet };

	for (auto &enemy : m_listEnemys) {
		if (!PtInRect(&m_rcClient, enemy.m_Pos.GetPOINT())) continue;
		if (enemy.m_isterget) continue;
		if (enemy.m_isTesla) continue;
		float tmpdistance;
		tmpdistance = bullet.distance(enemy.m_Pos);
		if (tmpdistance <= enemy.m_size + size) {
			

			Point tmp = enemy.m_Pos - bullettmppos;
			Point tmpbullet = bullet- midpt;
			tmp.normalize();
			tmpbullet.normalize();
			if (tmp.inner(tmpbullet) < cos(PI/4)) continue;


			enemy.m_isterget = true;
			v_laser->push_back(TeslaLaser());
			v_laser->back().OnCreat(&enemy, bullet, 7.f);
			enemy.m_tergetBullet = &v_laser->back();

		}
//			enemy.damage(0.005);
//			Point3 tmpdir;
//			tmpdir.x = enemy.m_Pos.x - m_tergetPos.x;
//			tmpdir.y = enemy.m_Pos.y - m_tergetPos.y;
//			tmpdir = tmpdir.cross(Point3{ 0.f,0.f,1.f });
//			enemy.SetUnitMove(Point{ tmpdir.x,tmpdir.y }, 20);
//			continue;
//		}


	}

}
