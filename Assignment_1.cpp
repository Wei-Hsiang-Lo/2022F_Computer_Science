//File Name: HW1_110704008.cpp
//Author:羅瑋翔
//Email Address: xianglo9121.mg10@nycu.edu,tw
//HW Number: 1
//Description:This program enables users to enter a character to compose XD by the character.
//Last Changed: 09, 14, 2022 
//Anything special? I used two kinds of iterative method to form this program.
//I provide additional functions:Ask users whether they are satiesfied with this program.
#include<iostream>
using namespace std;

int main(){
	char ans, rate;
	cout << "This program is will ask you to enter a character and" << endl;
	cout << "it will output a large XD composed by the character you entered." << "\n\n";
	char input;
	do{
		cout << "Enter a character : ";
		cin >> input ;
		for(int i = 1 ; i <= 9; i++){//there are 9 rows
			if(i == 1 || i == 9){
				for(int j = 1; j <= 21; j++){
					if(j == 1 || j == 9 || (j <= 17 && j >= 13))
						cout << input;
					else
						cout << " ";
				}
				cout << endl;
			}
			else if(i ==  2 || i == 8){
				for(int j = 1; j <= 21; j++){
					if(j == 2 || j == 8 || j == 13 || j == 18)
						cout << input;
					else
						cout << " ";
				}
				cout << endl;
			}
			else if(i == 3 || i == 7){
				for(int j = 1; j <= 21; j++){
					if(j == 3 || j == 7 || j == 13 || j == 19)
						cout << input;
					else
						cout << " ";
				} 
				cout << endl;
			}
			else if(i == 4 || i == 6){
				for(int j = 1; j <= 21; j++){
					if(j == 4 || j == 6 || j == 13 || j == 20)
						cout << input;
					else
						cout << " ";
				}
				cout << endl;
			}
			else{
				for(int j = 1; j <= 21; j++){
					if(j == 5 || j == 13 || j == 21)
						cout << input;
					else
						cout << " ";
				}
					cout << endl;
			}
		}
		
		cout << "Do you want to continue? Press y for yes, n for no : ";
		cin >> ans;
		}while(ans == 'y' || ans == 'Y');
		cout << "Are you satisfied with this experience ? (Please enter y for yes, n for no) : ";
		cin >> rate;
		if(rate == 'y' || rate == 'Y')
			cout << "thank you :)" << endl;
		else if(rate == 'n' || rate == 'N')
			cout << "So sad :(" << endl;
		else
			cout << "Error :(" << endl;
	system("pause");
	return 0;	
}