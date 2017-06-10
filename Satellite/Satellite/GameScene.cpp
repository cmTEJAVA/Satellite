#include "stdafx.h"
#include "GameFrameWork.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "EditChildScene.h"
#include "GameOverScene.h"

CGameScene::CGameScene()
{
}


CGameScene::~CGameScene()
{
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
	m_Gametime++;
	if (m_Gametime > 25) {
		plusEnemy();
		m_Gametime = 0;
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
		}
			break;
		default:
			break;
		}

	}

	for (int i = 0; i < 2; i++) {
		if (!m_arrbutton[i].Getselect()) continue;
		switch (i)
		{
		case 0:
			if (m_ChildScenes) {
				m_arrbutton[i].Setselect(false);
				PopChildScene();
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
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETORBITMAX, 1, 0);
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETORBITSIZE, 0, m_vOrbit[0]);

				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETUNITMAX, 2, 0);
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETUNITPATH, 0, (LPARAM)L"Resorce/button/bullet unit button.png");
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETUNITPATH, 1, (LPARAM)m_arrUnitszPath[1]);
				
			}
			//	retrun;

			break;
		default:
			break;
		}
		return;
	}

	if (m_test_player.GetLife() <= 0.f)
	{
		ChangeChildScene(ENUM_SCENE_CHILD::GameOver);
	}


}

void CGameScene::Draw(HDC hDC)
{
	//FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(GRAY_BRUSH));
	m_bmp_backimg.draw(hDC);

	m_EnemyManager.draw(hDC);

	m_test_player.draw(hDC);

	m_arrbutton[0].draw(hDC);
	if (!m_ChildScenes)
		m_arrbutton[1].draw(hDC);

	for (auto&q : m_listUnits) {
		q.draw(hDC);
	}

	m_BulletManager.draw(hDC);

	if (m_ChildScenes)m_ChildScenes->Draw(hDC);



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

	GetClientRect(hWnd, &m_rcClient);
	m_Gametime = 0;
	m_vOrbit.push_back(100);

	m_arrUnitszPath[(int)ENUM_UNIT::BULLET_UNIT] = L"Resorce/Test/bullet unit.bmp";
	m_arrUnitszPath[(int)ENUM_UNIT::TESLA_UNIT] = L"Resorce/Test/tesla.png";


	m_arrbutton[0].OnCreatCimg(L"Resorce/button/green arrow back.png");
	m_arrbutton[0].SetObjRECT(RECT{ -15,-15,15,15 });
	m_arrbutton[0].SetPos(Point{ 20,20 });
	m_arrbutton[1].OnCreatCimg(L"Resorce/button/option.png");
	m_arrbutton[1].SetObjRECT(RECT{ -20,-20,20,20 });
	m_arrbutton[1].SetPos(Point{ m_rcClient.right - 30,m_rcClient.bottom - 30 });




	m_bmp_backimg.OnCreatCimg(L"Resorce/Test/testback.jpg");
	m_bmp_backimg.SetObjRECT(m_rcClient);


	m_test_player.OnCreatplayerimg
	(
		Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 },
		L"Resorce/Test/ss3.bmp",
		1.f, 16, 0.6f
	);

	m_test_player.Setdestroyedimg(L"Resorce/Test/ss4.bmp");


	for (int i = 0; i < 1; i++) {
		plusUnit( ENUM_UNIT::BULLET_UNIT, Point{ m_rcClient.right / 2 + 100,m_rcClient.bottom / 2 });
	}

	RECT playerimgtmprect = m_test_player.m_imgUnit.GetObjRECT();
	int playersize= playerimgtmprect.right- playerimgtmprect.left;
	playersize /= 2;
	m_BulletManager.OnCreateBulletImg();
	m_EnemyManager.OnCreatEnemy(Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 },playersize);


	return true;
}

void CGameScene::ReleaseObjects()
{
	CScene::ReleaseObjects();

}
