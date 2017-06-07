#include "stdafx.h"
#include "GameFrameWork.h"
#include "HlepScene.h"


CHlepScene::CHlepScene()
{
}


CHlepScene::~CHlepScene()
{
}

void CHlepScene::Update()
{
}

void CHlepScene::Draw(HDC hDC)
{
	m_bmphlep[m_sizehlepindx].draw(hDC);
	for (auto & q : m_arrbutton) {
		q.draw(hDC);
	}
}

bool CHlepScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	if (!CScene::Initialize(pFramework, hWnd)) return false;

	RECT rcClient;
	GetClientRect(hWnd, &rcClient);

	m_sizehlepindx = 0;
	m_bmphlep[0].OnCreatCimg(L"Resorce/Test/help1.bmp");
	m_bmphlep[1].OnCreatCimg(L"Resorce/Test/help2.bmp");
	m_bmphlep[2].OnCreatCimg(L"Resorce/Test/help3.bmp");
	m_arrbutton[0].OnCreatCimg(L"null");
	m_arrbutton[1].OnCreatCimg(L"null");
	m_arrbutton[2].OnCreatCimg(L"null");
	for (auto & q : m_arrbutton) {
		q.SetObjRECT(RECT{-50,-20,50,20});
	}
	m_arrbutton[0].SetPos(Point{ 70,rcClient.bottom-50});
	m_arrbutton[1].SetPos(Point{ rcClient.right-70,rcClient.bottom - 50 });
	m_arrbutton[2].SetPos(Point{50,20});

	for (auto & q:m_bmphlep) {
		q.SetObjRECT(rcClient);
	}

	return false;
}

bool CHlepScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONUP:
	{
		

		for (int i = 0; i < 3;i++) {
			RECT tmp = m_arrbutton[i].GetObjRECT();
			POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
			m_arrbutton[i].SetOn(false);

			if (PtInRect(&tmp, ptmouse)) {
				m_arrbutton[i].SetOn(true);

				switch (i)
				{
				case 0:
					m_sizehlepindx=max(0,int(m_sizehlepindx-1));
					break;

				case 1:
					m_sizehlepindx = min(HLEP_IMG_N-1, m_sizehlepindx+1);

					break;

				case 2:
					m_Framework->ChangeScene(ENUM_SCENE::MENU);
					return false;
					break;

				default:
					break;
				}



				return false;
			}
		}
	}
		break;

	case WM_MOUSEMOVE:
		for (auto & buttonq:m_arrbutton) {
			RECT tmp = buttonq.GetObjRECT();
			POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
			buttonq.SetOn(false);

			if (PtInRect(&tmp, ptmouse)) {
				buttonq.SetOn(true);
				return false;
			}
		}
		break;

	default:
		break;
	}
	return false;
}
