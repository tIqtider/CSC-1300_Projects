/**************************************************************************************************
	Title:  	lab4a.cpp
	Author:		Taseen Iqtider
	Date:		10/02/2024
	Purpose:	Making a password generator that customizes a password and makes unique passwords
***************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <ctime>
using namespace std;

int main()
{
	// Variable definition
	int randomIndex, capitalLetter, randNum;
	string password;

	cout << "***The Password Program***\n\n";
	cout << "Please enter a word with no spaces: ";
	getline(cin, password);

	// Verify if the password has less than 1 character and see if there's any space between the password
	while (password.length() < 1 || password.find(' ') != string::npos)
	{
		cout << "Please enter a word with no spaces: ";
		getline(cin, password);
	}

	// Seed a random index in the password
	srand(time(0));
	randomIndex = rand() % (password.length());

	// Change a random index to a capital letter if that index is a letter
	while (!(isalpha(password.at(randomIndex))))
	{
		randomIndex = rand() % (password.length());
	}

	// Convert a number to a capital letter following the ASCII rules
	capitalLetter = (rand() % 26) + 65;
	password.at(randomIndex) = static_cast<char>(capitalLetter); // Convert an integer to a character

	if (password.find('a') != string::npos)
	{
		password.replace(password.find('a'), 1, "-alpha-"); // Change 1st 'a' to be '-alpha-'
	}
	if (password.find('g') != string::npos)
	{
		password.replace(password.find('g'), 1, "-gamma-"); // Change 1st 'g' to be '-gamma-'
	}
	if (password.find('d') != string::npos)
	{
		password.replace(password.find('d'), 1, "-delta-"); // Change 1st 'd' to be '-delta-'
	}

	// Generate a random 3-digit number
	randNum = rand() % (999 - 100 + 1) + 100;
	password.append(to_string(randNum)); // Append that random number to the end of the password
	cout << "Updated Password: " << password << endl;

	return 0;
}
