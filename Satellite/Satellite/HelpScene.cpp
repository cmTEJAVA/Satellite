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
	m_arrbutton[0].OnCreatCimg(L"null");
	m_arrbutton[1].OnCreatCimg(L"null");
	m_arrbutton[2].OnCreatCimg(L"Resorce/Test/go-back-arrow.png");
	for (auto & q : m_arrbutton) {
		q.SetObjRECT(RECT{-50,-20,50,20});
	}
	m_arrbutton[2].SetObjRECT(RECT{ -20,-20,20,20 });

	m_arrbutton[0].SetPos(Point{ 70,rcClient.bottom-50});
	m_arrbutton[1].SetPos(Point{ rcClient.right-70,rcClient.bottom - 50 });
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
		

		for (int i = 0; i < 3;i++) {
			RECT tmp = m_arrbutton[i].GetObjRECT();
			POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
			m_arrbutton[i].SetOn(false);

			if (PtInRect(&tmp, ptmouse)) {
				m_arrbutton[i].SetOn(true);

				switch (i)
				{
				case 0:
					m_sizeHELPindx=max(0,int(m_sizeHELPindx-1));
					break;

				case 1:
					m_sizeHELPindx = min(HELP_IMG_N-1, m_sizeHELPindx+1);

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
