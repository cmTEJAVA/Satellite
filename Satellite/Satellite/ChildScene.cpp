#include "stdafx.h"
#include "ChildScene.h"


CChildScene::CChildScene()
{
}


CChildScene::~CChildScene()
{
}

void CChildScene::Update()
{
}

void CChildScene::Draw(HDC hDC)
{
}

bool CChildScene::Keyboard(UINT message, WPARAM wParam)
{
	return false;
}

bool CChildScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	return false;
}

bool CChildScene::Initialize(CScene * pparentScene, HWND hWnd)
{
	m_parentScene = pparentScene;
	m_hWnd = hWnd;
	return true;
}

void CChildScene::ReleaseObjects()
{
}

UINT CChildScene::GetSceneMessge(UINT message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
