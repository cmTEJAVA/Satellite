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
	TCHAR asdf[50] = L"EditChildScene";
	DrawText(hDC, asdf, lstrlen(asdf), &m_rcClinet,DT_TOP|DT_LEFT);
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
