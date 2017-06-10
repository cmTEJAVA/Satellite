#pragma once
#include "GameMoveObject.h"
#include "Sprite.h"
class CUnit :
	public CGameMoveObject
{
	ENUM_UNIT m_unitID;

	float	m_fRadianUnit;
	float	m_fradianspeed;
	Point	m_ptmidpos;
	int		m_iRadius;//¹ÝÁö¸§

	int		m_ibullettime;
public:
	CSprite m_imgUnit;
	CUnit();
	~CUnit();
	virtual void draw(HDC hdc) override;
	void OnCreatUnit(const Point& pos, const Point& midpos
		, const LPCTSTR& pStream
		, float imgsizerate, int spriteframeN, float frameupdatetime
		, float radianspeed = 0.01, float speed = 0.02f) {
		m_imgUnit.SetPos(pos);
		m_imgUnit.OnCreatCimg(pStream);
		m_imgUnit.OnCreatSprite(imgsizerate, spriteframeN, frameupdatetime);
		m_ptmidpos = midpos;
	//	SetObjRECT(m_imgUnit.GetObjRECT());
	//	SetPos(pos);
	//	m_rcobjsize=m_rcobjsize - pos.GetPOINT();
		SetSpeed(speed);
		m_fradianspeed = radianspeed;
		m_fRadianUnit = 0;
		m_ibullettime = 0;
	}
	void SetID(ENUM_UNIT id) {
		m_unitID = id;
	}
	ENUM_BULLET GetBullet() {
		if (m_ibullettime < 7)return ENUM_BULLET::END;
		switch (m_unitID)
		{
		case ENUM_UNIT::BULLET_UNIT:
			m_ibullettime = 0;
			return ENUM_BULLET::STANDARD;
			break;
		case ENUM_UNIT::LASER_UNIT:
			m_ibullettime = 0;
			return ENUM_BULLET::LASER;
			break;
		//case ENUM_UNIT::TESLA_UNIT:
		//	break;
		//case ENUM_UNIT::END:
		//	break;
		default:
			break;
		}

	}

	void Update()override;

};

