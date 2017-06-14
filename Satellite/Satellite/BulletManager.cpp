#include "stdafx.h"
#include "BulletManager.h"
#include "Point3.h"

CBulletManager::CBulletManager()
{
}


CBulletManager::~CBulletManager()
{
}

void CBulletManager::draw(HDC hdc)
{
	RECT tmp=m_bullet[(int)ENUM_BULLET::STANDARD].GetObjRECT();
	for (auto &cirB : m_listCirBullet)
	{
		RECT rctmp = tmp+cirB.m_Pos.GetPOINT();
		m_bullet[0].draw(hdc, rctmp);
	}
	tmp = m_bullet[(int)ENUM_BULLET::LASER].GetObjRECT();
	for (auto &laserB : m_listLaserBullet)
	{
		Point asdf = *laserB.m_ptrUnit;
		asdf = asdf - m_ptmid;
		Point3 tmp3{ asdf.x,asdf.y,0 };
		tmp3 = tmp3.cross(Point3{ 0.f,0,1 });
		Point tmpcross2 = tmp3.GetPoint2();
		tmpcross2.normalize();
		

		POINT arr[3];

		arr[0] = (m_ptmid+asdf + tmpcross2*tmp.top).GetPOINT();
		arr[2] = (m_ptmid+asdf + tmpcross2*tmp.bottom).GetPOINT();
		tmpcross2 = asdf;
		tmpcross2.normalize();
		arr[1] = (m_ptmid+asdf + tmpcross2*tmp.right).GetPOINT();

		m_bullet[1].draw(hdc,arr);
	}

}

void CBulletManager::Update()
{
	for (auto &cirB : m_listCirBullet)
	{
		if (!PtInRect(&m_rcClent, cirB.m_Pos.GetPOINT()))
		{
			cirB.isShow = false;
		}
		
		cirB.Update();

		if (m_ptrEnemeyManager->damageCirBullet(&cirB)) {
			cirB.isShow = false;
		}

	}


	m_listCirBullet.remove_if([](CirBullet bullet) {return !bullet.isShow; });

	for (auto &cirB : m_listLaserBullet)
	{
		cirB.Update();

		m_ptrEnemeyManager->damageLaserBullet(*(cirB.m_ptrUnit));
		
	}
	m_listLaserBullet.remove_if([](LaserBullet bullet) {return !bullet.isShow; });

}

void CBulletManager::OnCreate(CEnemymanager * ptrEnemeyManager)
{
	m_ptrEnemeyManager = ptrEnemeyManager;
}
