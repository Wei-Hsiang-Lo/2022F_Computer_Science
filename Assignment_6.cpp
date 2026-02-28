//File Name: HW6_110704008.cpp
//Author:羅瑋翔
//Email Address: xianglo9121.mg10@nycu.edu,tw
//HW Number: 6
//Description:This program allows users to play tic-tac-toe with computer.
//Last Changed: 11, 28, 2022 
//Anything special? I provide the users clearly understand who is player with the mark O and change the color menifest
//on the screen from white to red.
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <windows.h>//change the color of O and X with this headfile

const int N = 3;
const int C = 5;

void fillPlayerO(char array[][N]);
//fill the position with O where player O chose

void fillPlayerX(char array[][N]);
//fill the position with X where player X chose

int bingo(char array[][N]);
//check if the player O or player X is bingo or not

int main()
{
	int count = 1, player;
	char a1[N][N] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char a2[N][N], answer, garbage;
	int full = 0, caseLine;
	
	cout << "This program allows users to play tic-tac-toe." << endl;
	cout << "Enter 1 for position 1, 2 for position 2, and so on." << endl;
	
	do
	{	
	
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				cout << a1[i][j] << " ";
			}
			cout << endl;
		}
		answer = ' ';
		srand(time(NULL));
		player = rand();
		caseLine = 0;
		
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				a2[i][j] = a1[i][j];
			}
		}//initialization
	
		do
		{
			full = 0;
			if(player % 2 == 0 && (full < 9))
			{
				fillPlayerO(a2);
				player++;
			}
			else if(player % 2 == 1 && (full < 9))
			{          
				fillPlayerX(a2);
				player++;
			}
			for(int i = 0; i < N; i++)
			{
				for(int j = 0; j < N; j++)
				{
					if(a2[i][j] == 'X' || a2[i][j] == 'O')
						full++;
				}
			}
		}while(full < 9 && !bingo(a2));
		
		caseLine = bingo(a2);
		
		if(caseLine == 1)
			cout << "Player O wins.\n";
		else if(caseLine == 2)
			cout << "Player X wins.\n";
		else if(full == 9 && !bingo(a2))
			cout << "There is no winner.\n";
		cout << "Do you want to play again? (Enter yes or no) : ";
		do
		{
			cin.get(answer);
		}while((answer != 'Y') && (answer != 'y') && (answer != 'N') && (answer != 'n'));
		do{
			cin.get(garbage);
		}while(garbage != '\n');
	}while(answer == 'Y' || answer == 'y');

	system("PAUSE");
	return 0;
}

void fillPlayerO(char array[][N])
{
	HANDLE hout;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int position, row, column;
	
	do
	{
		cout << "Player O selects position : ";
		cin >> position;
		
		row = position / 3;
		column = position % 3;
		if(column == 0 && row > 0)
		{
			column = 3;
			row--;
		}
	}while(array[row][column - 1] == 'X' || array[row][column - 1] == 'O');
	
	array[row][column - 1] = 'O';
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(array[i][j] == 'O')
			{
				SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "O" << " ";
				SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else if(array[i][j] == 'X')
			{
				SetConsoleTextAttribute(hout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "X" << " ";
				SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else
				cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void fillPlayerX(char array[][N])
{
	HANDLE hout;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int position, row, column;
	
	do
	{
		srand(time(NULL));
		position = rand() % 9 + 1;
		row = position / 3;
		column = position % 3;
		if(column == 0 && row > 0)
		{
			column = 3;
			row--;
		}
	}while(array[row][column - 1] == 'O' || array[row][column - 1] == 'X');
	
	cout << "Player X selects position : " << position << endl;
	array[row][column - 1] = 'X';
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(array[i][j] == 'X')
			{
				SetConsoleTextAttribute(hout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "X" << " ";
				SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else if(array[i][j] == 'O')
			{
				SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "O" << " ";
				SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			}
			else
				cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

int bingo(char array[][N])
{
	int ind = 0;
	
	for(int i = 0; i < N; i++)
	{
		if(array[i][0] == array[i][1] && array[i][0] == array[i][2])
		{
			if(array[i][0] == 'O')
				ind = 1;
			else
				ind = 2;
		}	
		else if(array[0][i] == array[1][i] && array[0][i] == array[2][i])
		{
			if(array[0][i] == 'O')
				ind = 1;
			else
				ind = 2;
		}
		else if(i == 0 && array[i][i] == array[1][1] && array[i][i] == array[2][2])
		{
			if(array[i][i] == 'O')
				ind = 1;
			else
				ind = 2;
		}
		else if(i == 0 && array[i][2] == array[1][1] && array[i][2] == array[2][i])
		{
			if(array[i][2] == 'O')
				ind = 1;
			else
				ind = 2;
		}
	}
	return ind;
}