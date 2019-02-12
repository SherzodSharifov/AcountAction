// Assign01AcountActions.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <string>

using namespace std;

char getActionCode();
void displayBalance();
void recordAction(char);
double getActionAmount(char);
void writeAction(char, double);//done this part in recordAction() no need to write separate function for this
void listActions();
string getActionLabel(char);


int main()
{
	char actionCode;
	cout << fixed << setprecision(2);
	actionCode = toupper (getActionCode());

	while (actionCode != 'Q')
	{
		switch (actionCode)
		{
		case 'B':
			displayBalance();
			break;
		case 'C':
			recordAction('C');
			break;
		case 'D':
			recordAction('D');
			break;
		case 'W':
			recordAction('W');
			break;
		case 'L':
			listActions();
			break;
		default:
			cout << "wrong choice";
			break;
		}
		actionCode = toupper(getActionCode());
	}
	cout << endl;
	system("pause");
	return 0;
}

char getActionCode()
{
	char code;
	cout << "\nEnter:" << endl;
	cout << setw(10) << "B" << setw(3) << " Show Balance ..." << endl;
	cout << setw(10) << "C" << setw(3) << " Record Check ..." << endl;
	cout << setw(10) << "D" << setw(3) << " Make Deposit ..." << endl;
	cout << setw(10) << "W" << setw(3) << " Withdrawal ..." << endl;
	cout << setw(10) << "L" << setw(3) << " List Actions ..." << endl;
	cout << setw(10) << "Q" << setw(3) << " Quit Program:" << endl; 
	cin >> code;
	return code;

}

void listActions()
{
	fstream file;
	file.open("data.txt", ios::in);//to open file

	if (!file)
	{
		cout << "no file found";
		return;
	}

	string line;
	while (getline(file, line))
	{
		istringstream ss(line);//to read every line
		char action;
		float n;

		ss >> action >> n;//getting action and amount from file

		switch (action)
		{
		case 'C':
			cout << "\nCheck + " << n;
			break;

		case 'D':

			cout << "\nDeposit + " << n;

			break;

		case 'W':

			cout << "\nWithdrawal - " << n;

			break;

		}

	}

	file.close();

	displayBalance();

}

void displayBalance()

{
	ifstream inputFile("AccountActions.txt");

	string line;

	char action;

	float amount = 0, n;

	while (getline(inputFile, line))
	{
		istringstream ss(line);

		ss >> action >> n;

		switch (action)
		{
		case 'C':
			amount += n;
			break;
		case 'D':
			amount += n;
			break;
		case 'W':
			amount -= n;
			break;
		}
	}
	inputFile.close();
	cout << "\nBalance of account $" << amount;
}

void recordAction(char action)
{
	fstream file;
	file.open("data.txt", ios::app);
	if (!file)
	{
		cout << "\nError no file found";
		return;
	}
	file << action << " " << getActionAmount(action) << endl;
	file.close();
}

double getActionAmount(char action)
{
	double amount;
	switch (action)
	{
	case 'C':
		cout << "\nAmount of check $";
		cin >> amount;
		break;
	case 'D':
		cout << "\nAmount of deposit $";
		cin >> amount;
		break;
	case 'W':
		cout << "\nAmount of withdrawal $";
		cin >> amount;
		break;
	default:cout << "wrong action";
		break;
	}
	return amount;
}
