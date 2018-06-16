/*
 * GameState.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */




#include "MainMenuState.h"
#include <iostream>
#include "PlayState.h"

#include "../InputHandler.h"

#include "../Game.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "../SoundManager.h"
const std::string PlayState::s_playID = "PLAY";
int playersTurn;
void PlayState::update()
{
	if(TheInputHandler::Instance()->isPressed(SDLK_SPACE)||TheInputHandler::Instance()->isPressed(SDLK_RETURN))
	{
	if(playersTurn==1)
	{
		TheSoundManager::Instance()->playMusic("spiller 2s tur",1);
		playersTurn=2;
	}
	else if(playersTurn==2)
		{
		TheSoundManager::Instance()->playMusic("spiller 1s tur",1);
		playersTurn=1;
		}
	}
	std::cout << "on update"<< playersTurn<<"\n";

}
void PlayState::render()
{



}
bool PlayState::onEnter()
{
	playersTurn=1;
	string pathSFX="assets/Lydfiler/spil/Brik.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Brik",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/spiller 1s tur.mp3";
	TheSoundManager::Instance()->load(pathSFX,"spiller 1s tur",SOUND_MUSIC);

	pathSFX="assets/Lydfiler/spil/spiller 2s tur.mp3";
		TheSoundManager::Instance()->load(pathSFX,"spiller 2s tur",SOUND_MUSIC);
		TheSoundManager::Instance()->playMusic("spiller 1s tur",1);
	std::cout << "on enter PlayState\n";
	return true;
}
bool PlayState::onExit()
{



std::cout << "exiting PlayState\n";
return true;
}


