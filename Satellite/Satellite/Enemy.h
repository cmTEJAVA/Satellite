#pragma once
#include "Point.h"
class CEnemy 
{

	float		m_fradianspeed;
	Point		m_Dir;
	Point		m_tergetPos;
	float		m_Speed;
	float		m_life; // 0~1

	//CSprite;
	float m_oneframetime;
	float m_updatetime;
	int m_framenum;
	//CSprite;

	char ID;
	char ID2;

	//Unit에의해 움직임
	Point		m_UnitDir;
	bool		m_isUnitMove;
	size_t		m_UnitMovemaxTime;
	//Unit에의해 움직임

public:
	int m_drawframenum;

	bool		m_isShow;


	int			m_size;
	Point		m_Pos;
	float		m_fRadianUnit;
	CEnemy();
	~CEnemy();

	void Oncreat(int size,const Point& pos, const Point& tergetPos, float speed
		, float radianspeed = 0.01
		) {
		m_fradianspeed = radianspeed;
		m_Pos = pos;
		m_tergetPos = tergetPos;
		m_Speed = speed;
		m_size = size;
		m_life = 1;

		SetSprite(10, 5);

		Point enmytmp = m_Pos;
		enmytmp = enmytmp - m_tergetPos;
		float enemytmpradian = (2 * PI + atan2(enmytmp.y, enmytmp.x));
		int asdf = enemytmpradian / DIVIDE_RADIAN;

		asdf %= DIVIDE_N;
		ID = asdf;


		float ID2floatradian = DIVIDE_RADIAN*((float)ID + 0.5f);
		if (enemytmpradian > 2 * PI) {
			enemytmpradian -= 2 * PI;
		}
		
		ID2 = (enemytmpradian < ID2floatradian ? ID - 1 : ID + 1);
		ID2 = (ID2+ DIVIDE_N) % DIVIDE_N;



	}
	void SetTergetPos(const Point& pos) {
		m_tergetPos = pos;
	}
	void Update();
	void UpdateDraw() {

		m_fRadianUnit += m_fradianspeed;
		if (m_fRadianUnit >= PI * 2) {
			m_fRadianUnit = 0;
		}

	}
	void Drawlife(HDC hdc);
	void damage(float fPerdmg = 0.05f) {
		m_life = max(0.f, m_life - fPerdmg);
		if (m_life == 0.f) {
			m_Speed = 0;
			m_isShow = false;
			//m_imgUnit.releaseCimg();
			//m_imgUnit.loadCimg(m_destroyedimgPath);
		}
	};


	RECT GetDrawRECT() {
		return RECT{
			LONG(m_Pos.x-m_size),
			LONG(m_Pos.y-m_size),
			LONG(m_Pos.x+m_size),
			LONG(m_Pos.y+m_size)

		};
	}

	bool istrueOnID(const char& tmp) {
		if (ID == -1 || ID == tmp || ID2 == tmp) {
			return true;
		}
		return false;
	}

	void SetUnitMove(const Point& Unitdir,size_t maxtime) {

		m_UnitDir= Unitdir;
		m_UnitDir.normalize();
		m_UnitMovemaxTime= maxtime;
		m_isUnitMove=true;
	}

	void SetSprite( int imgN, float frametime) {


		m_framenum = imgN;
		m_oneframetime = frametime;
		
	}

};

