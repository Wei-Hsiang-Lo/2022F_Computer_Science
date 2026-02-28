//File Name: HW3_110704008.cpp
//Author: 羅瑋翔
//Email Address: xianglo9121.mg10@nycu.edu.tw
//HW Number: 3
//Description: This program is used to substitute temperature that can not be entered.
//Last Changed: 10,14, 2022
//Anything special? I provide the users clearly understand what the information mean?
#include <iostream>
using namespace std;

int nextLargest(int t);
//to get the next largest temperature

int nextSmallest(int t);
//to get the next smallest temperature

void nextLargestWarning(int, int);
//warn the users that the difference between the 
//desired temperature and nextLargest is > 30 by XX.

void nextSmallestWarning(int, int);
//warn the users that the difference between the 
//desired temperature and nextSmallest is > 30 by YY.

int main()
{
	cout << "This program is used to substitute a temperature that can be entered" << endl;
	cout << "Then compute the next largest and smallest temperature" << endl;
	cout << "And output XX if the difference between the next largest temperature and desired is > 30" << endl;
	cout << "And output YY if the difference between the next smallest temperature and desired is > 30\n\n";
	 
	int desiredT;
	int tHundreds, tTens, tDigits;
	
	for(int i = 1; i <= 10 ; i++)
	{
		cout << "Enter the temperature (integer) between 0 and 999 (inclusive) : ";
		cin >> desiredT;
	
		tHundreds = desiredT / 100;
		tTens = (desiredT % 100) / 10;
		tDigits = desiredT % 10;
		if(tHundreds == 2 || tHundreds == 5)//call the function
		{
			cout << nextLargest(desiredT) << " "<< nextSmallest(desiredT);
			nextLargestWarning(nextLargest(desiredT), desiredT);
			nextSmallestWarning(nextSmallest(desiredT), desiredT);
			cout << endl;
		}
		else if(tHundreds == 0 || (tHundreds != 0 && tHundreds != 2 && tHundreds != 5))
		{
			if(tTens == 2 || tTens == 5)
			{
				cout << nextLargest(desiredT) << " "<< nextSmallest(desiredT);
				nextLargestWarning(nextLargest(desiredT), desiredT);
				nextSmallestWarning(nextSmallest(desiredT), desiredT);
				cout << endl;
			}
			else if((tHundreds != 0) && tTens == 0)
			{
				cout << nextLargest(desiredT) << " "<< nextSmallest(desiredT);
				nextLargestWarning(nextLargest(desiredT), desiredT);
				nextSmallestWarning(nextSmallest(desiredT), desiredT);
				cout << endl;
			}
			else if((tHundreds == 0 && tTens == 0) || (tTens != 0 && tTens != 2 && tTens != 5))
			{
				if(tDigits == 0 || tDigits == 2 || tDigits == 5 )
				{
					cout << nextLargest(desiredT) << " "<< nextSmallest(desiredT);
					nextLargestWarning(nextLargest(desiredT), desiredT);
					nextSmallestWarning(nextSmallest(desiredT), desiredT);
					cout << endl;
				}
				else
					cout << desiredT << " " << "(Only one temperature can be outputted.)" << endl;
			}
		}
	}
	
	system("PAUSE");
	return 0;
}

int nextLargest(int t)
{
	int tHundreds, tTens, tDigits;
	tHundreds = t / 100;
	tTens = (t % 100) / 10;
	tDigits = t % 10;
	
	if(tHundreds == 2 || tHundreds == 5)
	{
		tHundreds += 1;
		tTens = 1;
		tDigits = 1;
	}
	else if((tHundreds != 0) && tTens == 0)
	{
		tTens += 1;
		tDigits = 1;
	}
	else if((tHundreds == 0 && tTens == 0) || (tHundreds != 0 && tHundreds != 2 && tHundreds != 5))
	{
		if(tTens == 2 || tTens == 5)
		{
			tTens += 1;
			tDigits = 1;
		}
		else if(tTens == 0 || (tTens != 0 && tTens != 2 && tTens != 5))
		{
			{      
				tDigits += 1;
			}
		}
	}
	if((tHundreds * 100 + tTens * 10 + tDigits) <= 999)
		return (tHundreds * 100 + tTens * 10 + tDigits);
	else
		return -1;
}

int nextSmallest(int t)
{
	int tHundreds, tTens, tDigits;
	tHundreds = t / 100;
	tTens = (t % 100) / 10;
	tDigits = t % 10;
	
	if(tHundreds == 2 || tHundreds == 5)
	{
		tHundreds -= 1;
		tTens = 9;
		tDigits = 9;
	}
	else if(tHundreds == 0 || (tHundreds != 0 && tHundreds != 2 && tHundreds != 5))
	{
		if(tTens == 2 || tTens == 5)
		{
			tTens -= 1;
			tDigits = 9;
		}
		else if((tHundreds != 0) && tTens == 0)
		{
			tHundreds -= 1;
			tTens = 9;
			tDigits = 9;
		}
		else if((tHundreds == 0 && tTens == 0) || (tTens != 0 && tTens != 2 && tTens != 5))
		{
			if(tDigits == 0 || tDigits == 2 || tDigits == 5 )
			{
				tDigits -= 1;
			}
		}
	}
	if((tHundreds * 100 + tTens * 10 + tDigits) >= 0)
		return (tHundreds * 100 + tTens * 10 + tDigits);
	else
		return -1;
}

void nextLargestWarning(int t1, int t2){
	if((t1 - t2) > 30 || t1 == -1)
		cout << " XX ";
}

void nextSmallestWarning(int t1, int t2){
	if((t2 - t1) > 30 || t1 == -1)
		cout << " YY ";
}