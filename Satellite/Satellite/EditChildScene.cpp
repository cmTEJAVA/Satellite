#include "stdafx.h"
#include "EditChildScene.h"


CEditChildScene::CEditChildScene()
{
}


CEditChildScene::~CEditChildScene()
{
}

void CEditChildScene::Update()
{

}

void CEditChildScene::Draw(HDC hDC)
{
#pragma region alphahdc_draw
	HDC alphahdc = CreateCompatibleDC(hDC);
	HBITMAP alphahbmp = CreateCompatibleBitmap(hDC, m_rcClient.right, m_rcClient.bottom);
	HBITMAP alphaoldbmp = (HBITMAP)SelectObject(alphahdc, alphahbmp);


	TCHAR asdf[50] = L"EditChildScene";
	DrawText(alphahdc, asdf, lstrlen(asdf), &m_rcClient,DT_TOP|DT_LEFT);


	Rectangle(alphahdc, m_rcEditWindow.left, m_rcEditWindow.top, m_rcEditWindow.right, m_rcEditWindow.bottom);




	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = (255/4);
	bf.AlphaFormat = 0;
	AlphaBlend(hDC, 0, 0, m_rcClient.right, m_rcClient.bottom, alphahdc, 0, 0, m_rcClient.right, m_rcClient.bottom, bf);

	SelectObject(alphahdc, alphaoldbmp);
	DeleteObject(alphahbmp);
	DeleteDC(alphahdc);

#pragma endregion





	HBRUSH old = (HBRUSH)SelectObject(hDC, GetStockObject(NULL_BRUSH));
	HPEN hpen = CreatePen(PS_SOLID, 3, RGB(0, 100, 180));
	HPEN oldpen = (HPEN)SelectObject(hDC, hpen);
	for (auto &q : m_vOrbit) {
		Ellipse(hDC, q.left, q.top, q.right, q.bottom);
	}

	for (int i = 0; i < m_vUnits.size(); i++) {
		HPEN hpenselect=nullptr;
		HPEN hpenselectold= nullptr;
		if (m_iSelectOrbit == i) {
			HPEN hpenselect = CreatePen(PS_SOLID, 3, RGB(255, 150, 0));
			hpenselectold=(HPEN)SelectObject(hDC, hpenselect);

		}
		Cbutton &m_testbutt = m_vUnits[i];

		RECT rctmp = m_testbutt.GetObjRECT();
		m_testbutt.draw(hDC);
		Rectangle(hDC, rctmp.left, rctmp.top, rctmp.right, rctmp.bottom);
		if (m_iSelectOrbit == i) {
			SelectObject(hDC, hpenselectold);
			DeleteObject(hpenselect);
			hpenselect = nullptr;

		}
	}


	SelectObject(hDC, old);
	SelectObject(hDC, oldpen);
	DeleteObject(hpen);

}

bool CEditChildScene::Keyboard(UINT message, WPARAM wParam)
{
	return false;
}

bool CEditChildScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_MOUSEMOVE:
	{
		for (auto& m_testbutt : m_vUnits)
		{

			RECT tmp = m_testbutt.GetObjRECT();
			POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
			m_testbutt.SetOn(false);

			if (PtInRect(&tmp, ptmouse)) {
				m_testbutt.SetOn(true);
			}
		}
	}	

	break;
	case WM_LBUTTONUP:

		for (int i = 0; i < m_vUnits.size(); i++) {
			Cbutton &m_testbutt = m_vUnits[i];


			RECT tmp = m_testbutt.GetObjRECT();
			POINT ptmouse{ LOWORD(lParam),HIWORD(lParam) };
			m_testbutt.SetOn(false);

			if (PtInRect(&tmp, ptmouse)) {
				m_testbutt.SetOn(true);
				m_testbutt.Setselect(true);
				m_iSelectOrbit = i;
				return true;
			}
		}


		break;




	default:
		return false;
		//메세지가 처리 되지 않았으면 false가 반환
		break;
	}
	return false;

}

bool CEditChildScene::Initialize(CScene * pparentScene, HWND hWnd)
{
	CChildScene::Initialize(pparentScene, hWnd);
	GetClientRect(hWnd, &m_rcClient);


	RECT tmp = m_rcClient;
	tmp.top = (m_rcClient.bottom / 4) * 3;
	tmp.bottom -= 30;
	m_rcEditWindow = tmp;

//	m_rcEditWindow
	return false;
}

UINT CEditChildScene::GetSceneMessge(ENUM_CHILD_MESSGE message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case ENUM_CHILD_MESSGE::SETORBITMAX:
	{
		m_vOrbit.clear();
		for (int i = 0; i < wParam; i++) {
			m_vOrbit.push_back(RECT{});
		}
	}
		break;
	case ENUM_CHILD_MESSGE::SETORBITSIZE:
	{
		LONG tmp = lParam;
		m_vOrbit[wParam] = 
			RECT{ WIDTH / 2 - tmp,HEIGHT / 2 - tmp
			,WIDTH / 2 + tmp,HEIGHT / 2 + tmp };
	}
		break;
	case ENUM_CHILD_MESSGE::SETUNITMAX:
		m_vUnits.clear();
		for (int i = 0; i < wParam; i++) {
			m_vUnits.push_back(Cbutton{});
		}
		break;
	case ENUM_CHILD_MESSGE::SETUNITPATH:
	{
		m_vUnits[wParam].OnCreatCimg(
			(LPCTSTR)lParam
			);
		LONG sizetmp = m_rcEditWindow.bottom - m_rcEditWindow.top;
		sizetmp /= 2;
		int interval=10;
		sizetmp -= interval;
		m_vUnits[wParam].SetObjRECT(RECT{ -sizetmp,-sizetmp,sizetmp,sizetmp });
		LONG ltmp = m_rcEditWindow.bottom + m_rcEditWindow.top;
		ltmp /= 2;

		
		m_vUnits[wParam].SetPos(
			Point{ 
			((int)(wParam)*2+1)*( sizetmp+ interval) 
			,ltmp });
	}
		break;
	default:
		break;
	}

	return 0;
}
