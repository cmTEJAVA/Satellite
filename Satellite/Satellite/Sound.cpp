#include "stdafx.h"
#include "Sound.h"


Sound_Func::Sound_Func()
{
}


Sound_Func::~Sound_Func()
{
}


void Sound_Func::sound_init()
{
	System_Create(&pSystem);
	pSystem->init(SOUND_TYPE, FMOD_INIT_NORMAL, NULL);

	pSystem->createSound(
		"BENDY+AND+THE+INK+MACHINE+(Build+Our+Machine).mp3"
		, FMOD_HARDWARE
		, NULL
		, &pSound[0]
	);

	pSystem->createSound(
		"gaster_blaster_sound_effect.mp3"
		, FMOD_HARDWARE | FMOD_LOOP_OFF
		, NULL
		, &pSound[1]
	);

}

void Sound_Func::sound_playing(ENUM_SOUND type)
{
	pSystem->update();
	pSystem->playSound(FMOD_CHANNEL_FREE, pSound[(int)type]
		, false, &pChannel[(int)type]);
}

void Sound_Func::sound_del()
{
	for (int i = 0; i < SOUND_TYPE; ++i)
	{
		pSound[i]->release();
	}
	pSystem->release();

	pSystem->close();
}