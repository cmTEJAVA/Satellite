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

	m_fRadianUnit += m_fradianspeed;
	if (m_fRadianUnit >= PI * 2) {
		m_fRadianUnit = 0;
	}
	m_imgUnit.Update();
}
