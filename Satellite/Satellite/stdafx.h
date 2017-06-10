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

#define WIDTH 800
#define HEIGHT 600

#define PI 3.141592
#define RADIAN(X) ((PI / 180) * X)

#define GAMEFPS			int(1000 / 60)

#define SOUND_TYPE 20


enum class ENUM_SCENE
{
	TITLE,
	MENU,
	GAME,
	HELP,
	TITLE3D,
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
	, INTRO
	, BACK
	, CLICK
	, LASER
	, ELECTRIC
	, BULLET
	, SHOCKWAVE	
	, EXPLOSION
	, ATTACK
	, TEST
};


enum class ENUM_UNIT
{
	BULLET_UNIT
	, TESLA_UNIT
	, LASER_UNIT
	, END
};

enum class ENUM_BULLET
{
	STANDARD
//	,LASER
	, END
};



//szPath define