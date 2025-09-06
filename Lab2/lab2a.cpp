/*
	Title:  	lab2a.cpp
	Author:		Robby Molloy & Taseen Iqtider
	Date:		9/18/2024
	Purpose:	This program is written for waiters & waitresses at
				TGI Fridays so that they can calculate total cost
				of hot wings for their customers.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// define your variables here

	int wings;
	double finalBill;
	const double TAX_RATE = 1.085;
	const double WING_PRICE = 0.99;

	/* 	the line below will allow floating point amounts to display
		two numbers after the decimal point.  (it will make amounts pretty)
	*/

	cout << "\n\nPlease input the number of hot wings purchased:  ";

	//	Fill in the	input statement to bring in	the	quantity of hot wings.

	cin >> wings;

	//	Fill in the assignment statement to determine the total bill.

	finalBill = (wings * WING_PRICE) * TAX_RATE;
	cout << fixed << setprecision(2) << showpoint << finalBill << endl;

	//	Fill in	the	output statement to print total bill as shown in sample output

	cout << "\n\nYour total bill is " << finalBill << endl;
	return 0;
}
