/*************************************************************************************************
	Title:  	lab4b.cpp
	Author:		Taseen Iqtider
	Date:		10/02/2024
	Purpose:	Creating a menu based testing policy
**************************************************************************************************/



#include<iostream>
#include<iomanip>
#include<cctype>
#include<string>
using namespace std;

int main()
{
	// Variable definition
	int option;
	int totalLabs, totalOfficeHours;
	char playGames;

	// Assign lab & office hours to zero
	cout << "***Testing Soon***\n\n";
	totalLabs = 0;
	totalOfficeHours = 0;

	// Main loop that prints out the menu as many times as the user wants
	do {
		// Display the menu
		cout << "\n1. Go to Lab" << endl;
		cout << "2. Go to Office Hours" << endl;
		cout << "3. Take the test" << endl;

		// Let the user choose from the menu and print out texts according to their choice
		cout << "Please choose an option 1-3: ";
		cin >> option; 

		do {
			if ((option < 1) || (option > 3)) {
			cout << "That's not an option, you silly goose. Enter 1-3: "; // Print invalid option and prompt the user to dial the right input
			cin >> option;
			} 
		} while ((option < 1) || (option > 3)); 

		if (option == 1) { 
			cout << "Did you play minesweeper all of lab? (Y or N) "; // Ask the user if they utilized their time in the lab
			cin >> playGames;

			if (playGames == 'Y' || playGames == 'y') {
				cout << "Negative aura.. tsk tsk\n"; // Print a sad text if they played video-game instead of studying
			}
			else {
				cout << "You chose to go to lab! Your TAs are proud.\n"; // Print a happy text if they didn't play the video-game and add 1 lab point
				totalLabs ++;
			}
		}
		else if (option == 2) {
			cout << "You chose to go to office hours. Very demure\n"; // Print a positive comment if they went to office hours and add 1 office hour point  
			totalOfficeHours ++;
		}
		else if (option == 3) {
			cout << "Good luck soldier o7\n"; // Wish them good luck if they selected testing option
		}
	} while (option != 3); // Exit the loop when user decides to take the test

	// Results
	cout << endl;
	cout << "Labs: " << totalLabs << endl;
	cout  << "Office hours: " << totalOfficeHours << endl;
	
	// Give feedback based on user's participation in their lab & office hours
	if (totalLabs >= 3 || totalOfficeHours >= 3) {
		cout << "You passed the test without even trying. Good job!\n"; 
	}
	else if (totalLabs >= 1 || totalOfficeHours >= 1) {
		cout << "Your attendance paid off. Wes the Lab Princess looked upon you kindly.\n";
	}
	else {
		cout << "Risky, risky...\n";
	}
	return 0;
}