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
#include <chrono>
#include <thread>
#include "../Game.h"
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
		if(menuSelect==1)
		{
			TheSoundManager::Instance()->playMusic("Boing",1);
		}
		else
		{
			menuSelect--;
			cout<<menuSelect<<endl;
			changed=true;
		}
	}
	if(TheInputHandler::Instance()->isPressed(SDLK_DOWN))
	{

		if(menuSelect==3)
				{
					TheSoundManager::Instance()->playMusic("Boing",1);
				}
				else
				{
		menuSelect++;
		cout<<menuSelect<<endl;
		changed=true;
				}
	}
	if(TheInputHandler::Instance()->isPressed(SDLK_SPACE)||TheInputHandler::Instance()->isPressed(SDLK_RETURN))
	{
			cout<<"menu item " << menuSelect<< " is selected"<<endl;
			if(menuSelect==1)
				TheGame::Instance()->getStateMachine()->changeState(new PlayState());
			if(menuSelect==3)
				exit(0);
	}

// nothing for now
}
void MainMenuState::render()
{




}
bool MainMenuState::onEnter()
{
	string pathSFX="assets/Lydfiler/menu/Start et nyt spil.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Start",SOUND_MUSIC);

	pathSFX="assets/Lydfiler/menu/Afslut.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Afslut",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/menu/Indstillinger.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Indstillinger",SOUND_MUSIC);


	pathSFX="assets/Lydfiler/menu/Boing 2.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Boing",SOUND_MUSIC);

	pathSFX="assets/Lydfiler/menu/Velkommen.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Velkommen",SOUND_MUSIC);
	TheSoundManager::Instance()->playMusic("Velkommen",1);
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono;
	sleep_for(nanoseconds(1));
	sleep_until(system_clock::now() + seconds(4));
	std::cout << "entering MenuState\n";
	return true;



}
void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
{

}

bool MainMenuState::onExit()
{
	return true;
}


