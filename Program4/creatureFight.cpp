/*****************************************************************
 *****************************************************************
    Title: 			creatureFight.cpp
    Authors: 		April Crockett and Taseen Iqtider
    Date Created: 	11/19/2024
    Last Updateed: 	11/22/2024
    Purpose: 		Creature Fight Game
******************************************************************
******************************************************************/

// Program header
#include "program4.h"

int main()
{
    int numCreatures = 0;
    int maxCreatures;
    int menuOption;
    char saveChoice;
    Creatures *beast = nullptr;

    srand(time(0)); // Seed random number generator

    // Game Title
    cout << "\n********************************************************************************\n";
    cout << "\t\t\t\tCREATURE FIGHT!" << endl;

    // Ask user for creature number
    cout << "********************************************************************************\n\n";
    cout << "What is the maximum number of creatures that can fit in your arena?\n";
    cout << "MAX NUM OF CREATURES: ";
    cin >> maxCreatures;

    // User input validation
    while (!cin || maxCreatures < 1)
    {
        cin.clear();                                         // Clears the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the rest of the current line, up to '\n' or EOF
        cout << "Oops! That didn't make sense. Please enter a positive integer.\n";
        cout << "MAX NUM OF CREATURES: ";
        cin >> maxCreatures;
    }

    // Dynamically allocate new struct array
    beast = new Creatures[maxCreatures];

    do
    {
        // Print Menu
        cout << "\nWhat would you like to do?\n";
        cout << "\t1.  Enter some creatures\n";
        cout << "\t2.  Fight! Fight! Fight!\n";
        cout << "\t3.  Delete a creature\n";
        cout << "\t4.  Print creatures to the screen\n";
        cout << "\t5.  Print creature stats\n";
        cout << "\t6.  End Program\n";

        // Ask for menu option
        cout << "\tENTER 1-6: ";
        cin >> menuOption;

        // Menu option validation
        while (!cin || menuOption < 1 || menuOption > 6)
        {
            cin.clear();                                         // Clears the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignores the rest of the current line, up to '\n' or EOF
            cout << "\tYour choice was invalid.  ENTER 1-6: ";
            cin >> menuOption;
        }

        // Call relevant functions based on menu option
        switch (menuOption)
        {
        case 1:
            enterCreatures(maxCreatures, numCreatures, beast);
            break;
        case 2:
            numCreatures = fight(numCreatures, beast);
            break;
        case 3:
            deleteCreature(numCreatures, beast);
            break;
        case 4:
            printCreatures(numCreatures, beast);
            break;
        case 5:
            printStats(numCreatures, beast);
            break;
        case 6:
            cout << "\nWould you like to save your creature to a file? (y or n) ";
            cin >> saveChoice;
            if (tolower(saveChoice) == 'y') // Ask if they want to save creatures to file
            {
                saveCreaturesToFile(numCreatures, beast);
                cout << "\n\nGOODBYE!\n";
            }
            else
            {
                cout << "\n\nGOODBYE!\n";
            }
        }
    } while (menuOption != 6);

    // Delete dynamically allocated array
    delete[] beast;

    return 0;
}