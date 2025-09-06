/*****************************************************************************************
	Title:  	lab3c.cpp
	Author:		Taseen Iqtider
	Date:		09/19/2024
	Purpose:	Rewriting the code with switch statements instead of if-else if statements
*****************************************************************************************/



#include <iostream>
using namespace std;

int main()
{
	//variable definitions
	char grade;

	cout << "\n\nWhat grade will you earn on this lab assignment?" << endl;
	cout << "GRADE: ";
	cin >> grade;

	/*
		Replaced all 'if-else if' statements with 'switch' statement.  
	*/
	switch (grade)
    {	
	case 'A': 
		cout << "An A - you rock!!\n";
		break;
	case 'B': 
		cout << "You got a B - good job.\n" ;
		break;
	case 'C': 
		cout << "Earning a C is satisfactory.\n";
		break;
	case 'D': 
		cout << "While D is passing, there is a problem.\n";
		cout << "You really didnt learn much.\n";
		break;
	case 'F': 
		cout << "Oh BARF!  You failed - better luck next time.\n";
		break;
	default:  
		cout << "You did not enter an A, B, C, D, or F.\n";
	}
    return 0;
}