//File Name: HW2_110704008.cpp
//Author: 羅瑋翔
//Email Address: xianglo9121.mg10@nycu.edu.tw
//HW Number: 2
//Description: this program is used to calculate how many month it will take to pay off the loan and how much the users paid for the interest.
//Last Changed: 09, 30, 2022
//Anything special? My program provide more interaction to the users. Let the users easly understand what information.
//I provide additional functions: (1)Let the users to score for the program. (2)provide more illustrations to let the users understand what the number represent.
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	cout << "This program is used to tell you how many month it will take to pay off the loan" << endl;
	cout << "and how much you paid for the interest" << endl;
	
	int price, payment, interest2, totalInterest, score;
	double rateYear, interest1;
	char ans;
	
	do
	{
		int month = 1, a = 1;
		int price, payment, interest2 = 0, totalInterest = 0;
		double rateYear, interest1 = 0;
		cout << "Enter the price of iPhone (integer) : ";
		cin >> price;
		cout << "Enter the rate per year (how many percent, double) : ";
		cin >> rateYear;
		cout << "Enter the monthly payment (integer) : ";
		cin >> payment;
	
		do
		{
			interest1 = (rateYear/12/100) * price;
			interest2 = floor(interest1 + 0.5);
			price = price - payment + interest2;
			if(price <= 0)
			{
				price = 0;
				a = 0;
			}
			cout << "month " << month << ' '<< '\t' << interest2 << '\t' << price << endl;
			month++;
			totalInterest += interest2;
		}while(a != 0);
		
		cout << "You will take " << month-1 << " to pay off the debt and interest" << endl;
		cout << "The interest you paid = " << totalInterest << "\n\n";
		cout << "Do you want to do it again ? Enter y for yes, n for no : ";
		cin >> ans;
		
	}while(ans == 'y' || ans == 'Y');
	
	cout << "How is your experience of the program, please score 1~3 (3 for good, 2 for not bad, 1 for terrible) : " << endl;
	cin >> score;
	switch(score)
	{
		case 3:
			cout << "Thanks! : )" << endl;
			break;
		case 2:
			cout << "I will provide you a better experience next time." << endl;
			break;
		case 1:
			cout << "Get away : (" << endl;
			break;
		default:
			cout << "Invalid score" << endl;
			break;
	}
	
	system("PAUSE");
	return 0;
}