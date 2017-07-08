#include "stdafx.h"
#include "GameFrameWork.h"
#include "HELPScene.h"
#include "Sound.h"


CHELPScene::CHELPScene()
{
}


CHELPScene::~CHELPScene()
{
}

void CHELPScene::Update()
{
	int buttonid;
	for (buttonid = 0; buttonid < HELP_BUTTON_N; buttonid++) {
		if (!m_arrbutton[buttonid].Getselect())continue;
		switch (buttonid)
		{
		case 0:
			snd2->Play_effect(ENUM_SOUND::CLICK);
			m_sizeHELPindx = max(0, int(m_sizeHELPindx - 1));
			m_arrbutton[buttonid].Setselect(false);
			break;

		case 1:
			snd2->Play_effect(ENUM_SOUND::CLICK);
			m_sizeHELPindx = min(HELP_IMG_N - 1, m_sizeHELPindx + 1);
			m_arrbutton[buttonid].Setselect(false);
			break;

		case 2:
			snd2->Play_effect(ENUM_SOUND::CLICK);
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
	
	//만약 첫 페이지가 아니라면 앞으로 버튼을 그린다.
	if(m_sizeHELPindx!=0)m_arrbutton[0].draw(hDC);
	//만약 마지막 페이지가 아니라면 뒤로 버튼을 그린다.
	if (m_sizeHELPindx != HELP_IMG_N - 1)m_arrbutton[1].draw(hDC);
	//만약 마지막 페이지 라면 메뉴로 버튼을 그린다.
	if (m_sizeHELPindx == HELP_IMG_N - 1) m_arrbutton[2].draw(hDC);
}

bool CHELPScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	if (!CScene::Initialize(pFramework, hWnd)) return false;

	GetClientRect(hWnd, &rcClient);

	m_sizeHELPindx = 0;
	m_bmpHELP[0].OnCreatCimg(L"Resorce/Help/help1.bmp");
	m_bmpHELP[1].OnCreatCimg(L"Resorce/Help/help2.bmp");
	m_bmpHELP[2].OnCreatCimg(L"Resorce/Help/help3.bmp");
	m_bmpHELP[3].OnCreatCimg(L"Resorce/Help/help4.bmp");

	m_arrbutton[0].OnCreatCimg(L"Resorce/button/green arrow left.png");
	m_arrbutton[1].OnCreatCimg(L"Resorce/button/green arrow right.png");
	m_arrbutton[2].OnCreatCimg(L"Resorce/button/green arrow back.png");
	for (auto & q : m_arrbutton) {
		q.SetObjRECT(RECT{-20,-20,20,20});
	}


	m_arrbutton[0].SetPos(Point{ 30,rcClient.bottom-300});
	m_arrbutton[1].SetPos(Point{ rcClient.right - 30,rcClient.bottom - 300 });
	m_arrbutton[2].SetPos(Point{ rcClient.left+30,rcClient.top + 30 });
	//m_arrbutton[2].SetPos(Point{ 30,rcClient.bottom - 300 });

	for (auto & q:m_bmpHELP) {
		q.SetObjRECT(rcClient);
	}

	return false;
}

void CHELPScene::snd_init(Sound_Func * ptrs)
{
	snd2 = ptrs;
}

bool CHELPScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONUP:
	{
		for (int i = 0; i < HELP_BUTTON_N; ++i)
		{
			if (m_sizeHELPindx != HELP_IMG_N - 1 && i == 2) break;
			m_arrbutton[i].SetMouseLUp(POINT{ LOWORD(lParam),HIWORD(lParam) });
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
