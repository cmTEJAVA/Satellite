#pragma once
#include "Enemy.h"
#include <list>
#include "Sprite.h"
class CEnemymanager
{
	Point m_tergetPos;
	std::list<CEnemy> m_listEnemys;
public:
	CBitmapObject m_imgEnemy;
	CEnemymanager();
	~CEnemymanager();
	void OnCreatEnemy(const Point& tergetpos) {

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

	void insertEnemy(const Point& pos, float speed) {
		
		m_listEnemys.push_back(CEnemy());
		m_listEnemys.back().Oncreat(rand()%40+5,pos, m_tergetPos, speed);
	
	}
};

