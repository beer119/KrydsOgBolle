//
//  SoundManager.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 26/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include "SoundManager.h"

SoundSystem* SoundSystem::instance;

SoundSystem::SoundSystem()
{

    if(Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 )<0)
    {
    	printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    	exit(0);
    }
}

SoundSystem::~SoundSystem()
{
    Mix_CloseAudio();
}

bool SoundSystem::load(std::string fileName, string id, sound_type type)
{
    if(type == SOUND_MUSIC)
    {
        Mix_Music* pMusic = Mix_LoadMUS(fileName.c_str());
        if(pMusic == 0)
        {
            cout << "Could not load music: ERROR - " << Mix_GetError() << endl;
            return false;
        }

        Music[id] = pMusic;
        return true;
    }
    else if(type == SOUND_SFX)
    {
        Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());
        if(pChunk == 0)
        {
            cout << "Could not load SFX: ERROR - " << Mix_GetError() << endl;
            return false;
        }

        SoundEffects[id] = pChunk;
        return true;
    }
    return false;
}

void SoundSystem::playMusic(string id, int loop)
{
    Mix_PlayMusic(Music[id], loop);
}

void SoundSystem::playSound(string id, int loop)
{
   int returnKode= Mix_PlayChannel(1, SoundEffects[id], loop);
   if(returnKode == -1) {
       fprintf(stderr, "Unable to play WAV file: %s\n", Mix_GetError());
   }
}
