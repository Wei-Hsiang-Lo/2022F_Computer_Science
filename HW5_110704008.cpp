//File Name: HW5_110704008.cpp
//Author:羅瑋翔
//Email Address: xianglo9121.mg10@nycu.edu,tw
//HW Number: 5
//Description:This program aims at designing a seat reservation system for economy cabin of A330 300.
//Last Changed: 11, 15, 2022 
//Anything special? I findSeat function to check whether the seat is available and
//use the return value to decide the seat needed to be marked as X or not
#include <iostream>
using namespace std;
#include <iomanip>

const int N1 = 35, N2 = 8;
const char order[] = "ACDEFGHK";

void fillArray(char arraySeat[][N2]);
//fill the column of the seat by A, C, D, E, F, G, H, K

int findSeat(char arraySeat[][N2], int seatInt, int ind);
//find whether the seat is available

void markSeat(char arraySeat[][N2], int seatInt,int ind );
//if the seat is sold change the menifest from A, C, D, E, F, G, H or K to X

int main()
{
	char arraySeat[N1][N2];
	int seatInt, ind;
	char seatChar[N2], ans, aAns[N2];
	
	fillArray(arraySeat);
	do
	{
		do
		{
			cout << "This program aims at designing a seat reservation system "
				<< "for economy cabin of A330 300." << endl;
			cin >> seatChar;
			seatInt = (seatChar[0] -'0') * 10 + (seatChar[1] - '0');
			for(int i = 0; i < 8; i++)
			{
				if(order[i] == seatChar[2])
					ind = i;
			}	
		}while(findSeat(arraySeat, seatInt, ind) == 0);	
		
		if(findSeat(arraySeat, seatInt, ind) == 1)
		{
			markSeat(arraySeat, seatInt, ind);
			
			for(int i = 0; i < N1; i++)
			{
				cout << i+10;
				for(int j = 0; j < N2; j++)
				{
					if(j == 2 || j == 6)
						cout << setw(4) << arraySeat[i][j];
					else
						cout << setw(2) << arraySeat[i][j];
				}
				cout << endl;
			} 
		}
		
		cout << "Do you want to buy another ticket (please answer yes or not) : ";
		cin >> aAns;
		ans = aAns[0];
	}while(ans == 'y' || ans == 'Y');
	
	system("PAUSE");
	return 0;
}

void fillArray(char arraySeat[][N2])
{
	int i, j;
	
	for(i = 0; i < N1; i++)
	{
		for(j = 0; j < N2; j++)
		{
			if((i == 18 && j <2) || (i == 19 && j < 6) || (i >= 31 && i <= 34 && j == 4))
			{
				arraySeat[i][j] = ' ';
			}
			else
				arraySeat[i][j] = order[j];
		}
	}
	return;
}

int findSeat(char arraySeat[][N2], int seatInt, int ind)
{
	if(arraySeat[seatInt-10][ind] == ' ')
		return 0;
	else 
		return 1;
}

void markSeat(char arraySeat[][N2], int seatInt,int ind)
{
	arraySeat[seatInt-10][ind] = 'X';
	return;
}