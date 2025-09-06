/*************************************************************************************************
	Title:  	lab4c.cpp
	Author:		Taseen Iqtider
	Date:		10/02/2024
	Purpose:	Creating a Number Guessing Game
**************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// Variable definition
	char choice;
	int randomNumber;
	int guess;

	srand(time(0)); // Seed random number generator

	cout << "Would you like to play a game? "; // Ask the user if they want to play
	cin >> choice;
	while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
	{
		cout << "\nNot a valid input\n";
		cout << "Enter a 'y' or 'n': "; // Prompt the user to dial in the right input
		cin >> choice;
	}

	// Onto thee main loop if the user wants to play
	while (choice != 'n' && choice != 'N')
	{

		randomNumber = rand() % (50 - 1 + 1) + 1; // Generating a random number between 1-50
		cout << "\nGuess a random number between 1-50: ";
		cin >> guess;

		while (guess < 1 || guess > 50)
		{
			cout << "That's not in the guessing range. Try again: "; // Print an error message if the guess is out of range
			cin >> guess;
		}
		if (guess == randomNumber)
		{
			cout << "\nGOOD JOB!\n"; // Congratulate if the guess matched with the random number
		}
		else if (guess != randomNumber)
		{
			cout << "\nThe number was " << randomNumber << ".\n"; // Print a sad message if it doesn't match
			cout << "You can always try again :)\n";
		}
		cout << "Play again? (enter 'y' or 'n'): "; // Ask if they want to play again
		cin >> choice;
		cout << endl;

		while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			cout << "Not a valid input" << endl;
			cout << "Enter a 'y' or 'n': "; // Prompt the user to dial in the right input
			cin >> choice;
		}
	}
	cout << "\nBYE BYE\n"; // Print goodbye message if the user doesn't want to play
	return 0;
}
