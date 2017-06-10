// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

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