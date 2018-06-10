//============================================================================
// Name        : KrydsOgBolle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

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
int main() {

	cout << "Enter player 1" << endl;
	string name1;
	cin >> name1;
	cout<< "hi "+ name1<<endl;
	cout << "Enter player 2" << endl;
	string name2;
	cin >> name2;
	cout<< "hi "+ name2<<endl;
	int board[3][3] = {
	   {0, 0, 0} ,   /*  initializers for row indexed by 0 */
	   {0, 0, 0} ,   /*  initializers for row indexed by 1 */
	   {0, 0, 0}   /*  initializers for row indexed by 2 */
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
