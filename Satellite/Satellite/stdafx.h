// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

#include <time.h>
#include <math.h>
#include <atlimage.h>

#include <MMSystem.h>

#define WIDTH 800
#define HEIGHT 600

#define PI 3.141592
#define RADIAN(X) ((PI / 180) * X)

#define DIVIDE_N 20//��� �������� ����¾�
#define DIVIDE_RADIAN ((2 * PI) / DIVIDE_N)

#define ENEMY_MAX_R_SIZE 40

#define ORBIT_DISTANCE 55

#define MONEY_TERM 30

#define PRICE_UNIT_B 300
#define PRICE_UNIT_T 500
#define PRICE_UNIT_S 600
#define PRICE_UNIT_L 400
#define PRICE_ORBIT 1000
#define PRICE_ENEMY 20

#define ORBIT_MAX 4

#define STAGE_LEVEL_MAX 20
#define STAGE_LEVEL_TERM 2000

#define ENEMY_ADD_TIME_MAX 100
#define ENEMY_ADD_TIME_MIN 30

#define ENEMY_ADD_delta(LEVEL)  \
	(((ENEMY_ADD_TIME_MIN-ENEMY_ADD_TIME_MAX)/(float)STAGE_LEVEL_MAX)*LEVEL+ENEMY_ADD_TIME_MAX)


#define ATK_UNIT_B 0.2f
#define ATK_UNIT_L 0.04f
#define ATK_UNIT_S 0.005f
#define ATK_UNIT_T 0.003f


#define GAMEFPS			int(1000 / 60)

#define SOUND_TYPE 20



extern float g_DIVIDE_MAX_SIZE;

enum class ENUM_SCENE
{
	TITLE,
	MENU,
	GAME,
	HELP,
	TITLE3D,
	TEST,
	END
};

enum class ENUM_SCENE_CHILD
{
	EDIT
	, END
	, GameOver
};

enum class ENUM_SOUND
{
	LOGO
	, LOGO2
	, INTRO			// bgm
	, BACK			// bgm
	, CLICK
	, LASER
	, TESLA
	, BULLET
	, SHOCKWAVE	
	, EXPLOSION		// enemy
	, ATTACK		// player
//	, GAME_OVER		// bgm
};


enum class ENUM_UNIT
{
	BULLET_UNIT
	, TESLA_UNIT
	, LASER_UNIT
	, SHOCKWAVE_UNIT
	, END
};

enum class ENUM_BULLET
{
	STANDARD
	,LASER
	, SHOCKWAVE
	, TESLA
	, END
};
//szPath define


// sound
enum class ENUM_INTRO_BGM
{
	OFF
	, ON
};

enum class ENUM_BACK_BGM
{
	OFF
	, ON
};
