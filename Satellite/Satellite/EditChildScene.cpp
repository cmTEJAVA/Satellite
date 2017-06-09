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
	HDC alphahdc = CreateCompatibleDC(hDC);
	HBITMAP alphahbmp = CreateCompatibleBitmap(hDC,m_rcClinet.right,m_rcClinet.bottom);
	HBITMAP alphaoldbmp = (HBITMAP)SelectObject(alphahdc, alphahbmp);

#pragma region alphahdc_draw
	TCHAR asdf[50] = L"EditChildScene";
	DrawText(alphahdc, asdf, lstrlen(asdf), &m_rcClinet,DT_TOP|DT_LEFT);


	RECT tmp = m_rcClinet;
	tmp.top = (m_rcClinet.bottom / 4) * 3;
	tmp.bottom -= 30;
	Rectangle(alphahdc, tmp.left, tmp.top, tmp.right, tmp.bottom);
#pragma endregion


	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = 255/2;
	bf.AlphaFormat = 0;
	AlphaBlend(hDC, 0, 0, m_rcClinet.right, m_rcClinet.bottom, alphahdc, 0, 0, m_rcClinet.right, m_rcClinet.bottom, bf);

	SelectObject(alphahdc, alphaoldbmp);
	DeleteObject(alphahbmp);
	DeleteDC(alphahdc);
}

bool CEditChildScene::Keyboard(UINT message, WPARAM wParam)
{
	return false;
}

bool CEditChildScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	return false;
}

bool CEditChildScene::Initialize(CScene * pparentScene, HWND hWnd)
{
	CChildScene::Initialize(pparentScene, hWnd);
	GetClientRect(hWnd, &m_rcClinet);
	return false;
}
