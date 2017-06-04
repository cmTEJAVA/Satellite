#pragma once
class CGameObject
{
protected:
	RECT m_rcobjsize;
	Point m_ptpos;
	float m_fsizerate;

public:
	CGameObject();
	virtual ~CGameObject() {};

	virtual void draw(HDC hdc) = 0;
	void Setsizerate(const float& q) { m_fsizerate = q; }
	const float Getsizerate() { return m_fsizerate; }

	//GetRECTsize: sizerate�� ����� ������Ʈ ������
	const RECT GetRECTsize() const { return m_rcobjsize*m_fsizerate; }

	//GetObjRECT: pos�� ����� 
	const RECT GetObjRECT() const { return GetRECTsize() + m_ptpos.GetPOINT(); }


	void SetPos(const Point& q) { m_ptpos = q; }
	const Point Getpos()const { return m_ptpos; }

	bool BoxCollision_posconst(const RECT& rcObj);

};

