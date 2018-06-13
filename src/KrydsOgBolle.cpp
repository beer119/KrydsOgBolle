//============================================================================
// Name        : KrydsOgBolle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

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
/*

void printBoard(int board[3][3])
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
			{
				cout <<board[i][j];
			}
		cout<<endl;
	}
}
void winning(int board[3][3], int player, string name)
{
	for (int i=0;i<3;i++)
		{

				if( board[i][0]==player&& board[i][1]==player&& board[i][2]==player)
					{
						cout<<name<<" winds"<<endl;
						exit(0);

					}


		}

			for (int j=0;j<3;j++)
				{
				if( board[0][j]==player&& board[1][j]==player&& board[2][j]==player)
					{
						cout<<name<<" winds"<<endl;
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
void menu()
{
	TheSoundManager::Instance()->playMusic("Start",1);
	std::this_thread::sleep_for (std::chrono::seconds(4));
	TheSoundManager::Instance()->playMusic("Indstillinger",1);
	std::this_thread::sleep_for (std::chrono::seconds(4));
	TheSoundManager::Instance()->playMusic("Afslut",1);
	cout << "Enter 1-3" << endl;
	int menuIn=-1;
	cin >> menuIn;
	if(menuIn==1)
	{

		cout<<" the game will start"<<endl;
	}
	else if(menuIn==2)
	{
		cout<<"Indstillinger has yet to be implemented. Try again"<<endl;
		menu();
	}
	else if(menuIn== 3)
	{
		cout<<"exit the game"<<endl;
		exit(0);
	}

}
int main() {
	if( SDL_Init(SDL_INIT_EVERYTHING) < 0 )
	    {
	        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	        exit(0);
	    }
	SDL_Event e;
	cout<<"before"<<endl;
	 while( SDL_PollEvent( &e ) != 0){

	    switch( e.type ){
	      case SDL_KEYDOWN:
	        printf( "Key press detected\n" );
	        break;

	      case SDL_KEYUP:
	        printf( "Key release detected\n" );
	        break;

	      default:
	        break;
	    }
	  }
	 int quit = 0;
     while( !quit ){


         while( SDL_PollEvent( &e ) ){

        	 switch( e.type ){
        	 	      case SDL_KEYDOWN:
        	 	        printf( "Key press detected\n" );
        	 	        break;

        	 	      case SDL_KEYUP:
        	 	        printf( "Key release detected\n" );
        	 	        break;

        	 	      default:
        	 	        break;
        	 	    }

         }

     }
	 cout<<"after"<<endl;
	string pathSFX="assets/Lydfiler//Start et nyt spil.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Start",SOUND_MUSIC);

	pathSFX="assets/Lydfiler/Afslut.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Afslut",SOUND_MUSIC);
	pathSFX="assets/Lydfiler/Indstillinger.mp3";
	TheSoundManager::Instance()->load(pathSFX,"Indstillinger",SOUND_MUSIC);

	 menu();
	cout << "Enter player 1" << endl;
	string name1;
	cin >> name1;
	cout<< "hi "+ name1<<endl;
	cout << "Enter player 2" << endl;
	string name2;
	cin >> name2;
	cout<< "hi "+ name2<<endl;
	int board[3][3] = {
	   {0, 0, 0} ,
	   {0, 0, 0} ,
	   {0, 0, 0}
	};
	int playersTurn=1;
	while(true)
	{
		printBoard(board);
		if(playersTurn==1)
			cout<<name1<<"'s turn"<<endl;
		else
			cout<<name2<<"'s turn"<<endl;
		cout<<"enter cordinate"<<endl;
		int first;
		int second;
		cin >>first;
		cin >>second;
		if (board[first][second]==0)
		{
			board[first][second]=playersTurn;
			if(playersTurn==1)
			{
				cout <<name1<< " has taken " <<first<< ", "<<second<<endl;
				playersTurn=2;
			}
			else if(playersTurn==2)
			{
				cout <<name2<< " has taken " <<first<< ", "<<second<<endl;
				playersTurn=1;
			}
		}
		else
		{
			cout<<"place is taken"<<endl;
		}
		winning(board, 1 , name1);
		winning(board, 2 , name2);


	}
	return 0;
}
*/
