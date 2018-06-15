/*
 * GameState.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */




#include <iostream>
#include "../Game.h"
#include "../SoundManager.h"
#include "../InputHandler.h"
#include "PlayState.h"
#include <iostream>

#include "MainMenuState.h"
using namespace std;
const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update()
{
	if(menuSelect==1&&changed==true)
	{
		TheSoundManager::Instance()->playMusic("Start",1);
		changed=false;
	}
	else if (menuSelect==2&&changed==true)
	{
		TheSoundManager::Instance()->playMusic("Indstillinger",1);
		changed=false;
	}
	else if (menuSelect==3&&changed==true)
	{
		TheSoundManager::Instance()->playMusic("Afslut",1);
		changed=false;

	}
	if(TheInputHandler::Instance()->isPressed(SDLK_UP))
	{
		menuSelect--;
		cout<<menuSelect<<endl;
		changed=true;
	}
	if(TheInputHandler::Instance()->isPressed(SDLK_DOWN))
	{
		menuSelect++;
		cout<<menuSelect<<endl;
		changed=true;
	}
	if(TheInputHandler::Instance()->isPressed(SDLK_SPACE)||TheInputHandler::Instance()->isPressed(SDLK_RETURN))
	{
			cout<<"menu item " << menuSelect<< " is selected"<<endl;
			if(menuSelect)
				exit(0);
	}

// nothing for now
}
void MainMenuState::render()
{




}
bool MainMenuState::onEnter()
{
	string pathSFX="assets/Lydfiler//Start et nyt spil.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Start",SOUND_MUSIC);

	pathSFX="assets/Lydfiler/Afslut.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Afslut",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/Indstillinger.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Indstillinger",SOUND_MUSIC);

	std::cout << "entering MenuState\n";
	return true;

	return true;


}
void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
{

}

bool MainMenuState::onExit()
{
	return true;
}


