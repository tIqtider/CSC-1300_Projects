/*************************************************************************
   Title:    lab7_driver.cpp
   Author:   Taseen Iqtider
   Date:  	 October 29, 2024
   Purpose:  Future Predictor Program
*************************************************************************/

// Program header
#include "lab7_header.h"

int main()
{
	// Variable definition
	char mainChoice;
	int fileRandomInt, randomInt;
	string dwelling, person, location, car;
	string jobTitle1, jobTitle2, jobTitle3;
	string place1, place2, place3;
	int numOne, numTwo, numThree;
	double salOne, salTwo, salThree;
	ifstream inFile;

	srand(time(0)); // Seed the random number generator

	// Beginning of the future predictor program
	do
	{
		cout << "\nI will predict your future!\n";
		cout << "First, I need just a little information.\n";

		// Calling getNumChildren() function
		getNumChildren(numOne, numTwo, numThree);

		// job title
		cout << "\nEnter in an awesome job title: ";
		getline(cin, jobTitle1);
		cout << "Enter in another awesome job title: ";
		getline(cin, jobTitle2);
		cout << "Enter in the worst job title ever: ";
		getline(cin, jobTitle3);

		// Place of employment
		cout << "\nEnter a company, organization, or restaurant you like: ";
		getline(cin, place1);
		cout << "Enter another company, organization, or restaurant you like: ";
		getline(cin, place2);
		cout << "Enter a company, organization, or restaurant you hate: ";
		getline(cin, place3);

		// Calling getSalary() function
		getSalary(salOne, salTwo, salThree);

		/** Retrieve info from the text files **/
		fileRandomInt = generateRandomInt(1, 15); // Generate a random number between 1 and 15
		inFile.open("DWELLINGS.txt");			  // Opening "DWELLINGS>txt" file
		for (int i = 1; i <= fileRandomInt; i++)
		{
			getline(inFile, dwelling);
		}
		inFile.close();

		fileRandomInt = generateRandomInt(1, 15); // Generate a random number between 1 and 15
		inFile.open("PEOPLE.txt");				  // Opening "PEOPLE.txt" file
		for (int i = 1; i <= fileRandomInt; i++)
		{
			getline(inFile, person);
		}
		inFile.close();
		fileRandomInt = generateRandomInt(1, 15); // Generate a random number between 1 and 15
		inFile.open("LOCATIONS.txt");			  // Opening "LOCATIONS.txt" file
		for (int i = 1; i <= fileRandomInt; i++)
		{
			getline(inFile, location);
		}
		inFile.close();
		fileRandomInt = generateRandomInt(1, 15); // Generate a random number between 1 and 15
		inFile.open("CARS.txt");				  // Opening "CARS.txt" file
		for (int i = 1; i <= fileRandomInt; i++)
		{
			getline(inFile, car);
		}
		inFile.close();

		// Display user's future
		cout << "******  YOUR FUTURE  ******\n";
		cout << "You and your spouse, " << person;
		cout << " will live in a " << dwelling << " in ";
		cout << location << " and drive a " << car << ".\n";

		// Print number of user's offsprings
		randomInt = generateRandomInt(1, 3); // generate a random number between 1 and 3
		cout << "You and your spouse will have ";
		if (randomInt == 1)
		{
			cout << numOne << " children.\n";
		}
		else if (randomInt == 2)
		{
			cout << numTwo << " children.\n";
		}
		else
		{
			cout << numThree << " children.\n";
		}

		// Print user's job title
		randomInt = generateRandomInt(1, 3); // generate a random number between 1 and 3
		cout << "You will work at ";
		if (randomInt == 1)
		{
			cout << place1 << " as a " << jobTitle1 << " making ";
		}
		else if (randomInt == 2)
		{
			cout << place2 << " as a " << jobTitle2 << " making ";
		}
		else
		{
			cout << place3 << " as a " << jobTitle3 << " making ";
		}

		// Print user's yearly salary
		randomInt = generateRandomInt(1, 3); // generate a random number between 1 and 3
		if (randomInt == 1)
		{
			cout << "$" << salOne << " a year.\n";
		}
		else if (randomInt == 2)
		{
			cout << "$" << salTwo << " a year.\n";
		}
		else
		{
			cout << "$" << salThree << " a year.\n";
		}
		cout << "\nWould you like to play Future Predictor again? (y/n) "; // Ask if they want to play again
		cin >> mainChoice;
		// line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (tolower(mainChoice) == 'y');

	cout << "\n\nGoodbye!\n\n";

	return 0;
}