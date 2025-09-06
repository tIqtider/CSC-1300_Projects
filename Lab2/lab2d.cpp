/*
	Title:  	lab2d.cpp
	Author:		Robby Molloy & Taseen Iqtider
	Date:		9/18/2024
	Purpose:	This program is written to determine the dog's prison sentence for stealing other dog's bones.

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	// Defining variables

	int bones;
	const int PRISON_LENGTH = 83;
	const int YEAR_AMT = 365;
	double years, days;

	// Ask dog to input amount of bones stolen

	cout << "\nHow many bones have you stolen? ";
	cin >> bones;
	days = bones * PRISON_LENGTH;
	years = days / YEAR_AMT;

	// ending statement that prints amount of days, and years

	cout << "\nYou must go to prison for " << days << " days, which is " << fixed << setprecision(5) << years << " years.";

	return 0;
}