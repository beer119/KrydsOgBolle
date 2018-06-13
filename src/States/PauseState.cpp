/*
 * PauseState.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */
#include "PauseState.h"

#include "../Game.h"
#include "MainMenuState.h"

#include "../InputHandler.h"


const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::update()
{
for(int i = 0; i < m_gameObjects.size(); i++)
{

}
}
void PauseState::render()
{
for(int i = 0; i < m_gameObjects.size(); i++)
{

}
}
bool PauseState::onEnter()
{

	std::cout << "entering PauseState\n";
	return true;
}
void PauseState::setCallbacks(const std::vector<Callback>&callbacks)
{

}

bool PauseState::onExit()
{



std::cout << "exiting PauseState\n";
return true;
}
