
#include <iostream>
#include <cstdlib>
#include "SoundManager.h"
#include <thread>
#include <chrono>         // std::chrono::seconds
#include <SDL.h>
#include "Game.h"
#include "InputHandler.h"
using namespace std;
int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;
	Uint32 frameStart, frameTime;
	Game::Instance()->init("Chapter 5", 100, 100, 640, 640, SDL_WINDOW_MAXIMIZED);
	while(Game::Instance()->running())
	{

		frameStart = SDL_GetTicks();
		TheInputHandler::Instance()->update();
		Game::Instance()->handleEvents2();
		Game::Instance()->update();
		Game::Instance()->render();
		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime< DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}

	}

	Game::Instance()->clean();


}
