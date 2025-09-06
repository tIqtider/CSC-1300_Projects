/*****************************************************************
 *****************************************************************
	Title: 			functions.cpp
	Authors: 		April Crockett and Taseen Iqtider
	Date Created: 	11/19/2024
	Last Updateed: 	11/22/2024
	Purpose: 		Creature Fight Game
******************************************************************
******************************************************************/

// Program header
#include "program4.h"

/*************************************************************************************
	Function name:      enterCreatures()
	Return type:        int
	Function purpose:   The enterCreatures function allows
						the user to enter new creatures.
*************************************************************************************/
int enterCreatures(int maxCreatures, int &numCreatures, Creatures *beast)
{
	int enterChoice;
	string fileName;
	string line;
	ifstream inputFile;
	ofstream outputFile;

	cout << "\n********************************************************************************\n";
	cout << "\t\t\t---------- ENTER CREATURES! ----------\n\n";

	// Check if the arena is already at maximum capacity
	if (numCreatures >= maxCreatures)
	{
		cout << "Sorry! You are already at the maximum capacity of " << maxCreatures << " creatures.\n\n";
		return numCreatures;
	}

	// Ask if they want to load creatures or enter creatures manually
	cout << "Would you like to (1) Load my creatures from a text file or (2) Enter one creature manually?\n";
	cout << "CHOOSE 1 or 2:  ";
	cin >> enterChoice;

	// Creature Tracker
	int creaturesAdded = 0;

	// If the user enters in Option 1
	if (enterChoice == 1)
	{
		string temp = "";
		cout << "What is the name of the text file with your list of creatures? (ex: filename.txt)\n";
		cout << "FILENAME:  ";
		cin.ignore();
		getline(cin, fileName);

		ifstream inputFile(fileName);
		if (!inputFile.is_open())
		{
			cout << "Error: Could not open " << fileName << ".\n";
			return numCreatures;
		}

		else if (inputFile.is_open())
		{
			// Reading in file with delimiters
			while (getline(inputFile, temp, '#') && numCreatures < maxCreatures)
			{
				beast[numCreatures].name = temp;
				getline(inputFile, temp, '#');
				beast[numCreatures].description = temp;
				getline(inputFile, temp, '#');
				beast[numCreatures].length = stod(temp);
				getline(inputFile, temp, '#');
				beast[numCreatures].height = stod(temp);
				getline(inputFile, temp, '#');
				beast[numCreatures].location = temp;
				getline(inputFile, temp, '#');
				beast[numCreatures].ferocity = (temp == "1");
				getline(inputFile, temp, '#');
				beast[numCreatures].creaStats.hitPoints = stoi(temp);
				getline(inputFile, temp, '#');
				beast[numCreatures].creaStats.healthPoints = stoi(temp);
				getline(inputFile, temp, '#');
				beast[numCreatures].creaStats.special[0] = temp[0];
				beast[numCreatures].creaStats.special[1] = temp[1];
				beast[numCreatures].creaStats.special[2] = '\0';

				creaturesAdded++;
				numCreatures++; // Increment after adding one creature
			}
		}
		inputFile.close();
		cout << endl << creaturesAdded << " creature(s) from " << fileName << " have been added to the program!\n\n";
	}

	// If user enters in Option 2
	else if (enterChoice == 2)
	{
		char dangerous;
		char creatureChoice = 'y';
		char hitModifier;
		do
		{
			if (numCreatures >= maxCreatures)
			{
				cout << "Want to add more creatures? (y or n):  ";
				cin >> creatureChoice;
				creatureChoice = tolower(creatureChoice);
				if (tolower(creatureChoice) == 'y')
				{
					cout << "Sorry! You already are at the maximum capacity of " << maxCreatures << " creatures.\n";
					return numCreatures;
				}
			}
			// Read in creature info
			cout << "\nNAME:  ";
			cin.ignore();
			getline(cin, beast[numCreatures].name);
			cout << "DESCRIPTION:  ";
			getline(cin, beast[numCreatures].description);
			cout << "AVERAGE LENGTH (in feet):  ";
			cin >> beast[numCreatures].length;
			cout << "AVERAGE HEIGTH (in feet):  ";
			cin >> beast[numCreatures].height;
			cout << "LOCATION:  ";
			cin.ignore();
			getline(cin, beast[numCreatures].location);
			cout << "IS IT A DANGEROUS CREATURE? (y or n):  ";
			cin >> dangerous;
			beast[numCreatures].ferocity = (tolower(dangerous) == 'y');

			cout << "HIT POINTS:  ";
			cin >> beast[numCreatures].creaStats.hitPoints;
			cout << "HEALTH POINTS:  ";
			cin >> beast[numCreatures].creaStats.healthPoints;

			cout << "HIT SPECIAL MODIFIER? (y/n):  ";
			cin >> hitModifier;
			if (tolower(hitModifier) == 'y')
			{
				beast[numCreatures].creaStats.special[0] = '1';
				cout << "HIT MODIFIER (0 through 9):  ";
				cin >> beast[numCreatures].creaStats.special[1];
			}
			else if (tolower(hitModifier) != 'y')
			{
				beast[numCreatures].creaStats.special[0] = '0';
				beast[numCreatures].creaStats.special[1] = '0';
			}
			cout << "\nThe " << beast[numCreatures].name << " has been added!\n\n";
			numCreatures++;

			// Ask if user wants to add more creatures
			if (numCreatures < maxCreatures)
			{
				cout << "Want to add more creatures? (y or n):  ";
				cin >> creatureChoice;
				creatureChoice = tolower(creatureChoice);
			}
		} while (tolower(creatureChoice) == 'y');

		// Break out of this fucntion when creature list is full
		if (numCreatures == maxCreatures)
		{
			cout << "Sorry! You already are at the maximum capacity of " << maxCreatures << " creatures.\n";
		}
	}
	return numCreatures;
}

/*************************************************************************************
	Function name:     fight()
	Return type:       int
	Function purpose:  The fight function will allow two creatures to fight.
					   The user gets to select the two creatures.
*************************************************************************************/
int fight(int numCreatures, Creatures *beast)
{
	int random, first, second, numRounds;
	int hitter, victim, hitterHP, victimHP;

	int f1Hit, f2Hit;

	cout << "\n********************************************************************************\n";
	cout << "\t\t  ---------- FIGHT! FIGHT! FIGHT! ----------\n\n";

	// If there are no creatures, tell the user and then exit this function
	if (numCreatures == 0)
	{
		cout << "Oh no! There are no creatures in the arena!\n\n";
		return numCreatures;
	}

	// Print the creatures
	cout << "Here is the list of creatures who are eligible to fight:\n";
	for (int i = 0; i < numCreatures; i++)
	{
		cout << i + 1 << ") " << beast[i].name << ", HIT: ";
		cout << beast[i].creaStats.hitPoints << ", HEALTH: ";
		cout << beast[i].creaStats.healthPoints << endl;
	}

	// Get the first creature fighter
	cout << "\nFIRST FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
	cin >> first;
	// Validate the user's input
	while (!cin || first < 1 || first > numCreatures)
	{

		if (!cin)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Oops! That wasn't an integer.\n";
		}
		else
			cout << "Oops! That number wasn't in the correct range.\n";
		cout << "FIRST FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
		cin >> first;
	}

	// Get the second creature figher
	cout << "SECOND FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
	cin >> second;
	// Validate the user's input
	while (!cin || second < 1 || second > numCreatures || second == first)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Oops! That wasn't an integer.\n";
		}
		else if (second < 1 || second > numCreatures)
			cout << "Oops! That number wasn't in the correct range.\n";
		else
			cout << "Oops! " << beast[second - 1].name << " can't fight itself!!\n";

		cout << "SECOND FIGHTER (CHOOSE 1-" << numCreatures << "):  ";
		cin >> second;
	}
	/* Since the numbers in first & second are the element numbers, we
	   need to change them to the index values, so I am decrementing both */
	first--;
	second--;

	// FIGHT UNTIL DEATH
	numRounds = 0;

	srand(time(0));
	// While both fighting creatures are not dead (don't have health points of 0 or less), keep fighting
	while (beast[first].creaStats.healthPoints > 0 && beast[second].creaStats.healthPoints > 0)
	{
		// Random Number to see who hits who first
		random = rand() % (2 - 1 + 1) + 1;

		// calculate hit modifier for both creatures
		calculateModifier(first, beast, f1Hit);
		calculateModifier(second, beast, f2Hit);

		if (random == 1) // First hits second
		{
			hitter = first;
			hitterHP = f1Hit;
			victim = second;
		}
		else // Second hits first
		{
			hitter = second;
			hitterHP = f2Hit;
			victim = first;
		}

		numRounds++;
		cout << "\n>>>>>>>>>> ROUND " << numRounds << " <<<<<<<<<<\n";
		cout << beast[hitter].name << " hits " << beast[victim].name << " with " << hitterHP << " hit points!\n";

		// Update creature's health points
		beast[victim].creaStats.healthPoints -= hitterHP;
		cout << beast[victim].name << " now has " << beast[victim].creaStats.healthPoints << " health points.\n";

		// Is the creature's health points at or below 0? if so, it is dead,
		//  so remove it from array, decrement the number of creatures, and
		//  break from the loop
		if (beast[victim].creaStats.healthPoints <= 0)
		{
			cout << beast[victim].name << "'s body is being removed from the arena.\n";
			cout << beast[hitter].name << " IS THE WINNER!!!\n\n";
			moveArrayElements(beast[victim].name, numCreatures, beast);
			numCreatures--;
			break;
		}
	} // End of fight loop

	// Return the updated number of creatures because one creature died
	return numCreatures;
}

/*******************************************************************************************
	Function name:      calculateModifier()
	Return type:     	void
	Function purpose:   The calculateModifier function will accept the index value
						of the creature that will have its hit points modified
						by the special bonus modifier. This function also accepts
						the creature array and an integer that is passed by reference
						that will hold the updated hit points for this creature
*******************************************************************************************/
void calculateModifier(int i, Creatures *beast, int &fHit)
{
	int randomNum = rand() % (11 - 7 + 1) + 7;
	if (strncmp(beast[i].creaStats.special, "1", 1) == 0) // hit modification
		fHit = (beast[i].creaStats.special[1] - '0') * randomNum + beast[i].creaStats.hitPoints;
	else // no special modifications
		fHit = beast[i].creaStats.hitPoints;
}

/***************************************************************************************
	Function name:     deleteCreature()
	Return type:       void
	Function purpose:  The deleteCreature function will allow user to remove a creature.
****************************************************************************************/
int deleteCreature(int &numCreatures, Creatures *beast)
{
	string creatureName;
	bool result;

	cout << "\n********************************************************************************\n";
	cout << "\t\t  ---------- DELETE CREATURE ----------\n\n";

	// If there are no creatures, tell the user and then exit this function
	if (numCreatures == 0)
	{
		cout << "Oh no! There are no creatures in the arena!\n\n";
		return numCreatures;
	}

	cout << "The following is a list of all the creatures:\n";
	for (int i = 0; i < numCreatures; i++)
	{
		cout << beast[i].name << endl; // Print all creatures
	}
	cout << "\n\nWhat creature do you wish to remove?\n"; // Ask user which one they want to remove
	cout << "CREATURE NAME: ";
	cin.ignore();
	getline(cin, creatureName);

	// Call moveArrayElement() function
	result = moveArrayElements(creatureName, numCreatures, beast);

	if (result == true)
	{
		cout << "\nYou have removed " << creatureName << ".\n\n";
		numCreatures--; // Decrement loser creature
	}
	else if (result != true)
	{
		// Print error if the name doesn't match
		cout << "\nSorry, a creature by the name " << creatureName << " could not be found.\n\n";
	}
	return numCreatures;
}

/*************************************************************************************
	Function name:     moveArrayElements()
	Return type:       bool
	Function purpose:  The moveArrayElement function shifts array contents
					   after a creature is being removed.
*************************************************************************************/
bool moveArrayElements(string creatureName, int &numCreatures, Creatures *beast)
{
	int indexToRemove = -1;

	for (int i = 0; i < numCreatures; i++)
	{
		if (beast[i].name == creatureName)
		{
			indexToRemove = i; // Creature found
		}
	}
	if (indexToRemove == -1)
	{
		return false; // Creature not found
	}

	for (int i = indexToRemove; i < numCreatures - 1; i++)
	{
		beast[i] = beast[i + 1]; // Move array elements
	}

	return true;
}

/*************************************************************************************
	Function name:     printCreatures()
	Return type:	   void
	Function purpose:  The printCreatures function shifts array contents
					   after a creature is being removed.
*************************************************************************************/
void printCreatures(int numCreatures, Creatures *beast)
{
	cout << "\n********************************************************************************\n";
	cout << "\t\t  ---------- PRINT CREATURES ----------\n\n";

	// If there are no creatures, tell the user and then exit this function
	if (numCreatures == 0)
	{
		cout << "Oh no! There are no creatures in the arena!\n\n";
	}

	// Print creature details
	else
	{
		cout << "Here is a detailed list of all the creatures who are eligible to fight:\n\n";
		for (int i = 0; i < numCreatures; i++)
		{

			cout << "\t\t\t\t ---------- CREATURE " << (i + 1) << " ----------\n\n";
			cout << "Name:\t\t\t" << beast[i].name << endl;
			cout << "Description:\n\t" << beast[i].description << endl << endl;
			cout << "Length:\t\t\t" << beast[i].length << " feet" << endl;
			cout << "Height:\t\t\t" << beast[i].height << " feet" << endl;
			cout << "Location:\t\t" << beast[i].location << endl;
			cout << "Dangerous?\t\t";
			if (beast[i].ferocity == true)
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
			cout << "Hit Points:\t\t" << beast[i].creaStats.hitPoints << endl;
			cout << "Health Points:\t\t" << beast[i].creaStats.healthPoints << endl;
			if (beast[i].creaStats.special[0] == '1')
			{
				cout << "Special Bonus:\t\tHit modifier of " << beast[i].creaStats.special[1] << endl << endl;
			}
			else
			{
				cout << "Special Bonus:\t\tNo hit modifier\n\n";
			}
		}
	}
}

/*******************************************************************************************
	Function name:     printStats()
	Return type:       void
	Function purpose:  The printStats function prints out each creature's
					   name, hit points, health points, special bonus in an organized way.
*******************************************************************************************/
void printStats(int numCreatures, Creatures *beast)
{
	cout << "\n********************************************************************************\n";
	cout << "\t\t  ---------- PRINT CREATURE STATISTICS ----------\n\n";

	// If there are no creatures, tell the user and then exit this function
	if (numCreatures == 0)
	{
		cout << "Oh no! There are no creatures in the arena!\n\n";
		return;
	}

	// Print header row with column labels with setw()
	cout << "Here are the current stats of each creature:\n\n";
	cout << setw(20) << left << "CREATURE" << setw(11) << right << "HIT PTS" << setw(15) << right << "HEALTH PTS" << setw(18) << right << "SPECIAL BONUS" << endl;
	cout << "--------------------------------------------------------------------------------" << endl;

	// Print creature statistics
	for (int i = 0; i < numCreatures; i++)
	{
		cout << setw(20) << left << beast[i].name;
		cout << setw(10) << right << beast[i].creaStats.hitPoints;
		cout << setw(12) << right << beast[i].creaStats.healthPoints;
		if (beast[i].creaStats.special[0] == '1')
		{
			cout << setw(24) << right << "Hit modifier of  " << beast[i].creaStats.special[1] << endl;
		}
		else
		{
			cout << setw(24) << right << "No hit modifier\n";
		}
	}
	cout << endl;
}

/*******************************************************************************************
	Function name:     saveCreaturesToFile()
	Return type:       void
	Function purpose:  The saveCreaturesToFile function saves each creature's info.
*******************************************************************************************/
void saveCreaturesToFile(int numCreatures, Creatures *beast)
{
	ofstream outputFile;
	ifstream inputFile;
	string creatureFile;

	cout << "\n********************************************************************************\n";
	cout << "\t\t  ---------- SAVE CREATURES TO FILE ----------\n\n";

	// If there are no creatures, tell the user and then exit this function
	if (numCreatures == 0)
	{
		cout << "Oh no! There are no creatures in the arena!\n\n";
		return;
	}

	// Ask for textfile name
	cout << "What is the name of the file you want to save your creatures to?";
	cout << "\nFILENAME:  ";
	cin.ignore();
	getline(cin, creatureFile);
	cout << endl;

	// Print all the creatures in .txt file
	outputFile.open(creatureFile);

	for (int i = 0; i < numCreatures; i++)
	{
		outputFile << beast[i].name << "#";
		outputFile << beast[i].description << "#";
		outputFile << beast[i].length << "#";
		outputFile << beast[i].height << "#";
		outputFile << beast[i].location << "#";
		if (beast[i].ferocity)
		{
			outputFile << "1#";
		}
		else
		{
			outputFile << "0#";
		}
		outputFile << beast[i].creaStats.hitPoints << "#";
		outputFile << beast[i].creaStats.healthPoints << "#";
		outputFile << beast[i].creaStats.special[0] << beast[i].creaStats.special[0] << "#";
	}
	outputFile.close();

	// Print confirmation on the screen
	for (int i = 0; i < numCreatures; i++)
	{
		cout << beast[i].name << " was saved to file.\n";
	}
	cout << numCreatures << " creature(s) were successfully saved to the " << creatureFile << " file.\n";
}