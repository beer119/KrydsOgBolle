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
#include <iostream>
#include <chrono>
#include <thread>
const std::string PlayState::s_playID = "PLAY";
int playersTurn;
int board[3][3] = {
	   {0, 0, 0} ,
	   {0, 0, 0} ,
	   {0, 0, 0}
	};

void PlayState::winning(int player)
{
	for (int i=0;i<3;i++)
		{

				if( board[i][0]==player&& board[i][1]==player&& board[i][2]==player)
					{
						TheSoundManager::Instance()->playMusic("vundet"+to_string(player),1);
						cout<<player<<" winds"<<endl;
						using namespace std::this_thread; // sleep_for, sleep_until
										using namespace std::chrono;
										sleep_for(nanoseconds(1));
										sleep_until(system_clock::now() + seconds(4));
						exit(0);

					}


		}

			for (int j=0;j<3;j++)
				{
				if( board[0][j]==player&& board[1][j]==player&& board[2][j]==player)
					{


					TheSoundManager::Instance()->playMusic("vundet"+to_string(player),1);
											cout<<player<<" winds"<<endl;
											using namespace std::this_thread; // sleep_for, sleep_until
						using namespace std::chrono;
						sleep_for(nanoseconds(1));
						sleep_until(system_clock::now() + seconds(4));
						exit(0);

					}
				}


	bool found0=false;
	for (int i=0;i<3;i++)
			{
				for (int j=0;j<3;j++)
					{
					if( board[i][j]==0)
						{
						found0=true;

						}
					}

			}

	if(found0==false)
	{
		cout<<"no more roome"<<endl;
		exit(0);
	}

}
void PlayState::playfield(int row, int column)
{

	if( board[row-1][column-1]==1)
		{
			TheSoundManager::Instance()->playMusic("optaget1",1);
			using namespace std::this_thread; // sleep_for, sleep_until
					using namespace std::chrono;
					sleep_for(nanoseconds(1));
					sleep_until(system_clock::now() + seconds(4));
		}
		if( board[row-1][column-1]==2)
			{
				TheSoundManager::Instance()->playMusic("optaget2",1);
				using namespace std::this_thread; // sleep_for, sleep_until
						using namespace std::chrono;
						sleep_for(nanoseconds(1));
						sleep_until(system_clock::now() + seconds(4));
			}

	string rowtxt = to_string(row);
	string columntxt = to_string(column);
	TheSoundManager::Instance()->playMusic(rowtxt+columntxt,1);

}
void PlayState::update()
{

	std::cout << "on update"<< playersTurn<<"\n";
	int Row=1;
	int Colums=1;
	while(true)
	{

		TheInputHandler::Instance()->update();
		if(TheInputHandler::Instance()->isPressed(SDLK_SPACE)||TheInputHandler::Instance()->isPressed(SDLK_RETURN))
			{
				if(board[Row-1][Colums-1]==0)
									{
										board[Row-1][Colums-1]=playersTurn;
										cout<<"taget "<<playersTurn<<endl;
									}
				else
				{
					cout<<"noy taget "<<playersTurn<<endl;
				}
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
		if(TheInputHandler::Instance()->isPressed(SDLK_UP))
			{
				if(Row==1)
				{
					TheSoundManager::Instance()->playMusic("Boing",1);
					using namespace std::this_thread; // sleep_for, sleep_until
					using namespace std::chrono;
					sleep_for(nanoseconds(1));
					sleep_until(system_clock::now() + seconds(1));
				}
				else
				{
					Row--;

				}
				playfield(Row,Colums);
			}
		if(TheInputHandler::Instance()->isPressed(SDLK_DOWN))
		{
			if(Row==3)
			{
				TheSoundManager::Instance()->playMusic("Boing",1);
				using namespace std::this_thread; // sleep_for, sleep_until
				using namespace std::chrono;
				sleep_for(nanoseconds(1));
				sleep_until(system_clock::now() + seconds(1));
			}
			else
			{
				Row++;
			}
			playfield(Row,Colums);
		}
		if(TheInputHandler::Instance()->isPressed(SDLK_RIGHT))
					{
						if(Colums==3)
						{
							TheSoundManager::Instance()->playMusic("Boing",1);
							using namespace std::this_thread; // sleep_for, sleep_until
							using namespace std::chrono;
							sleep_for(nanoseconds(1));
							sleep_until(system_clock::now() + seconds(1));
						}
						else
						{
							Colums++;;

						}
						playfield(Row,Colums);
					}
				if(TheInputHandler::Instance()->isPressed(SDLK_LEFT))
				{
					if(Colums==1)
					{
						TheSoundManager::Instance()->playMusic("Boing",1);
						using namespace std::this_thread; // sleep_for, sleep_until
						using namespace std::chrono;
						sleep_for(nanoseconds(1));
						sleep_until(system_clock::now() + seconds(1));
					}
					else
					{
						Colums--;
					}
					playfield(Row,Colums);
				}


				winning(playersTurn);
	}

}
void PlayState::render()
{



}
bool PlayState::onEnter()
{
	playersTurn=1;
	string pathSFX="assets/Lydfiler/spil/a1.mp3";
	TheSoundManager::Instance()->load(pathSFX,"11",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/a2.mp3";
	TheSoundManager::Instance()->load(pathSFX,"12",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/a3.mp3";
	TheSoundManager::Instance()->load(pathSFX,"13",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/b1.mp3";
	TheSoundManager::Instance()->load(pathSFX,"21",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/b2.mp3";
	TheSoundManager::Instance()->load(pathSFX,"22",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/b3.mp3";
	TheSoundManager::Instance()->load(pathSFX,"23",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/c1.mp3";
	TheSoundManager::Instance()->load(pathSFX,"31",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/c2.mp3";
	TheSoundManager::Instance()->load(pathSFX,"32",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/c3.mp3";
	TheSoundManager::Instance()->load(pathSFX,"33",SOUND_MUSIC);

	pathSFX="assets/Lydfiler/spil/Brik.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Brik",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/spiller 1s tur.mp3";
	TheSoundManager::Instance()->load(pathSFX,"spiller 1s tur",SOUND_MUSIC);

	pathSFX="assets/Lydfiler/spil/spiller 2s tur.mp3";
	TheSoundManager::Instance()->load(pathSFX,"spiller 2s tur",SOUND_MUSIC);



	pathSFX="assets/Lydfiler/spil/felt-optaget-af-spiller-1.mp3";
	TheSoundManager::Instance()->load(pathSFX,"optaget1",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/felt-optaget-af-spiller-2.mp3";
	TheSoundManager::Instance()->load(pathSFX,"optaget2",SOUND_MUSIC);

	pathSFX="assets/Lydfiler/spil/spiller-1-vinduer.mp3";
	TheSoundManager::Instance()->load(pathSFX,"vundet1",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/spil/spiller-2-vinduer.mp3";
	TheSoundManager::Instance()->load(pathSFX,"vundet2",SOUND_MUSIC);

	TheSoundManager::Instance()->playMusic("spiller 1s tur",1);
	std::cout << "on enter PlayState\n";
	return true;
}
bool PlayState::onExit()
{



std::cout << "exiting PlayState\n";
return true;
}


