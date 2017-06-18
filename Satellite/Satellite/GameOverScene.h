#pragma once
#include "ChildScene.h"
#include <vector>
#include "Button.h"
#include "BitmapObject.h"
#include "GameFrameWork.h"

class Sound_Func;

enum class ENUM_CHILD_MESSGE_GOVER
{
	GETCHANGESCENE,//return true�� �޴��� �ٲ�,
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

	//�޼����� ó�� ���� �ʾ����� false�� ��ȯ
	virtual bool Mouse(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual bool Initialize(CScene* pparentScene, HWND hWnd) override;

	virtual UINT GetSceneMessge(UINT message, WPARAM wParam, LPARAM lParam);

};

