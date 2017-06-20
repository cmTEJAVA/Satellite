#pragma once
#include "Enemy.h"
#include <list>
#include "Sprite.h"
#include "CirBullet.h"
#include "TeslaLaser.h"

class Sound_Func;

class CEnemymanager
{
	Point m_tergetPos;
	int m_tergetSize;
	std::list<CEnemy> m_listEnemys;

	unsigned char m_delN;


	//std::vector<std::list<CEnemy*>> m_vlistenemys;
	//std::list<CEnemy*> m_listEnemys;
	RECT m_rcClient{ 0,0,WIDTH,HEIGHT };
	
	Sound_Func* m_ptrSound;

public:
	CSprite m_imgEnemy;
	CSprite m_imgEnemyTesla;
	CEnemymanager();
	~CEnemymanager();
	void OnCreatEnemyManager(const Point& tergetpos,int tergetSize, Sound_Func* ptrS) {
		m_delN = 0;
		m_tergetSize = tergetSize;

		m_imgEnemy.OnCreatCimg(L"Resorce/Game/enemy sprite.bmp");
		m_imgEnemy.OnCreatSprite(0.5, 20, 0.6);
		m_imgEnemy.Setsizerate(0.5f);
		m_imgEnemy.Setmidpos(m_imgEnemy.GetObjRECT());

		m_imgEnemyTesla.OnCreatCimg(L"Resorce/Game/tesla sprite.png");
		m_imgEnemyTesla.OnCreatSprite(1.f, 5, 0.6);
		m_imgEnemyTesla.Setsizerate(1.f);
		m_imgEnemyTesla.Setmidpos(m_imgEnemy.GetObjRECT());

	//	m_imgEnemy.OnCreatSprite(0.5f, 1, 0);


		m_tergetPos = tergetpos;
		m_ptrSound = ptrS;

	}
	void SetTergetPos(const Point& pos) {
		for (auto& enemy : m_listEnemys)
		{
			enemy.SetTergetPos(pos);
		}
	}
	void draw(HDC hdc);
	void Update();

	void insertEnemy(float speed) {
		Point pos{-10,10};
		pos.rotation(m_tergetPos,(rand()%628)/100.0f);

		m_listEnemys.push_back(CEnemy());
		m_listEnemys.back().Oncreat(rand()% (ENEMY_MAX_R_SIZE-10) +10, pos, m_tergetPos, speed,0.05);
	
	}

	int attack() {
		int returni = 0;
		for (auto & enemy : m_listEnemys) {
			int tmp = enemy.m_Pos.distance(m_tergetPos);
			tmp -= enemy.m_size+m_tergetSize-15;
			if (abs(tmp)<5) {
				enemy.m_isShow = false;
				returni++;
			}
		}
		return returni;
	}

	RECT GetSorceRECT(int i = 0) {

	}

	bool damageCirBullet(CirBullet * ptrbullet);
	void damageLaserBullet(Point bullet);
	void damageShockBullet(Point bullet, int size);
	void targetTeslaBullet(Point bullet,int size,std::list<TeslaLaser> * v_laser);

	unsigned char GetDelN() {
		auto tmp = m_delN;
		m_delN = 0;
		return tmp;
	}
};

