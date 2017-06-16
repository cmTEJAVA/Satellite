#include "stdafx.h"
#include "GameFrameWork.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "EditChildScene.h"
#include "GameOverScene.h"
#include "Sound.h"

CGameScene::CGameScene()
{
	snd_game = new Sound_Func;
	snd_game->Add_sound();
}


CGameScene::~CGameScene()
{
	delete snd_game;
}

void CGameScene::Update()
{
	if ( m_test_player.GetLife() <= 0.f&&m_ChildScenes ) {
		m_ChildScenes->Update();
		ENUM_SCENE changeID;
		if (m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_GOVER::GETCHANGESCENE,(WPARAM)&changeID,0)) {
			m_Framework->ChangeScene(changeID);
			//return;
		}
		return;

	}

	for (int i = 0; i < 2; i++) {
		if (!m_arrbutton[i].Getselect()) continue;
		switch (i)
		{
		case 0:
			if (m_ChildScenes) {
				m_arrbutton[i].Setselect(false);
				PopChildScene();
				m_bPause = false;
			}
			else {

				m_arrbutton[i].Setselect(false);
				m_Framework->ChangeScene(ENUM_SCENE::MENU);

			}

			break;
		case 1:
			if (!m_ChildScenes) {
				m_arrbutton[i].Setselect(false);

				ChangeChildScene(ENUM_SCENE_CHILD::EDIT);
				m_bPause = true;
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETORBITMAX, 1, 0);
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETORBITSIZE, 0, m_vOrbit[0]);

				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETUNITMAX, int(ENUM_UNIT::END), 0);
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETUNITPATH, 0, (LPARAM)L"Resorce/button/bullet unit button.png");
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETUNITPATH, 1, (LPARAM)L"Resorce/button/tesla unit button.png");
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETUNITPATH, 2, (LPARAM)L"Resorce/button/laser unit button.png");
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETUNITPATH, 3, (LPARAM)L"Resorce/button/shock wave unit button.png");
				
			}
			//	retrun;

			break;
		default:
			break;
		}
		return;
	}
	if (m_ChildScenes) {
		m_ChildScenes->Update();
		//return;


		Point tmppos;
		int testunitid;
		if (m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::GETINSERTUNIT, (WPARAM)&tmppos, (LPARAM)&testunitid)) {
			plusUnit((ENUM_UNIT)testunitid, tmppos);

		}


	}
	if (m_bPause) return;

	//이 이후로 게임진행 업데이트

	m_Gametime++;
	if (m_Gametime > 50) {
		plusEnemy();
		m_Gametime = 0;
	}



	m_EnemyManager.Update();
	m_BulletManager.Update();
	int attack=m_EnemyManager.attack();
	m_test_player.attack(0.05*attack);

	m_test_player.Update();


	for (auto&q : m_listUnits) {

		q.Update();
		
		switch (q.GetBullet())
		{
		case ENUM_BULLET::STANDARD:
		{
			Point ptpostmp = q.m_imgUnit.Getpos();
			Point ptdirtmp= ptpostmp;
			ptdirtmp = ptdirtmp - Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 };
			ptdirtmp.normalize();
			plusBullet(ENUM_BULLET::STANDARD,ptpostmp, ptdirtmp);
			snd_game->Play_effect(ENUM_SOUND::BULLET);
		}
			break;

		case ENUM_BULLET::LASER:
		{
			snd_game->Play_effect(ENUM_SOUND::LASER);
			m_BulletManager.insertlaserbullet(q.m_imgUnit.Getposptr());
		}
		break;
		//case ENUM_BULLET::TESLA:
		//{
		//	m_BulletManager.insertTeslabullet(q.m_imgUnit.Getposptr());
		//
		//
		//}
		break;
		default:
			break;
		}

	}

	if (m_test_player.GetLife() <= 0.f)
	{
		ChangeChildScene(ENUM_SCENE_CHILD::GameOver);
		m_bPause = false;

	}


}

void CGameScene::Draw(HDC hDC)
{
	//FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(GRAY_BRUSH));
	m_bmp_backimg.draw(hDC);
	{
		HBRUSH oldbr = (HBRUSH)SelectObject(hDC, GetStockObject(NULL_BRUSH));
		HPEN hpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 70));
		HPEN oldpen = (HPEN)SelectObject(hDC, hpen);
		POINT mid{ m_rcClient.right / 2,m_rcClient.bottom / 2 };

		for (int & q : m_vOrbit) {
			Ellipse(hDC, mid.x - q, mid.y - q, mid.x + q, mid.y + q);
		}

		SelectObject(hDC, oldbr);
		SelectObject(hDC, oldpen);
		DeleteObject(hpen);
	}

	m_test_player.draw(hDC);
	if(m_test_player.GetLife() > 0.f)
		m_arrbutton[0].draw(hDC);
	if (!m_ChildScenes)
		m_arrbutton[1].draw(hDC);
	

	m_EnemyManager.draw(hDC);

	m_BulletManager.draw(hDC);

	if (m_ChildScenes) {
		if (m_test_player.GetLife() > 0.f) {
			m_ChildScenes->Draw(hDC);
		}
	}
	
	


	for (auto&q : m_listUnits) {
		q.draw(hDC);
	}

	

	if (m_test_player.GetLife() <= 0.f)
		m_ChildScenes->Draw(hDC);

}

bool CGameScene::Mouse(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_ChildScenes) {
		if (m_ChildScenes->Mouse(message, wParam, lParam)) {
			return true;
		}
	}
	switch (message)
	{
	case WM_LBUTTONUP:
	{
		for (auto & button : m_arrbutton) {
			button.SetMouseLUp(POINT{ LOWORD(lParam),HIWORD(lParam) });
		}


		m_test_player.attack();
		//plusEnemy();
	}
	break;
	case WM_RBUTTONUP:
		m_test_player.cure();
		break;

	case WM_MOUSEMOVE:
		for (auto & buttonq : m_arrbutton) {
			buttonq.SetMouseMove(POINT{ LOWORD(lParam),HIWORD(lParam) });
	
		}
		break;
	case WM_LBUTTONDOWN:
		break;

	default:
		break;
	}




	return false;
}


bool CGameScene::Initialize(CGameFrameWork * pFramework, HWND hWnd)
{
	if (!CScene::Initialize(pFramework, hWnd)) return false;
	m_bPause = false;
	GetClientRect(hWnd, &m_rcClient);
	m_Gametime = 0;
	m_vOrbit.push_back(100);

	m_arrUnitszPath[(int)ENUM_UNIT::BULLET_UNIT] = L"Resorce/Game/bullet unit.bmp";
	m_arrUnitszPath[(int)ENUM_UNIT::TESLA_UNIT] = L"Resorce/Game/tesla.png";
	m_arrUnitszPath[(int)ENUM_UNIT::LASER_UNIT] = L"Resorce/Game/laser unit.bmp";
	m_arrUnitszPath[(int)ENUM_UNIT::SHOCKWAVE_UNIT] = L"Resorce/Game/shock wave unit.png";


	m_arrbutton[0].OnCreatCimg(L"Resorce/button/green arrow back.png");
	m_arrbutton[0].SetObjRECT(RECT{ -15,-15,15,15 });
	m_arrbutton[0].SetPos(Point{ 20,20 });
	m_arrbutton[1].OnCreatCimg(L"Resorce/button/option.png");
	m_arrbutton[1].SetObjRECT(RECT{ -20,-20,20,20 });
	m_arrbutton[1].SetPos(Point{ m_rcClient.right - 30,m_rcClient.bottom - 30 });




	m_bmp_backimg.OnCreatCimg(L"Resorce/Game/testback.jpg");
	m_bmp_backimg.SetObjRECT(m_rcClient);


	m_test_player.OnCreatplayerimg
	(
		Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 },
		L"Resorce/Game/ss3.bmp",
		1.f, 16, 0.6f
	);

	m_test_player.Setdestroyedimg(L"Resorce/Game/ss4.bmp");


	for (int i = 0; i < 1; i++) {
		plusUnit( ENUM_UNIT::LASER_UNIT, Point{ m_rcClient.right / 2 + 100,m_rcClient.bottom / 2 });
	}

	RECT playerimgtmprect = m_test_player.m_imgUnit.GetObjRECT();
	int playersize= playerimgtmprect.right- playerimgtmprect.left;
	playersize /= 2;
	m_BulletManager.OnCreateBulletImg();
	m_EnemyManager.OnCreatEnemy(Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 },playersize);
	m_BulletManager.OnCreate(&m_EnemyManager);


	return true;
}

void CGameScene::ReleaseObjects()
{
	CScene::ReleaseObjects();

}
