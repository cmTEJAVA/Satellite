#include "stdafx.h"
#include "Unit.h"


CUnit::CUnit()
{
}


CUnit::~CUnit()
{
}

void CUnit::draw(HDC hdc)
{

	m_imgUnit.drawRotatImage(hdc, m_fRadianUnit);

}

void CUnit::Update()
{

	m_imgUnit.Update();

	m_fRadianUnit += m_fradianspeed;
	if (m_fRadianUnit >= PI * 2) {
		m_fRadianUnit = 0;
	}
	
	if (m_fspeed > 0) {
		Point tmp = m_imgUnit.Getpos();
		tmp.rotation(m_ptmidpos, m_fspeed);
		m_imgUnit.SetPos(tmp);
	}

}
