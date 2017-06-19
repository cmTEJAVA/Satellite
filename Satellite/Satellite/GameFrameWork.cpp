#include "stdafx.h"
#include "GameFrameWork.h"
#include "Logo.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "HELPScene.h"
#include "Logo3DScene.h"
#include "TestScene.h"
#include "Sound.h"

CGameFrameWork::CGameFrameWork()
{
	snd = new Sound_Func;
	snd->Add_sound();
}


CGameFrameWork::~CGameFrameWork()
{
	delete snd;
}

bool CGameFrameWork::Create(HWND hWnd, HINSTANCE hInstance)
{
	m_hWnd = hWnd;
	m_hInstance = hInstance;
	::GetClientRect(hWnd, &m_rcClient);	
	ChangeScene(ENUM_SCENE::TITLE);
	g_DIVIDE_MAX_SIZE = 100;//(ENEMY_MAX_R_SIZE / cos((PI - DIVIDE_RADIAN) / 2));

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
		snd->Play_effect(ENUM_SOUND::CLICK);
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
		snd->Play_effect(ENUM_SOUND::LOGO);
		snd->Play_effect(ENUM_SOUND::LOGO2);
		break;
	case ENUM_SCENE::GAME:	
		snd->Play_effect(ENUM_SOUND::CLICK);
		snd->Stop_bgm(ENUM_SOUND::INTRO);
		snd->Stop_bgm(ENUM_SOUND::GAMEOVER);
		m_intro_bgm = (bool)ENUM_INTRO_BGM::OFF;
		snd->Play_bgm(ENUM_SOUND::BACK);
		m_Scenes = new CGameScene;
		m_Scenes->snd_init(snd);
		m_Scenes->Initialize(this, m_hWnd);
		break;
	case ENUM_SCENE::MENU:		
		if(!m_intro_bgm)
		{
			snd->Stop_bgm(ENUM_SOUND::BACK);
			snd->Stop_bgm(ENUM_SOUND::GAMEOVER);
			snd->Play_bgm(ENUM_SOUND::INTRO);
			m_intro_bgm = (bool)ENUM_INTRO_BGM::ON;
		}
		m_Scenes = new CMenuScene;
		m_Scenes->Initialize(this, m_hWnd);
		break;
	case ENUM_SCENE::HELP:
		snd->Play_effect(ENUM_SOUND::CLICK);
		m_Scenes = new CHELPScene;
		m_Scenes->snd_init(snd);
		m_Scenes->Initialize(this, m_hWnd);
		break;

	case ENUM_SCENE::TITLE3D:
		m_Scenes = new CLogo3DScene;
		m_Scenes->Initialize(this, m_hWnd);
		break;

	case ENUM_SCENE::TEST:
		m_Scenes = new CTestScene;
		m_Scenes->Initialize(this, m_hWnd);
		break;

	default:
		break;
	}
}
