/*
	Title:  	lab2b.cpp
	Author:		Robby Molloy & Taseen Iqtider
	Date:		9/18/2024
	Purpose:	This program is written for customers to determine the final price for goods
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// Defining variables

	double price1, price2, totalBill;
	int amtBought1, amtBought2;
	string firstItem, secondItem;
	const double TAX_RATE = 1.0975;

	//	Ask user to input first item

	cout << "\nPlease input the name of " << "the first item: ";
	getline(cin, firstItem);

	//	Ask user to input firstItem amount

	cout << "\nPlease input the number of " << firstItem << " bought: ";
	cin >> amtBought1;

	//	Ask user to input price of firstItem

	cout << "\nPlease input the price of " << firstItem << ": $";
	cin >> price1;

	cin.ignore();

	// Separate first and second item

	cout << endl;
	cout << endl;

	//	Ask user to input second item

	cout << "\nPlease input the name of " << "the second item: ";
	getline(cin, secondItem);

	cout << "\nPlease input the number of " << secondItem << " bought: ";
	cin >> amtBought2;

	cout << "\nPlease input the price of " << secondItem << ": $";
	cin >> price2;

	cout << endl;

	// Formula for totalBill

	totalBill = ((amtBought1 * price1) + (amtBought2 * price2)) * TAX_RATE;
	cout << "\nThe total bill is $" << fixed << setprecision(2) << totalBill << ".";

	return 0;
}