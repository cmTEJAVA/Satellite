#include "stdafx.h"
#include "GameFrameWork.h"


CGameFrameWork::CGameFrameWork()
{
}


CGameFrameWork::~CGameFrameWork()
{
}

bool CGameFrameWork::Create(HWND hWnd, HINSTANCE hInstance)
{
	m_hWnd = hWnd;
	m_hInstance = hInstance;
	::GetClientRect(hWnd, &m_rcClient);
	




	return false;
}

void CGameFrameWork::Render()
{
	BeginPaint();



	EndPaint();
}

void CGameFrameWork::Update(const float & frame_time)
{


}

void CGameFrameWork::Key_Event(UINT iMessage, WPARAM wParam)
{
	if (iMessage == WM_KEYDOWN)
		Key_Down(wParam);
	else if (iMessage == WM_KEYUP)
		Key_Up(wParam);
	else if (iMessage == WM_CHAR)
		Key_CHAR(wParam);

}

void CGameFrameWork::Key_Down(WPARAM wParam)
{
	switch (wParam)
	{
	

	}

}

void CGameFrameWork::Key_Up(WPARAM wParam)
{
	switch (wParam)
	{


	}
}

void CGameFrameWork::Key_CHAR(WPARAM wParam)
{
	switch (wParam)
	{


	}
}

void CGameFrameWork::Mouse_Event(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	POINT pt;
	::GetCursorPos(&pt);
	::ScreenToClient(m_hWnd, &pt);

	switch (iMessage)
	{

	}
}

void CGameFrameWork::Command(WPARAM wParam)
{
	switch (LOWORD(wParam))
	{
	
	}
}

bool CGameFrameWork::Release()
{
	return false;
}

void CGameFrameWork::PopScene()
{
	auto pScene = m_Scenes[m_nCurrentScene];
	m_Scenes[m_nCurrentScene] = nullptr;
	m_pCurrentScene = m_Scenes[--m_nCurrentScene];
	delete pScene;
}
