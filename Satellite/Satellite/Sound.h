#pragma once

#include "FMOD_32\inc\fmod.h"
#include "FMOD_32\inc\fmod.hpp"
#include "FMOD_32\inc\fmod_errors.h"

#pragma comment (lib, "FMOD_32/lib/fmodex_vc")

using namespace FMOD;

class Sound_Func
{
public:
	Sound_Func();
	~Sound_Func();

public:
	System * pSystem;
	Sound * pSound[5];
	Channel * pChannel[5];

	void sound_init();
	void sound_playing(int i);
	void sound_del();
};

