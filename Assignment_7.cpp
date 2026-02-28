//File Name: HW7_110704008.cpp
//Author:羅瑋翔
//Email Address: xianglo9121.mg10@nycu.edu,tw
//HW Number: 7
//Description:this program allows users to input two polynomials to get their sum
//Last Changed: 12. 15. 2022
//Anything special? I use a function to make nodes
#include <iostream>
using namespace std;
#include <cmath>

const int N = 100;

struct Node
{
	int coef;
	int expt;
	Node *link;
};

typedef Node* NodePtr;

NodePtr make_node(int coef_p, int expt_p);
//this function is used for generating node

int main()
{
	NodePtr head_1, temp_1, rear_1, head_2, temp_2, rear_2;
	char poly1[N], poly2[N], c, sign, garbage;
	int coef = 0, expt, count, ind, times, num;
	
	head_1 = new Node;
	head_2 = new Node;
	head_1->link = NULL;
	head_2->link = NULL;
	rear_1 = head_1;
	rear_2 = head_2;
	
	cout << "This program is to perform polynomial addtion.\n";
	cout << "Please enter poly1 and poly2(e.g:1x^2 + 1x^1 + 1x^0#), # means the end of the input : .\n";
	//cin poly1 and poly2
	num = 0;
	do
	{
		cin.get(c);
		poly1[num] = c;
		num++;
	}while(c != '#');
	num = 0;
	cin.get(garbage);
	do
	{
		cin.get(c);
		poly2[num] = c;
		num++;
	}while(c != '#');
	
	//find the leading coef of poly1;
	coef = 0;
	for(int i = 0; i < N; i++)
	{
		if(poly1[i] == 'x' || poly1[i] == 'X')
		{
			ind = i;
			break;
		}
	}
	//find the coef and the expt of the first x
	if(poly1[0] == '-')
	{
		for(int i = 1; (ind - i) >= 1; i++)
		{
			times = pow(10, i - 1);
			count = (poly1[ind - i] - '0') * times;
			coef = coef + count;
		}
		expt = poly1[ind + 2] - '0';
		coef = coef * (-1);
		temp_1 = make_node(coef, expt);//call the funtion to make node
		temp_1->link = rear_1->link;
		rear_1->link = temp_1;
		rear_1 = temp_1;
	}
	else
	{
		for(int i = 1; (ind - i) >= 0; i++)
		{
			times = pow(10, i - 1);
			count = (poly1[ind - i] - '0') * times;
			coef = coef + count;
		}
		expt = poly1[ind + 2] - '0';
		temp_1 = make_node(coef, expt);//call the funtion to make node
		temp_1->link = rear_1->link;
		rear_1->link = temp_1;
		rear_1 = temp_1;
	}
	
	while(poly1[ind + 3] != '#')
	{
		int i = ind + 6;	
		sign = poly1[ind + 4];
		coef = 0;
		//start from the next coef to find the next x
		for(int j = ind + 6; j < N; j++)
		{
			if(poly1[j] == 'x' || poly1[j] == 'X')
			{
				ind = j;
				break;
			}
		}
		//find the coef and expt of x
		for(int k = 1; (ind - k) >= i; k++)
		{
			times = pow(10, k - 1);
			count = (poly1[ind - k] - '0') * times;
			coef = coef + count;
		}
		//make nodes and append nodes
		if(sign == '-')
			coef = coef * (-1);
		expt = poly1[ind + 2] - '0';
		temp_1 = make_node(coef, expt);
		temp_1->link = rear_1->link;
		rear_1->link = temp_1;
		rear_1 = temp_1;
	}
	
	//find the leading coef of poly2;
	coef = 0;
	for(int i = 0; i < N; i++)
	{
		if(poly2[i] == 'x' || poly2[i] == 'X')
		{
			ind =i;
			break;
		}
	}
	//find the coef and the expt of the first x
	if(poly2[0] == '-')
	{
		for(int i = 1; (ind - i) >= 1; i++)
		{
			times = pow(10, i - 1);
			count = (poly2[ind - i] -'0') * times;
			coef = coef + count;
		}
			coef = coef * (-1);
			expt = poly2[ind + 2] - '0';
			temp_2 = make_node(coef, expt);//call the funtion to make node
			temp_2->link = rear_2->link;
			rear_2->link = temp_2;
			rear_2 = temp_2;
	}
	else
	{
		for(int i = 1; (ind - i) >= 0; i++)
		{
			times = pow(10, i - 1);
			count = (poly2[ind - i] - '0') * times;
			coef = coef + count;
		}
		expt = poly2[ind + 2] - '0';
		temp_2 = make_node(coef, expt);//call the funtion to make node
		temp_2->link = rear_2->link;
		rear_2->link = temp_2;
		rear_2 = temp_2;
	}

	while(poly2[ind + 3] != '#')
	{
		int i = ind + 6;
		sign = poly2[ind +4];
		coef = 0;
		//start from the next coef to find the next x
		for(int j = ind + 6; j < N; j++)
		{
			if(poly2[j] == 'x' || poly2[j] == 'X')
			{
				ind = j;
				break;
			}
		}
		//find the coef and expt of x
		for(int k = 1; (ind - k) >= i; k++)
		{
			times = pow(10, k - 1);
			count = (poly2[ind - k] - '0') * times;
			coef = coef + count;
		}
		//make nodes and append nodes
		if(sign == '-')
			coef = coef * (-1);
		expt = poly2[ind + 2] - '0';
		temp_2 = make_node(coef, expt);
		temp_2->link = rear_2->link;
		rear_2->link = temp_2;
		rear_2 = temp_2;
	}

	cout << "Poly1->";
	for(NodePtr iter = head_1->link; iter != NULL; iter = iter->link)
	{
		cout << iter->coef << " " << iter->expt << "->";
	}
	cout << "NULL" << endl;
	
	cout << "Poly2->";
	for(NodePtr iter = head_2->link; iter != NULL; iter = iter->link)
	{
		cout << iter->coef << " " << iter->expt << "->";
	}
	cout << "NULL" << endl;
		
	NodePtr head_3, temp_3, rear_3;
	head_3 = new Node;
	head_3->link = NULL;
	rear_3 = head_3;
	//add the two poly
	for(NodePtr iter_1 = head_1->link; iter_1 != NULL; iter_1 = iter_1->link)
	{
		for(NodePtr iter_2 = head_2->link; iter_2 != NULL; iter_2 = iter_2->link)
		{
			if(iter_1->expt == iter_2->expt)
			{
				temp_3 = new Node;
				temp_3->expt = iter_1->expt;
				temp_3->coef = (iter_1->coef + iter_2->coef);
				temp_3->link = NULL;
				rear_3->link = temp_3;
				rear_3 = temp_3;
				break;
			}
			else if(iter_2->expt > iter_1->expt)
			{
				temp_3 = new Node;
				temp_3->expt = iter_2->expt;
				temp_3->coef = iter_2->coef;
				temp_3->link = NULL;
				rear_3->link = temp_3;
				rear_3 = temp_3;
			}
			else
			{
				temp_3 = new Node;
				temp_3->expt = iter_1->expt;
				temp_3->coef = iter_1->coef;
				temp_3->link = NULL;
				rear_3->link = temp_3;
				rear_3 = temp_3;		
				break;
			}
		}
	}
	cout << "Poly3->";
	for(NodePtr iter = head_3->link; iter != NULL; iter = iter->link)
	{
		cout << iter->coef << " " << iter->expt << "->";
	}
	cout << "NULL" << endl;
	
	
	system("PAUSE");
	return 0;
}

NodePtr make_node(int coef_p, int expt_p)
{
	NodePtr temp;
	temp = new Node;
	
	temp->coef = coef_p;
	temp->expt = expt_p;
	
	return temp;
}