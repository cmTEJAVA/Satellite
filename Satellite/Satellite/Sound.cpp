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
		"Sound/VIOLA_SKILL1.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::LOGO]
	);

	pSystem->createSound(
		"Sound/VIOLA_SKILL2.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::LOGO2]
	);

	pSystem->createStream(
		"Sound/Fez - Adventure.mp3"
		, FMOD_LOOP_NORMAL | FMOD_2D
		, nullptr
		, &pSound[(int)ENUM_SOUND::INTRO]
	);
	
	pSystem->createStream(
		"Sound/Waterflame - Jumper.mp3"
		, FMOD_LOOP_NORMAL | FMOD_2D
		, nullptr
		, &pSound[(int)ENUM_SOUND::BACK]
	);

	pSystem->createSound(
		"Sound/button click.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::CLICK]
	);
	
	pSystem->createSound(
		"Sound/laser sound.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::LASER]
	);

	pSystem->createSound(
		"Sound/tesla sound.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::TESLA]
	);

	pSystem->createSound(
		"Sound/bullet sound.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::BULLET]
	);

	pSystem->createSound(
		"Sound/shock wave sound.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::SHOCKWAVE]
	);

	pSystem->createSound(
		"Sound/explosion sound.mp3"
		, FMOD_DEFAULT | FMOD_LOOP_OFF
		, nullptr
		, &pSound[(int)ENUM_SOUND::EXPLOSION]
	);

}

void Sound_Func::Play_bgm(ENUM_SOUND type)
{
	pSystem->playSound(pSound[(int)type]
		, nullptr, false, &pChannel[(int)type]);

	if(type == ENUM_SOUND::BACK)
	pChannel[(int)type]->setVolume(0.5f);

}

void Sound_Func::Play_effect(ENUM_SOUND type)
{
	pSystem->update();
	pSystem->playSound(pSound[(int)type]
		, nullptr, false, nullptr);
}

void Sound_Func::Stop_bgm(ENUM_SOUND type)
{
	bool bPlaying;
	pChannel[(int)type]->isPlaying(&bPlaying);
	if (bPlaying)
		pChannel[(int)type]->stop();
}

void Sound_Func::Stop_effect()
{
}


