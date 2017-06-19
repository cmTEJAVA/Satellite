#include "stdafx.h"
#include "GameFrameWork.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "EditChildScene.h"
#include "GameOverScene.h"
#include "Sound.h"

void CGameScene::plusUnit(ENUM_UNIT ID, const Point & pos)
{

	int tmpdistans = pos.distance(Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 });

	char OrvitID = -1;
	for (int i = 0; i < m_vOrbit.size(); i++) {
		int tmporbitsize = abs(tmpdistans - m_vOrbit[i]);
		if (tmporbitsize < 10) {
			OrvitID = i;
			break;
		}
	}
	if (OrvitID < 0) return;

	if (m_vOrbitUnitN[OrvitID] >= (OrvitID+1) * 2) return;



	switch (ID)
	{
	case ENUM_UNIT::BULLET_UNIT:
		if (!m_MoneyManager.using_money(PRICE_UNIT_B))return;
		m_listUnits.push_back(CUnit{});
		m_listUnits.back().OnCreatUnit(pos,
			Point{ m_rcClient.right / 2 ,m_rcClient.bottom / 2 },
			m_arrUnitszPath[int(ENUM_UNIT::BULLET_UNIT)],
			0.8f, 1, 0.6f, 0.01f, 0.02f
			);
		m_listUnits.back().SetID(ENUM_UNIT::BULLET_UNIT);
		break;
	case ENUM_UNIT::TESLA_UNIT:
		if (!m_MoneyManager.using_money(PRICE_UNIT_T))return;
		m_listUnits.push_back(CUnit{});
		m_listUnits.back().OnCreatUnit(pos,
			Point{ m_rcClient.right / 2 ,m_rcClient.bottom / 2 },
			m_arrUnitszPath[int(ENUM_UNIT::TESLA_UNIT)],
			0.7f, 1, 0.6f, 0.01f, 0.02f
			);
		m_listUnits.back().SetID(ENUM_UNIT::TESLA_UNIT);
		m_BulletManager.insertTeslabullet(m_listUnits.back().m_imgUnit.Getposptr(), 120);

		break;
	case ENUM_UNIT::LASER_UNIT:
		if (!m_MoneyManager.using_money(PRICE_UNIT_L))return;
		m_listUnits.push_back(CUnit{});
		m_listUnits.back().OnCreatUnit(pos,
			Point{ m_rcClient.right / 2 ,m_rcClient.bottom / 2 },
			m_arrUnitszPath[int(ENUM_UNIT::LASER_UNIT)],
			0.5f, 1, 0.6f, 0.01f, 0.02f
			);
		m_listUnits.back().SetID(ENUM_UNIT::LASER_UNIT);
		break;
	case ENUM_UNIT::SHOCKWAVE_UNIT:
		if (!m_MoneyManager.using_money(PRICE_UNIT_S))return;
		m_listUnits.push_back(CUnit{});
		m_listUnits.back().OnCreatUnit(pos,
			Point{ m_rcClient.right / 2 ,m_rcClient.bottom / 2 },
			m_arrUnitszPath[int(ENUM_UNIT::SHOCKWAVE_UNIT)],
			0.4f, 1, 0.6f, 0.01f, 0.02f
			);
		m_listUnits.back().SetID(ENUM_UNIT::SHOCKWAVE_UNIT);

		m_BulletManager.insertShockbullet(m_listUnits.back().m_imgUnit.Getposptr());

		break;
	default:
		return;
		break;
	}
	m_vOrbitUnitN[OrvitID]++;
}

void CGameScene::Update_stageLevel()
{
	m_Gametime_for_stage++;
	if (m_time_stageLevel_UP > 0) {
		m_time_stageLevel_UP--;
	}

	if (m_Gametime_for_stage >STAGE_LEVEL_TERM) {
		m_Gametime_for_stage = 0;
		m_stageLevel = min(STAGE_LEVEL_MAX, m_stageLevel + 1);
		if (m_stageLevel < STAGE_LEVEL_MAX) {
			m_time_stageLevel_UP = MAX_TIME_STAGE_LEVEL_UP;
			snd_game->Play_effect(ENUM_SOUND::STAGEUP);
		}
	}

}

CGameScene::CGameScene()
{
}


CGameScene::~CGameScene()
{
}

void CGameScene::Update()
{
	m_MoneyManager.Update(m_ChildScenes);


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
				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETORBITMAX, m_vOrbit.size(), 0);
				for (int i = 0; i < m_vOrbit.size(); i++) {

				m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETORBITSIZE, i, m_vOrbit[i]);
				}

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
			
			if (testunitid < 0) {
				if (m_vOrbit.size() < m_vOrbitUnitN.size()) {

					if (m_MoneyManager.using_money(PRICE_ORBIT)) {
						int tmp = m_vOrbit.back() + ORBIT_DISTANCE;
						m_vOrbit.push_back(tmp);
						m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETORBITMAX, m_vOrbit.size(), 0);
						for (int i = 0; i < m_vOrbit.size(); i++) {

							m_ChildScenes->GetSceneMessge((UINT)ENUM_CHILD_MESSGE_EDIT::SETORBITSIZE, i, m_vOrbit[i]);
						}

					}
				}
			}
			else
				plusUnit((ENUM_UNIT)testunitid, tmppos);

		}


	}
	if (m_bPause) return;

	//이 이후로 게임진행 업데이트

	if (m_shake_radian > 0) {
		m_shake_radian=max(m_shake_radian- DAMAGE_SHAKE_TERM,0);
	}


	m_Gametime++;
	if (m_Gametime > ENEMY_ADD_delta(m_stageLevel)) {
		plusEnemy();
		m_Gametime = 0;
	}

	Update_stageLevel();


	if (m_MoneyManager.plus_money(m_EnemyManager.GetDelN()*PRICE_ENEMY)) {
		m_shake_radian = DAMAGE_SHAKE_TIME;

	}
//	m_EnemyManager.GetDelN();

	m_EnemyManager.Update();
	m_BulletManager.Update();
	int attack=m_EnemyManager.attack();
	if (attack > 0) {

		m_test_player.attack(0.05*attack);
	}

	m_test_player.Update();
	if (m_test_player.IsDamage()) {
		m_shake_radian = DAMAGE_SHAKE_TIME;
	}

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
		snd_game->Play_effect(ENUM_SOUND::EXPLOSION);
		snd_game->Stop_bgm(ENUM_SOUND::BACK);
		snd_game->Play_bgm(ENUM_SOUND::GAMEOVER);
		ChangeChildScene(ENUM_SCENE_CHILD::GameOver);
		m_bPause = false;
	}



}

void CGameScene::Draw(HDC hDC)
{
	//FillRect(hDC, &m_rcClient, (HBRUSH)GetStockObject(GRAY_BRUSH));
	RECT tmpClient = m_rcClient;

	m_bmp_backimg.Draw(hDC, tmpClient);

	if (m_shake_radian > 0) {

		tmpClient.left+=	sin(m_shake_radian)*5;
		tmpClient.right+=	sin(m_shake_radian)*5;
		m_bmp_backimg.Draw(hDC, tmpClient);
	}


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


	m_EnemyManager.draw(hDC);
	m_BulletManager.draw(hDC);

	if(m_test_player.GetLife() > 0.f)
		m_arrbutton[0].draw(hDC);
	if (!m_ChildScenes)
		m_arrbutton[1].draw(hDC);
	



	if (m_ChildScenes) {
		if (m_test_player.GetLife() > 0.f) {
			m_ChildScenes->Draw(hDC);
		}
	}
	
	


	for (auto&q : m_listUnits) {
		q.draw(hDC);
	}
	m_MoneyManager.Draw(hDC);
	//스테이지 그리기
	{
		HFONT myFont = CreateFont(23, 0, 0, 0, 800, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Consolas");
		HFONT oldFont = (HFONT)SelectObject(hDC, myFont);

		COLORREF textColor;

		if(m_time_stageLevel_UP>0)
			textColor = RGB(255, 50, 50);
		else
			textColor = RGB(255, 255, 255);

		auto oldtxtcolor = SetTextColor(hDC, textColor);
		auto oldBk = SetBkMode(hDC, TRANSPARENT);
		//	SetBkMode(backDC, TRANSPARENT);
		//score = 876543210;
		CString strmoney;

		strmoney.Format(L"%d", m_stageLevel);
		strmoney = L"STAGE " + strmoney;

		DrawText(hDC, strmoney, lstrlen(strmoney), &m_rcClient, DT_TOP | DT_CENTER);

		SelectObject(hDC, oldFont);
		DeleteObject(myFont);
		myFont = nullptr;
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

		//m_stageLevel++;
		//m_test_player.attack(0);
	}
	break;
	case WM_RBUTTONUP:
		//m_MoneyManager.using_money(1000);
		//
		//m_test_player.cure();
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
	m_time_stageLevel_UP = 0;
	m_shake_radian = 0;
	m_stageLevel = 1;
	m_bPause = false;
	m_Gametime_for_stage=0;
	GetClientRect(hWnd, &m_rcClient);
	m_Gametime = 0;
	m_vOrbit.push_back(100);
	for (int i = 0; i < ORBIT_MAX; i++) {
		m_vOrbitUnitN.push_back(0);
	}

	m_arrUnitszPath[(int)ENUM_UNIT::BULLET_UNIT] = L"Resorce/Game/bullet unit.bmp";
	m_arrUnitszPath[(int)ENUM_UNIT::TESLA_UNIT] = L"Resorce/Game/tesla.png";
	m_arrUnitszPath[(int)ENUM_UNIT::LASER_UNIT] = L"Resorce/Game/laser unit.bmp";
	m_arrUnitszPath[(int)ENUM_UNIT::SHOCKWAVE_UNIT] = L"Resorce/Game/shock wave unit.png";


	m_arrbutton[0].OnCreatCimg(L"Resorce/button/green arrow back.png");
	m_arrbutton[0].SetObjRECT(RECT{ -15,-15,15,15 });
	//m_arrbutton[0].SetPos(Point{ 20,20 });
	m_arrbutton[0].SetPos(Point{ m_rcClient.right - 20, 20 });

	m_arrbutton[1].OnCreatCimg(L"Resorce/button/option.png");
	m_arrbutton[1].SetObjRECT(RECT{ -20,-20,20,20 });
	m_arrbutton[1].SetPos(Point{  30,m_rcClient.bottom - 30 });




	m_bmp_backimg.Load(L"Resorce/Game/testback.jpg");
//	m_bmp_backimg.SetObjRECT(m_rcClient);


	m_test_player.OnCreatplayerimg
	(
		Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 },
		L"Resorce/Game/ss3.bmp",
		1.f, 16, 0.6f
	);

	m_test_player.Setdestroyedimg(L"Resorce/Game/ss4.bmp");


	//for (int i = 0; i < 1; i++) {
	//	plusUnit( ENUM_UNIT::TESLA_UNIT, Point{ m_rcClient.right / 2 + 100,m_rcClient.bottom / 2 });
	//}

	RECT playerimgtmprect = m_test_player.m_imgUnit.GetObjRECT();
	int playersize= playerimgtmprect.right- playerimgtmprect.left;
	playersize /= 2;
	m_BulletManager.OnCreateBulletImg();
	m_EnemyManager.OnCreatEnemyManager(
		Point{ m_rcClient.right / 2,m_rcClient.bottom / 2 }
	,playersize, snd_game);
	m_BulletManager.OnCreate(&m_EnemyManager, snd_game);
	m_MoneyManager.OnCreat(snd_game);

	return true;
}

void CGameScene::ReleaseObjects()
{
	CScene::ReleaseObjects();

}

void CGameScene::snd_init(Sound_Func *ptrs)
{
	snd_game = ptrs;
}
