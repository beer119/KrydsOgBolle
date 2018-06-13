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

const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{




}
void PlayState::render()
{



}
bool PlayState::onEnter()
{

	return true;
}
bool PlayState::onExit()
{



std::cout << "exiting PlayState\n";
return true;
}


