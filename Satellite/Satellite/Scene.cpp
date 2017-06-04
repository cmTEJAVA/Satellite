#include "stdafx.h"
#include "Scene.h"


CScene::CScene()
{
}

CScene::~CScene()
{
	ReleaseObjects();
}

void CScene::Update()
{
}

void CScene::Draw(HDC hDC)
{
}

bool CScene::Keyboard(UINT message, WPARAM wParam, LPARAM lParam)
{
	return false;
}

bool CScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	return false;
}

bool CScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	m_Framework = pFramework;
	m_hWnd = hWnd;
	return true;
}

void CScene::ReleaseObjects()
{
}
