#pragma once
#include "Point.h"

class TeslaLaser;

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

	//CSprite;
	float		m_Shockoneframetime;
	float		m_Shockupdatetime;
	float		m_ShockMaxTime;
	int			m_Shockframenum;
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
	int m_Shockdrawframenum;

	bool		m_isShow;

	TeslaLaser * m_tergetBullet;
	bool		m_isterget;
	bool		m_isTesla;

	int			m_size;
	Point		m_Pos;
	float		m_fRadianUnit;
	CEnemy();
	~CEnemy();

	void Oncreat(int size, const Point& pos, const Point& tergetPos, float speed
		, float radianspeed = 0.01
		);
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
	void SetSprite_Tesla(int imgN, float frametime) {
		m_Shockoneframetime= frametime;
		m_Shockupdatetime=0;
		m_ShockMaxTime=4;
		m_Shockframenum = imgN;
		m_Shockdrawframenum = 0;
	}

	void SetTeslaShock() {
		m_isTesla = true;
		m_ShockMaxTime = 4;
	}

};

