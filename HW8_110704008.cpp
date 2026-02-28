//File Name: HW8_110704008.cpp
//Author:羅瑋翔
//Email Address: xianglo9121.mg10@nycu.edu,tw
//HW Number: 8
//Description: The purpose of this program is used to solve the problems
//the number, id who affected only Covid-19 or flu and the number, id who affected both Covid-19 and flu
//Last Changed: 12. 30. 2022
//Anything special? 
#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>

const int N1 = 100, N2 = 20;

class DiseaseInfo
{
public:
	DiseaseInfo();
	DiseaseInfo(string, char);
	
	string getId(); 
	char getDiseaseType();
	int getDataNum();
	int getIncorrectDataNum();

	void setId(string);
	void setDiseaseType(char);
	void check(ostream& outs);
	friend istream& operator >> (istream& ins, DiseaseInfo& diseaseInfo_);
	friend ostream& operator << (ostream& outs, DiseaseInfo& diseaseInfo_);
private:
	bool check_disease();
		//if disease is 'c' or 'f', then return true
		//if disease is neither 'c' nor 'f', then issue suitable error message and return false
	bool check_idFormat();
		//if the length of string not equal to 10 or the first char is not capitl
		//then issue suitable error message and retrun false
	bool check_duplicate();
		//if the id and diseaseType are the same in two diseaseInfo, then return false and issue suitable error message
	string id;
	string idData[N1][N2];
	string affectId[N1][N2];
	
	char diseaseTypeData[N1];
	char diseaseType; //'c' for covid-19, 'f' for flu
	int dataCount = 0, incorrectCount = 0, affect = 0;
};

bool check_disease(char c);

bool check_idFormat(string str);

int main()
{
	string inFileName, outFileName;
	ifstream inFile;
	ofstream outFile;
	DiseaseInfo diseaseInfo_;
	string Id[N1][N2];
	char DiseaseType[N1];
	int ind = 0, CandF = 0, count = 0, same = 0;
	
	cout << "This program enables you input a file of disease information\n"
		 << "and it will help you to check which data is correct.\n"
		 << "In the correct data, this program will help you classify the data into\n"
		 << "1. Id of individuals affected by only Covid-19 or only flu.\n" 
		 << "2. Id of individuals affected by both Covid-19 and flu.\n\n";
	cout << "Enter the input file name : ";
	cin >> inFileName;
	inFile.open(inFileName);
	if(inFile.eof())
	{
		cout << "Open file failed.\n";
		system("PAUSE");
		exit(1);
	}
	cout << "Enter the output file name : ";
	cin >> outFileName;
	outFile.open(outFileName);
	while(inFile >> diseaseInfo_)
	{
		Id[count][N2] = diseaseInfo_.getId();
		DiseaseType[count] = diseaseInfo_.getDiseaseType();
		outFile << diseaseInfo_ << endl;
		count++;
	}
	ind = diseaseInfo_.getDataNum();
	string NoDupId[N1][N2];
	char NoDulType[N1];
	int numNoDul = 0;
	
	//form a data without duplicate
	for(int i = 0; i < (ind - 1); i++)
	{
		int mark = 0;
		same = 0;
		if(check_disease(DiseaseType[i]) && check_idFormat(Id[i][N2]))
		{
			for(int j = i + 1; j < ind; j++)
			{
				if(Id[i][N2] == Id[j][N2] && DiseaseType[i] == DiseaseType[j])
					same = 1;
			}
		}
		else
			same = 1;
		if(same == 0)
		{
			NoDupId[numNoDul][N2] = Id[i][N2];
			NoDulType[numNoDul] = DiseaseType[i];
			numNoDul++;
		}
	}
	if(check_disease(DiseaseType[ind-1]) && check_idFormat(Id[ind-1][N2]))
	{
		NoDupId[numNoDul][N2] = Id[ind - 1][N2];
		NoDulType[numNoDul] = DiseaseType[ind - 1];
		numNoDul++;
	}
	
	outFile << "Summary:" << endl;
	outFile << "Total " << ind << " data, " << diseaseInfo_.getIncorrectDataNum() << " of them are incorrect." << endl;
	//count the number of CandF(who affected both covid and flu)
	for(int i = 0; i < numNoDul - 1; i++)
	{
		for(int j = i + 1; j < numNoDul; j++)
		{
			if(NoDupId[i][N2] == NoDupId[j][N2])
			{
				CandF++;
				break;
			}
		}
	}
	
	outFile << "(i) " << numNoDul - 2 * CandF << endl;
	outFile << "(ii) id of individuals affected by only Covid-19 or only flu." << endl; 
	
	for(int i = 0; i < numNoDul; i++)
	{
		same = 0;
		for(int j = 0; j < numNoDul; j++)
		{
			if(i != j)
			{
				if(NoDupId[i][N2] == NoDupId[j][N2])
				{
					same = 1;
					break;
				}
			}
		}
		if(same == 0)
			outFile << NoDupId[i][N2] << " " << NoDulType[i] << endl;
	}
	
	outFile << "(iii) " << CandF << endl;
	outFile << "(iv) id of individuals affected by both Covid-19 and flu." << endl;
	for(int i = 0; i < numNoDul - 1; i++)
	{
		for(int j = i + 1; j < numNoDul; j++)
		{
			if(NoDupId[i][N2] == NoDupId[j][N2])
			{
				outFile << NoDupId[i][N2] << endl;
				break;
			}
		}
	}

	inFile.close();
	outFile.close();
                                                                                      
	system("PAUSE");
	return 0;
}

DiseaseInfo::DiseaseInfo()
{}

DiseaseInfo::DiseaseInfo(string theId, char theSign):id(theId), diseaseType(theSign)
{}

string DiseaseInfo::getId()
{
	return id;
}

char DiseaseInfo::getDiseaseType()
{
	return diseaseType;
}

int DiseaseInfo::getDataNum()
{
	return dataCount;
}

int DiseaseInfo::getIncorrectDataNum()
{
	return incorrectCount;
}

void DiseaseInfo::setId(string newId)
{
	id = newId;
}

void DiseaseInfo::setDiseaseType(char newDiseaseType)
{
	diseaseType = newDiseaseType;
}


void DiseaseInfo::check(ostream& outs)
{
	if(!check_disease() && !check_idFormat())
	{
		outs << "\tIncorrect data : Id format and disease type both incorrect";
		incorrectCount++;
	}
	else if(!check_disease() && check_idFormat())
	{
		outs << "\tIncorrect data : Disease type incorrect";
		incorrectCount++;
	}
	else if(check_disease() && !check_idFormat())
	{
		outs << "\tIncorrect data : Id format incorrect";
		incorrectCount++;
	}
	else if(!check_duplicate())
	{
		outs << "\tIncorrect data : Duplicate";
		incorrectCount++;
	}
}

istream& operator >> (istream& ins, DiseaseInfo& diseaseInfo_)
{
	ins >> diseaseInfo_.id >> diseaseInfo_.diseaseType;
	return ins;
}

ostream& operator << (ostream& outs, DiseaseInfo& diseaseInfo_)
{
	outs << diseaseInfo_.id << " " << diseaseInfo_.diseaseType;
	diseaseInfo_.check(outs);
	diseaseInfo_.dataCount++;
	return outs;
}

bool DiseaseInfo::check_disease()
{
	if(diseaseType == 'c' || diseaseType == 'f')
		return true;
	else
		return false;
}

bool DiseaseInfo::check_idFormat()
{
	int length = id.size();
	if(id[0] >= 'A' && id[0] <= 'Z' && length == 10)
	{
		return true;
	}
	else
		return false;
}

bool DiseaseInfo::check_duplicate()
{
	idData[dataCount][N2] = id;
	diseaseTypeData[dataCount] = diseaseType;
	if(dataCount > 0)
	{
		for(int i = 0; i < dataCount; i++)
		{
			if(idData[i][N2] == id && diseaseType == diseaseTypeData[i])
			{
				return false;
			}
		}
	}
	return true;
}

bool check_disease(char type)
{
	if(type == 'c' || type == 'f')
		return true;
	else
		return false;
}

bool check_idFormat(string str)
{
	int length = str.size();
	if(str[0] >= 'A' && str[0] <= 'Z' && length == 10)
	{
		return true;
	}
	else
		return false;
}