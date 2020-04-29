//********************************************************
// Jian Zhong
// Professor MacKay
// CS121-01
// 3/8/2019
// Program Name: Project 1
// Program file: Project1.cpp
// Input Files: proj1data.txt
// Output Files: Zhong_Jian_proj1results.txt
// Included files: proj1data.txt
// Purpose: practice coding skills
//********************************************************

#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//declare
	ifstream inFile;
	ofstream outFile;

	int p1, p2; // get the first piece of data and the second piece of data
	string str; // get the string of the data
	char ch, P1;

	//open file
	inFile.open("proj1data.txt");
	outFile.open("Zhong_Jian_proj1results.txt");

	//get fill character									 GET DATA OF LINE 1
	inFile >> p1;
	inFile.ignore(200, ' ');

	//store the char value of p1
	P1 = static_cast <char>(p1);

	//get field width
	inFile >> p2;
	inFile.ignore(200, ' ');

	//get the L or R
	inFile >> ch;
	inFile.ignore(200, ' ');

	//get the string
	getline(inFile, str);

	//justification and outcome
	if (ch == 'r' || ch == 'R')
	{
		outFile << setw(p2) << setfill(P1);
		outFile << str;
	}
	else if (ch == 'l' || ch == 'L')
	{
		outFile << left << setw(p2) << setfill(P1);
		outFile << str;
	}

	//get fill character									  GET DATA OF LINE 2
	inFile >> p1;
	inFile.ignore(200, ' ');

	//store the char value of p1 
	P1 = static_cast <char>(p1);

	//get field width
	inFile >> p2;
	inFile.ignore(200, ' ');

	//get the L or R
	inFile >> ch;
	inFile.ignore(200, ' ');

	//get the string
	getline(inFile, str);

	//justification and outcome
	if (ch == 'r' || ch == 'R')
	{
		outFile << endl;
		outFile << setw(p2) << setfill(P1);
		outFile << str;
	}
	else if (ch == 'l' || ch == 'L')
	{
		outFile << endl;
		outFile << left << setw(p2) << setfill(P1);
		outFile << str;
	}

	//get fill character									GET DATA OF LINE 3
	inFile >> p1;
	inFile.ignore(200, ' ');

	//store the char value of p1 
	P1 = static_cast <char>(p1);

	//get field width
	inFile >> p2;
	inFile.ignore(200, ' ');

	//get the L or R
	inFile >> ch;
	inFile.ignore(200, ' ');

	//get the string
	getline(inFile, str);

	//justification and outcome
	if (ch == 'r' || ch == 'R')
	{
		outFile << endl;
		outFile << setw(p2) << setfill(P1);
		outFile << str;
	}
	else if (ch == 'l' || ch == 'L')
	{
		outFile << endl;
		outFile << left << setw(p2) << setfill(P1);
		outFile << str;
	}

	//close file
	inFile.close();
	outFile.close();

	return 0;
}