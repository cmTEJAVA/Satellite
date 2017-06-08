#include "stdafx.h"
#include "GameFrameWork.h"
#include "Logo.h"
#include "TestScene.h"
#include "MenuScene.h"
#include "HELPScene.h"
#include "Logo3DScene.h"
#include "Sound.h"

Sound_Func snd;

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
	
	ChangeScene(ENUM_SCENE::TITLE);
	snd.Add_sound();
	snd.Play_bgm(ENUM_SOUND::INTRO);

	return false;
}

void CGameFrameWork::Render()
{
	BeginPaint();

	if (m_Scenes) m_Scenes->Draw(m_memDC);


	EndPaint();
}

void CGameFrameWork::Update(const float & frame_time)
{
	if (m_Scenes) m_Scenes->Update();


}

void CGameFrameWork::Key_Event(UINT iMessage, WPARAM wParam)
{
	if (iMessage == WM_KEYDOWN)
		Key_Down(wParam);
	else if (iMessage == WM_KEYUP)
		Key_Up(wParam);
	else if (iMessage == WM_CHAR)
		Key_CHAR(wParam);

	

	if (m_Scenes) m_Scenes->Keyboard(iMessage,wParam);

}

void CGameFrameWork::Key_Down(WPARAM wParam)
{
	
	switch (wParam)
	{
	case VK_SPACE:
		snd.Play_effect(ENUM_SOUND::TEST);
		break;
	case VK_F1:
		snd.Play_effect(ENUM_SOUND::CLICK);

		break;
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
	default:
		if (m_Scenes) m_Scenes->Mouse(iMessage, wParam, lParam);
		break;
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
	ChangeScene(ENUM_SCENE::END);
	return false;
}

void CGameFrameWork::PopScene()
{
	if(m_Scenes) delete m_Scenes;
	m_Scenes = nullptr;
}


void CGameFrameWork::ChangeScene(ENUM_SCENE iID)
{
	PopScene();
	switch (iID)
	{
	case ENUM_SCENE::TITLE:
		m_Scenes = new CLogoScene;
		m_Scenes->Initialize(this, m_hWnd);
		break;
	case ENUM_SCENE::TEST:
		snd.Play_effect(ENUM_SOUND::CLICK);

		m_Scenes = new CTestScene;
		m_Scenes->Initialize(this, m_hWnd);
		break;
	case ENUM_SCENE::MENU:
		snd.Play_effect(ENUM_SOUND::CLICK);

		m_Scenes = new CMenuScene;
		m_Scenes->Initialize(this, m_hWnd);
		break;
	case ENUM_SCENE::HELP:
		snd.Play_effect(ENUM_SOUND::CLICK);

		m_Scenes = new CHELPScene;
		m_Scenes->Initialize(this, m_hWnd);

		break;

	case ENUM_SCENE::TITLE3D:
		m_Scenes = new CLogo3DScene;
		m_Scenes->Initialize(this, m_hWnd);

		break;

	default:
		break;
	}
}
