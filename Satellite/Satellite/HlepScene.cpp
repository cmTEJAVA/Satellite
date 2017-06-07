#include "stdafx.h"
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
}

bool CHlepScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	m_sizehlepindx = 0;
	m_bmphlep[0].OnCreatCimg(L"Resorce/Test/help1.bmp");
	m_bmphlep[1].OnCreatCimg(L"Resorce/Test/help2.bmp");
	m_bmphlep[2].OnCreatCimg(L"Resorce/Test/help3.bmp");
	return false;
}

bool CHlepScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONUP:
		
		m_sizehlepindx++;
		if (m_sizehlepindx >= 3) {
			return true;
			//m_ptparentScene->popSceneLayer();
			return false;
		}//m_sizehlepindx %= HLEP_IMG_N;
		break;
	default:
		break;
	}
	return false;
}
