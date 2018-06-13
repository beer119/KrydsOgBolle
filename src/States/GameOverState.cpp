/*
 * GameOverState.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */

#include "../Game.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "GameOverState.h"

#include <iostream>
using namespace std;
const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}
void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
bool GameOverState::onEnter()
{
	std::cout << "entering GameOverState\n";



return true;
}


bool GameOverState::onExit()
{

return true;
}
void GameOverState::update()
{

}
void GameOverState::render()
{

}

void GameOverState::setCallbacks(const std::vector<Callback>&callbacks)
{

}
