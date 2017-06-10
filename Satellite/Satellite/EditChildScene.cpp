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
	for (int i = 0; i < m_vUnits.size(); i++) {
		if (m_vUnits[i].Getselect() && (m_selectOrbit >= 0)) {
			m_vinsert_ID_Units.push_back(idUnit());
			m_vinsert_ID_Units.back().unitID = i;
			m_vinsert_ID_Units.back().orbit = m_selectOrbit;

			m_selectOrbit = -1;

			m_vUnits[i].Setselect(false);
		}
	}

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
	for (int i = 0; i < m_vOrbit.size(); i++) {
		HPEN hpenselect = nullptr;
		HPEN hpenselectold = nullptr;
		if (m_selectOrbit==i) {
			hpenselect = CreatePen(PS_SOLID, 3, RGB(255, 150, 0));
			hpenselectold = (HPEN)SelectObject(hDC, hpenselect);

		}
		//m_selectOrbbit
		Ellipse(hDC, m_vOrbit[i].left, m_vOrbit[i].top, m_vOrbit[i].right, m_vOrbit[i].bottom);
		if (m_selectOrbit==i) {
			SelectObject(hDC, hpenselectold);
			DeleteObject(hpenselect);
			hpenselect = nullptr;

		}
	}

	for (int i = 0; i < m_vUnits.size(); i++) {
		HPEN hpenselect=nullptr;
		HPEN hpenselectold= nullptr;
		if (m_vUnits[i].Getselect()) {
			hpenselect = CreatePen(PS_SOLID, 3, RGB(255, 150, 0));
			hpenselectold=(HPEN)SelectObject(hDC, hpenselect);

		}
		Cbutton &m_testbutt = m_vUnits[i];

		RECT rctmp = m_testbutt.GetObjRECT();
		m_testbutt.draw(hDC);
		Rectangle(hDC, rctmp.left, rctmp.top, rctmp.right, rctmp.bottom);
		if (m_vUnits[i].Getselect()) {
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

		for (auto &button : m_vUnits) {
			button.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}

	}

	break;
	case WM_LBUTTONUP:
	{
		Point mousetmp{ LOWORD(lParam),HIWORD(lParam) };
		Point midpos{ m_rcClient.right / 2,m_rcClient.bottom / 2 };
		
		mousetmp=mousetmp - midpos;
		int size = mousetmp.length();
		m_selectOrbit = -1;
		for (int i = 0; i < m_vOrbit.size();i++) {
			int tmpsize = (m_vOrbit[i].bottom - m_vOrbit[i].top)/2;
			tmpsize -= size;
			tmpsize=abs(tmpsize);
			if (tmpsize <=10)
			{
				m_selectOrbit = i;
				return true;
			}


		}
		for (auto &button : m_vUnits) {
			button.SetMouseLUp(POINT{ LOWORD(lParam),HIWORD(lParam) });
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

	case ENUM_CHILD_MESSGE::GETINSERTUNIT:
	if(m_vinsert_ID_Units.size()){
		RECT tmp = m_vOrbit[m_vinsert_ID_Units.back().orbit];
		int size = tmp.right - tmp.left;
		size /= 2;
		*((int *)wParam) = size;
		*((int *)lParam) = m_vinsert_ID_Units.back().unitID;

		m_vinsert_ID_Units.pop_back();

		return true;
	}
	
		break;


	default:
		break;
	}

	return 0;
}
