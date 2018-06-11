/*
 * SoundManager.h
 *
 *  Created on: Jun 10, 2018
 *      Author: beer
 */

#ifndef SOUNDMANAGER_H_
#define SOUNDMANAGER_H_

//
//  SoundManager.h
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 26/03/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#ifndef __SDL_Game_Programming_Book__SoundManager__
#define __SDL_Game_Programming_Book__SoundManager__

#include <iostream>
#include <map>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
using namespace std;
enum sound_type
{
    SOUND_MUSIC = 0,
    SOUND_SFX = 1
};

class SoundSystem
{
public:

    static SoundSystem* Instance()
    {
        if(instance == 0)
        {
        	instance = new SoundSystem();
            return instance;
        }
        return instance;
    }

    bool load(string fileName, string id, sound_type type);

    void playSound(std::string id, int loop);
    void playMusic(std::string id, int loop);

private:

    static SoundSystem* instance;

    std::map<string, Mix_Chunk*> SoundEffects;
    std::map<string, Mix_Music*> Music;

    SoundSystem();
    ~SoundSystem();

    SoundSystem(const SoundSystem&);
    SoundSystem& operator=(const SoundSystem&);
};

typedef SoundSystem TheSoundManager;

#endif /* defined(__SDL_Game_Programming_Book__SoundManager__) */




#endif /* SOUNDMANAGER_H_ */
