#include "stdafx.h"
#include "TestScene.h"
#include "Point.h"

CTestScene::CTestScene()
{
}


CTestScene::~CTestScene()
{
}

void CTestScene::Update()
{
	testEnemy.Update();


	Point ptmidtmp{ m_rcClient.right / 2,m_rcClient.bottom / 2 };
	int tmp=ptmidtmp.distance(testEnemy.m_Pos);


	if (maxdistance > tmp) {
		ID = -1;
	}
}

void CTestScene::Draw(HDC hdc)
{
	FillRect(hdc, &m_rcClient, (HBRUSH)GetStockObject(WHITE_BRUSH));
	//float tmp = (2 * PI) / DIVIDE_N;
	//Point pttmp{ m_rcClient.right,m_rcClient.bottom / 2 };
	//Point ptmidtmp{ m_rcClient.right / 2,m_rcClient.bottom / 2 };
	//for (int i = 0; i < DIVIDE_N; i++) {
	//	MoveToEx(hdc, ptmidtmp.x, ptmidtmp.y, nullptr);

	//	//Point pttmp{ m_rcClient.right,m_rcClient.bottom / 2 };
	//	pttmp.rotation(ptmidtmp, tmp);
	//	LineTo(hdc, pttmp.x, pttmp.y);
	//}

	//HPEN hpen = CreatePen(PS_SOLID, 1, RGB(0, 255, 255));
	//HPEN oldpen = (HPEN)SelectObject(hdc, hpen);
	//pttmp.rotation(ptmidtmp, tmp/2);
	//for (int i = 0; i < DIVIDE_N; i++) {
	//	MoveToEx(hdc, ptmidtmp.x, ptmidtmp.y, nullptr);

	//	//Point pttmp{ m_rcClient.right,m_rcClient.bottom / 2 };
	//	pttmp.rotation(ptmidtmp, tmp);
	//	LineTo(hdc, pttmp.x, pttmp.y);
	//}



	TCHAR text[50];
	wsprintf(text, L" %d (ID2: %d) ", ID,ID2);
	DrawText(hdc, text, lstrlen(text), &m_rcClient, DT_TOP|DT_LEFT);
	//SelectObject(hdc, oldpen);
	//DeleteObject(hpen);

	//HBRUSH oldbr = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
	//Ellipse(hdc	, m_ptMouse.x-10, m_ptMouse.y-10
	//			, m_ptMouse.x+10, m_ptMouse.y+10);
	//SelectObject(hdc, oldbr);

	RECT enemyrctmp=testEnemy.GetDrawRECT();
	Ellipse(hdc, enemyrctmp.left, enemyrctmp.top, enemyrctmp.right, enemyrctmp.bottom);

}

bool CTestScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEMOVE:
		m_ptMouse = POINT{ LOWORD(lParam),HIWORD(lParam) };
		break;
	case WM_LBUTTONUP:
		insertEnemy();
		break;
	default:
		break;
	}
	return false;
}

bool CTestScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	CScene::Initialize(pFramework, hWnd);

	GetClientRect(hWnd, &m_rcClient);
	float radian = (2 * PI) / DIVIDE_N;
	maxdistance = ENEMY_MAX_R_SIZE / cos((PI - radian) / 2);
	insertEnemy();
	return false;
}

void CTestScene::ReleaseObjects()
{
}
