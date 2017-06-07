#include "stdafx.h"
#include "Sound.h"

#pragma comment(lib, "FMOD/lib/fmod64_vc.lib")

Sound_Func::Sound_Func()
{
	FMOD::System_Create(&pSystem);
	pSystem->init(
		FMOD_MAX_CHANNEL_WIDTH
		, FMOD_INIT_NORMAL
		, nullptr
	);

	for (auto& p : pSound) p = nullptr;
}


Sound_Func::~Sound_Func()
{
	for (int i = 0; i < SOUND_TYPE; ++i)
	{
		pSound[i]->release();
	}
	pSystem->release();

	pSystem->close();
}


void Sound_Func::Add_sound()
{
	pSystem->createSound(
		"Sound/BENDY+AND+THE+INK+MACHINE+(Build+Our+Machine).mp3"
		, FMOD_LOOP_NORMAL | FMOD_2D
		, nullptr
		, &pSound[(int)ENUM_SOUND::BACK]
	);

	pSystem->createSound(
		"Sound/gaster_blaster_sound_effect.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::TEST]
	);

}

void Sound_Func::Play_bgm(ENUM_SOUND type)
{
	pSystem->playSound(pSound[(int)type]
		, nullptr, false, &pChannel[(int)type]);
}

void Sound_Func::Play_effect(ENUM_SOUND type)
{
	//pSystem->update();
	pSystem->playSound(pSound[(int)type]
		, nullptr, false, nullptr);
}