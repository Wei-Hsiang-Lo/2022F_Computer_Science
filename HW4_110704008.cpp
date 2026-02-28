//File Name: HW4_110704008.cpp
//Author:羅瑋翔
//Email Address: xianglo9121.mg10@nycu.edu,tw
//HW Number: 4
//Description:Use to calculate a file's clothes imformation of many people
//Last Changed: 10, 28, 2022 
//Anything special? if the file can not open it will manifest on the screen and I change weight's and height's type
//from integer to double rather than set their type as integer at the beginning
#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>

const double INCH = 2.54;
const double POUND = 0.454;

double hatSize(int weight, int height);
//calculate the hat size with parameter weight and height

double jacketSize(int weight, int heightm, int age);
//calculate the jacket size with parameter weight, height and age

double waistSize(int wight, int age);
//calculate the waist size with parameter weight and age

int main()
{
	ifstream inFile;
	ofstream outFile;
	int height, weight, age;
	
	inFile.open("personalData.txt");
	if(inFile.fail())
	{
		cout << "Input file opening fail." << endl;
		exit(1);
	}
	outFile.open("clothesData.txt");
	
	while(inFile >> height >> weight >> age)
	{
		outFile << hatSize(weight, height) << "\t"
				<< jacketSize(weight, height, age) << "\t"
				<< waistSize(weight, age) << endl;
	}
	
	inFile.close();
	outFile.close();
	
	system("PAUSE");
	return 0;
}

double hatSize(int weight, int height)
{
	double heightInInch, weightInPounds, hat;

	heightInInch = static_cast<double>(height) / INCH;
	weightInPounds = static_cast<double>(weight) / POUND;
	hat = weightInPounds / heightInInch * 2.9;
	
	return hat;
}

double jacketSize(int weight, int height, int age)
{
	double heightInInch, weightInPounds, jacket;
	int age10y;
	
	heightInInch = static_cast<double>(height) / INCH;
	weightInPounds = static_cast<double>(weight) / POUND;
		
	if(age > 30)
	{
		age10y = (age - 30) / 10 ;
		jacket = heightInInch * weightInPounds / 288 + static_cast<double>(age10y) / 8;
		return jacket;
	}
	else
	{
		jacket = heightInInch * weightInPounds / 288;
		return jacket;
	}
}

double waistSize(int weight, int age)
{
	double heightInInch, weightInPounds, waist;
	int age2y;
	
	weightInPounds = static_cast<double>(weight) / POUND;
	
	if(age > 28)
	{
		age2y = (age - 28) / 2 ;
		waist = weightInPounds / 5.7 + static_cast<double>(age2y) / 10;
		return waist;
	}
	else
	{
		waist = weightInPounds / 5.7;
		return waist;
	}
}
	