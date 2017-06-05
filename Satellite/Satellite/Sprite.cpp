#include "stdafx.h"
#include <math.h>
#include "Sprite.h"

CSprite::CSprite()
{

	m_framenum = 0;
	m_oneframetime = 0;
	m_drawframenum = 0;
	m_updatetime = 0;
}


CSprite::~CSprite()
{
}

void CSprite::draw(HDC hdc)
{
	drawRotatImage(hdc, 10);
	return;
	RECT rctmp = GetObjRECT();

	m_cimg.Draw(hdc,
		rctmp.left, rctmp.top,
		rctmp.right - rctmp.left, rctmp.bottom - rctmp.top

		, m_spritesize.x*(m_drawframenum), 0
		, m_spritesize.x, m_spritesize.y
		);




}

bool CSprite::Update(float time)
{
	m_updatetime += time;
	if (m_updatetime > m_oneframetime) {
		m_updatetime = 0;
		m_drawframenum++;

	}
	if (m_drawframenum >= m_framenum) {
		m_drawframenum = 0;
		return false;

	}
	return true;
}

bool CSprite::drawRotatImage(HDC hdc, double dblAngle)
{
	Point S_Center = Getpos();
	RECT rctmp = GetObjRECT();
	Point originDest{ rctmp.left, rctmp.top };

	POINT apt[3];
	double dblWidth = m_spritesize.x;
	double dblHeight = m_spritesize.y;

	double dblRadian, dblx, dbly, dblxDest, dblyDest, cosVal, sinVal;

	dblRadian = dblAngle * PI / 180.0f;
	cosVal = cos(dblRadian);
	sinVal = sin(dblRadian);


	Point S_RCenter;
	S_RCenter.x = S_Center.x*cosVal - S_Center.y*sinVal;	//ȸ����ȯ
	S_RCenter.y = S_Center.x*sinVal + S_Center.y*cosVal;	//ȸ����ȯ

	S_RCenter.x -= S_Center.x;				//�׸��� �߽� ���߱�
	S_RCenter.y -= S_Center.y;				//�׸��� �߽� ���߱�


											//�� ���� ȸ����ȯ�ؼ� apt�� �����Ű��
	for (int i = 0; i < 3; ++i)
	{
		switch (i) {
		case 0:
			dblx = originDest.x;
			dbly = originDest.y;
			break;
		case 1:
			dblx = originDest.x + dblWidth;
			dbly = originDest.y;
			break;
		case 2:
			dblx = originDest.x;
			dbly = originDest.y + dblHeight;

			break;
		}
		dblxDest = dblx*cosVal - dbly*sinVal;	//�� ������ ȸ����ȯ
		dblyDest = dblx*sinVal + dbly*cosVal;	//�� ������ ȸ����ȯ

		apt[i].x = dblxDest - S_RCenter.x;		//�׸��� �߽� ���߱�
		apt[i].y = dblyDest - S_RCenter.y;		//�׸��� �߽� ���߱�

	}
	POINT zroe{ apt[2].x,apt[0].y };
	for (int i = 0; i < 3; i++) {
		apt[i]=apt[i] - zroe;
	}

	HDC RotateDC;		//ȸ����Ų�� �׸����� DC

	RotateDC = CreateCompatibleDC(hdc);

	HBITMAP Old2;	//�̰� ������ ������ ����

	HBITMAP memBIT = CreateCompatibleBitmap(hdc, apt[1].x, apt[2].y+apt[1].y);
	Old2 = (HBITMAP)SelectObject(RotateDC, memBIT);				//RotateDC�� memBIT������

	RECT qqqq = {0,0,apt[1].x, apt[2].y + apt[1].y };
	FillRect(RotateDC, &qqqq, (HBRUSH)GetStockObject(BLACK_BRUSH));

	m_cimg.PlgBlt(RotateDC, apt, m_spritesize.x*(m_drawframenum), 0
		, m_spritesize.x, m_spritesize.y);
	
	CImage alphacimg;


	StretchBlt(hdc, zroe.x, zroe.y, apt[1].x, apt[2].y + apt[1].y,
		RotateDC, 0, 0, apt[1].x, apt[2].y + apt[1].y,SRCCOPY);


	SelectObject(RotateDC, Old2);
	DeleteObject(memBIT);
	DeleteDC(RotateDC);


 	return false;
}