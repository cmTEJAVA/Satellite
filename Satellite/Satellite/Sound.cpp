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
	pSystem->init(5, FMOD_INIT_NORMAL, NULL);

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

void Sound_Func::sound_playing(int i)
{
	pSystem->update();
	pSystem->playSound(FMOD_CHANNEL_FREE, pSound[i]
		, false, &pChannel[i]);
}

void Sound_Func::sound_del()
{
	pSound[0]->release();
	pSound[1]->release();

	pSystem->release();

	pSystem->close();
}