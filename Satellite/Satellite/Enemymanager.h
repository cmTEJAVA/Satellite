#pragma once
#include "Enemy.h"
#include <list>
#include "Sprite.h"
class CEnemymanager
{
	Point m_tergetPos;
	int m_tergetSize;
	std::list<CEnemy> m_listEnemys;
public:
	CBitmapObject m_imgEnemy;
	CEnemymanager();
	~CEnemymanager();
	void OnCreatEnemy(const Point& tergetpos,int tergetSize) {
		m_tergetSize = tergetSize;

		m_imgEnemy.OnCreatCimg(L"Resorce/Test/enemy1.bmp");
		m_imgEnemy.Setsizerate(0.5f);
		m_imgEnemy.Setmidpos(m_imgEnemy.GetObjRECT());
	//	m_imgEnemy.OnCreatSprite(0.5f, 1, 0);


		m_tergetPos = tergetpos;
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
		m_listEnemys.back().Oncreat(rand()%30+10, pos, m_tergetPos, speed+5.f);
	
	}

	int attack() {
		int returni = 0;
		for (auto & enemy : m_listEnemys) {
			int tmp = enemy.m_Pos.distance(m_tergetPos);
			tmp -= enemy.m_size+m_tergetSize;
			if (abs(tmp)<5) {
				enemy.m_isShow = false;
				returni++;
			}
		}
		m_listEnemys.remove_if([](CEnemy enemy) {return !enemy.m_isShow; });
		return returni;
	}



};

