// Project Euler Problem 13.cpp
// Aria Bennett

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>
#include <stdio.h>
using namespace std;

void pause()
{
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
}

int convertCharToInt(char c)
{
	if(c=='0'){return 0;}if(c=='1'){return 1;}if(c=='2'){return 2;}
	if(c=='3'){return 3;}if(c=='4'){return 4;}if(c=='5'){return 5;}
	if(c=='6'){return 6;}if(c=='7'){return 7;}if(c=='8'){return 8;}
	if(c=='9'){return 9;}
}

void addStringArraysByColumns(string s[150])
{
	//columnHolder initialization
	int columnHolder[50];
	for (int i = 0; i < 50; i++)
	{
		columnHolder[i] = 0;
	}
	//fills columnHolder with passed string array
	for (int j = 0; j < 50; j++)
	{
		for (int k = 0; k < 100; k++)
		{
			columnHolder[j] += convertCharToInt(s[k][j]);
		}
	}


	//long long finalNumber = 0;
	//long double valueConvert = 0;
	string finalNumber = "";
	long double valueConvert = 0;
	for (int i = 0; i < 50; i++)
	{
		valueConvert += ( columnHolder[49-i] ) * pow(10.0, i);
		cout << "columnHolder[" << 49-i << "]: " << columnHolder[49-i] << "\tvalueConvert: " << setprecision(17) << valueConvert << endl;
	}
}

int main()
{
	//data initialization code
	fstream numberFile("numbers.txt");
	string line;
	string numberStringArray[150];
	int counter = 0;

	//
	while ( numberFile.good() )
	{
		getline(numberFile, numberStringArray[counter]);
		++counter;
	}

	//function calls
	addStringArraysByColumns(numberStringArray);
	pause();
	return 0;
}