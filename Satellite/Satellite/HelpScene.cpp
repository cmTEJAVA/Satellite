#include "stdafx.h"
#include "GameFrameWork.h"
#include "HELPScene.h"


CHELPScene::CHELPScene()
{
}


CHELPScene::~CHELPScene()
{
}

void CHELPScene::Update()
{
	for (int i = 0; i < 3; i++) {
		if (!m_arrbutton[i].Getselect())continue;
		switch (i)
		{
		case 0:
			m_sizeHELPindx = max(0, int(m_sizeHELPindx - 1));
			m_arrbutton[i].Setselect(false);
			break;

		case 1:
			m_sizeHELPindx = min(HELP_IMG_N - 1, m_sizeHELPindx + 1);
			m_arrbutton[i].Setselect(false);

			break;

		case 2:
			m_Framework->ChangeScene(ENUM_SCENE::MENU);
			
			break;

		default:
			break;
		}
		return;
	}

}

void CHELPScene::Draw(HDC hDC)
{
	FillRect(hDC, &rcClient, (HBRUSH)GetStockObject(WHITE_BRUSH));

	m_bmpHELP[m_sizeHELPindx].draw(hDC);
	
	if(m_sizeHELPindx!=0)m_arrbutton[0].draw(hDC);
	if (m_sizeHELPindx != HELP_IMG_N-1)m_arrbutton[1].draw(hDC);
	m_arrbutton[2].draw(hDC);
}

bool CHELPScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	if (!CScene::Initialize(pFramework, hWnd)) return false;

	GetClientRect(hWnd, &rcClient);

	m_sizeHELPindx = 0;
	m_bmpHELP[0].OnCreatCimg(L"Resorce/Test/help1.bmp");
	m_bmpHELP[1].OnCreatCimg(L"Resorce/Test/help2.bmp");
	m_bmpHELP[2].OnCreatCimg(L"Resorce/Test/help3.bmp");
	m_arrbutton[0].OnCreatCimg(L"Resorce/button/green arrow left.png");
	m_arrbutton[1].OnCreatCimg(L"Resorce/button/green arrow right.png");
	m_arrbutton[2].OnCreatCimg(L"Resorce/button/green arrow back.png");
	for (auto & q : m_arrbutton) {
		q.SetObjRECT(RECT{-20,-20,20,20});
	}
	m_arrbutton[2].SetObjRECT(RECT{ -20,-20,20,20 });

	m_arrbutton[0].SetPos(Point{ 30,rcClient.bottom-30});
	m_arrbutton[1].SetPos(Point{ rcClient.right-30,rcClient.bottom - 30 });
	m_arrbutton[2].SetPos(Point{30,30});

	for (auto & q:m_bmpHELP) {
		q.SetObjRECT(rcClient);
	}

	return false;
}

bool CHELPScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONUP:
	{
		for (auto & buttonq : m_arrbutton) {
			buttonq.SetMouseLUp(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}

	}
		break;

	case WM_MOUSEMOVE:
		for (auto & buttonq:m_arrbutton) {
			buttonq.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}
		break;

	default:
		break;
	}
	return false;
}
