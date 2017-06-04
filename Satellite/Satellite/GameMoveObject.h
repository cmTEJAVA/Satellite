#pragma once
#include "GameObject.h"
class CGameMoveObject :
	public CGameObject
{

	float m_fspeed;
	Point m_dir;//바라보는 방향도 있어.
public:
	virtual void draw(HDC hdc) override;

	void SetDir(const Point& q) {
		m_dir = q;
		m_dir.normalize();
	}
	Point GetDir() const { return m_dir; };
	void SetSeeped(const float& q) { m_fspeed = q; }

	void Update() { m_ptpos += m_dir*m_fspeed; }
	CGameMoveObject();
	~CGameMoveObject();
};

