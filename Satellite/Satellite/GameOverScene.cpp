#include "stdafx.h"
#include "GameFrameWork.h"
#include "GameOverScene.h"

CGameOverScene::CGameOverScene()
{
}


CGameOverScene::~CGameOverScene()
{
}

void CGameOverScene::Update()
{
	for (int i = 0; i < 2; i++) {
		if (!m_arrbutton[i].Getselect())continue;
		switch (i)
		{
		case 0:
			m_Framework->ChangeScene(ENUM_SCENE::MENU);
			break;

		case 1:
			//게임종료
			break;


		default:
			break;
		}
		return;
	}

}

void CGameOverScene::Draw(HDC hDC)
{
	FillRect(hDC, &rcClient, (HBRUSH)GetStockObject(WHITE_BRUSH));

	m_bmpGameOver.draw(hDC);

	m_arrbutton[0].draw(hDC);
	m_arrbutton[1].draw(hDC);
}

bool CGameOverScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	if (!CScene::Initialize(pFramework, hWnd)) return false;

	GetClientRect(hWnd, &rcClient);

	m_sizeGameOverindx = 0;
	m_bmpGameOver.OnCreatCimg(L"Resorce/Game/game over.png");
	
	m_arrbutton[0].OnCreatCimg(L"Resorce/button/green arrow back.png");
	m_arrbutton[0].OnCreatCimg(L"Resorce/button/green arrow back.png");

	for (auto & q : m_arrbutton) {
		q.SetObjRECT(RECT{ -20,-20,20,20 });
	}

	m_arrbutton[0].SetPos(Point{ 30,rcClient.bottom - 300 });
	m_arrbutton[1].SetPos(Point{ rcClient.right - 30,rcClient.bottom - 300 });

	return false;
}

bool CGameOverScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
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
		for (auto & buttonq : m_arrbutton) {
			buttonq.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}
		break;

	default:
		break;
	}
	return false;
}
