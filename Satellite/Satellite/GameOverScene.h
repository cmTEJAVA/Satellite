#pragma once
#include "ChildScene.h"
#include <vector>
#include "Button.h"
#include "BitmapObject.h"
#include "GameFrameWork.h"

class Sound_Func;

enum class ENUM_CHILD_MESSGE_GOVER
{
	GETCHANGESCENE,//return true시 메뉴로 바꿈,
	INIT_SOUND_PTR
};

class CGameOverScene :
	public CChildScene
{
	RECT m_rcClient;
	CBitmapObject m_back[2];
	Cbutton m_button[2];
	
	Sound_Func *over_snd;

	//CGameFrameWork m_FrameWork;
	float m_ftitleVmoveradian;
	float m_ftitleHmoveradian;


public:
	CGameOverScene();
	virtual ~CGameOverScene() override;

	virtual void Update() override;

	virtual void Draw(HDC hDC) override;

	//메세지가 처리 되지 않았으면 false가 반환
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CScene* pparentScene, HWND hWnd) override;

	virtual UINT GetSceneMessge(UINT message, WPARAM wParam, LPARAM lParam);

};

