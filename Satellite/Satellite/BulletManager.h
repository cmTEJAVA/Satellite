#pragma once
#include "BitmapObject.h"
#include <list>
#include "CirBullet.h"
#include "ShockwaveBullet.h"
#include "LaserBullet.h"
#include "Tesla.h"
#include "TeslaLaser.h"
#include "Enemymanager.h"
class CBulletManager
{
	std::list<CirBullet> m_listCirBullet;
	std::list<LaserBullet> m_listLaserBullet;
	std::list<ShockwaveBullet> m_listShockBullet;
	std::list<Tesla> m_listTesla;
	std::list<TeslaLaser> m_listTeslaBullet;

	RECT m_rcClent;
	Point m_ptmid;
	CEnemymanager * m_ptrEnemeyManager;

public:
	CBitmapObject m_bullet[(int)ENUM_BULLET::END];
	
	CBulletManager();
	~CBulletManager() ;
	void draw(HDC hdc) ;
	void Update() ;
	void OnCreate(CEnemymanager * ptrEnemeyManager);
	void OnCreateBulletImg() {
		m_bullet[(int)ENUM_BULLET::STANDARD].Setsizerate(0.2f);
		m_bullet[(int)ENUM_BULLET::STANDARD].OnCreatCimg(L"Resorce/Game/bullet.png");
		RECT tmp = m_bullet[(int)ENUM_BULLET::STANDARD].GetObjRECT();
		m_bullet[(int)ENUM_BULLET::STANDARD].Setmidpos(tmp);
		m_bullet[(int)ENUM_BULLET::STANDARD].SetPos(Point{ 0,0 });
		m_rcClent = RECT{ 0,0,WIDTH,HEIGHT };
		m_ptmid = Point{ m_rcClent.right / 2,m_rcClent.bottom / 2 };

		m_bullet[(int)ENUM_BULLET::LASER].Setsizerate(1.f);
		m_bullet[(int)ENUM_BULLET::LASER].OnCreatCimg(L"Resorce/Game/laser.bmp");
		tmp = m_bullet[(int)ENUM_BULLET::LASER].GetObjRECT();
		int tmpsizelaser = tmp.bottom - tmp.top;
		tmp.top = -tmpsizelaser / 2;
		tmp.bottom = tmpsizelaser / 2;
		m_bullet[(int)ENUM_BULLET::LASER].SetObjRECT(tmp);
		m_bullet[(int)ENUM_BULLET::LASER].SetPos(Point{ 0,0 });
		
	}
	void insertbullet(ENUM_BULLET ID,const Point& pos,const Point& dir,float speed) {
		switch (ID)
		{
		case ENUM_BULLET::STANDARD:
			m_listCirBullet.push_back(CirBullet());
			m_listCirBullet.back().Oncreat(pos, dir, speed);
			break;
		default:
			break;
		}
	}
	void insertlaserbullet(Point* unitpos) {

		m_listLaserBullet.push_back(LaserBullet());
		m_listLaserBullet.back().Oncreat(unitpos);
	}
	void insertShockbullet(Point * unitpos,int size=50) {

		m_listShockBullet.push_back(ShockwaveBullet());
		m_listShockBullet.back().Oncreat(unitpos,size);
	}

	void insertTeslabullet(Point * unitpos, int size = 50) {

		m_listTesla.push_back(Tesla());
		m_listTesla.back().Oncreat(unitpos, size);
	}

};

