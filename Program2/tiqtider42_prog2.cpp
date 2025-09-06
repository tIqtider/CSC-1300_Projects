/************************************************************************
 *	Filename: tiqtider42_prog2.cpp                                      *
 *	Author:   Taseen Iqtider                                            *
 *	Date:     October 09, 2024                                          *
 *	Purpose:  Creating a Pet Store Management System                    *
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // Variable definitions
    string petName, animalType, fileLine;
    int menuOption, counter, soldPet;
    fstream inputFile, outputFile;

    // Welcome the user to the pet store
    cout << "\nWelcome to the Pet Store Management System!";

    // Display the pet store menu to the screen
    do
    {
        cout << "\n\nChoose from the following options:\n";
        cout << "1. Add a new animal" << endl;
        cout << "2. Display all animals" << endl;
        cout << "3. Sell an animal" << endl;
        cout << "4. Exit\n";
        cout << endl;
        cout << "Please choose an option: ";
        cin >> menuOption;

        // Validate user's menu option selection
        while (menuOption < 1 || menuOption > 4)
        {
            cout << "Oops! That option doesn't exist. Please choose 1, 2, 3, or 4." << endl;
            cout << "Please choose an option: ";
            cin >> menuOption;
            cout << endl;
        }
        // Made sure the "animals.txt" file is in same directory as the source file

        // Ask the user what type of animal they'd want to add to the "animals.txt" file
        cin.ignore();

        // MENU option 1
        if (menuOption == 1)
        {
            cout << "\nEnter the animal type: ";
            getline(cin, animalType); // Dog:Jack
            cout << "Enter the animal's name: ";
            getline(cin, petName);
            cout << petName << " was added successfully!";
            inputFile.open("animals.txt", ios::out | ios::app);
            inputFile << endl << animalType << ":" << petName;
            inputFile.close();
        }
        // MENU option: 2
        /* Read the current animals from the text file at the beginning of execution
           OR read the updated file after adding or removing the file
        */
        else if (menuOption == 2)
        {
            counter = 1;
            cout << "\nAnimals currently in the shelter:" << endl;
            inputFile.open("animals.txt", ios::in);

            if (!inputFile.is_open())
            {
                cout << "\nError opening file!\n\n"; // Print an error message to the screen if the text file can't be opened for input
                return 1;
            }
            else if (inputFile.is_open())
            {
                while (getline(inputFile, animalType, ':') && getline(inputFile, petName))
                {
                    cout << counter << ". " << animalType << " named " << petName << endl;
                    counter++;
                }
                inputFile.close();
            }
        }
        // MENU option: 3
        else if (menuOption == 3)
        {
            counter = 1;
            cout << "\nAnimals currently in the shelter:" << endl;
            inputFile.open("animals.txt", ios::in); // First, display current pets in the shelter and then ask them which pet they want to remove

            if (!inputFile.is_open())
            {
                cout << "\nError opening file!\n\n"; // Print an error message to the screen if the text file can't be opened for input
                return 1;
            }
            else if (inputFile.is_open())
            {
                while (getline(inputFile, animalType, ':') && getline(inputFile, petName))
                {
                    cout << counter << "." << animalType << " named " << petName << endl;
                    counter++;
                }
                inputFile.close();
            }
            cout << "\nEnter the number of the animal that sold: ";
            cin >> soldPet;

            //  Validate user's selection when they want to remove an aniaml
            while ((soldPet > (counter - 1)) || (soldPet < 1))
            {
                cout << "Oops! There is no animal with number " << soldPet << ". ";
                cout << "Select an animal between 1 and " << counter - 1 << endl;
                cout << "Enter the number of the animal that sold: ";
                cin >> soldPet;
            }

            // Create a temporary file ("temp.txt") and rename it to "aniamls.txt" with the updated list of pets
            cin.ignore();
            counter = 1;

            // Open both files ("animals.txt", "temp.txt")
            outputFile.open("temp.txt", ios::out);
            inputFile.open("animals.txt", ios::in);

            /* Read in from "animals.txt" line by line
               Conditionally print the animals to the "temp.txt"
            */

            getline(inputFile, fileLine);

            // Made sure the file didn't read a blank line and put the animal down below in the next line instead of the right line
            if (soldPet != 1)
            {
                outputFile << fileLine;
                counter++;
            }
            else
            {
                getline(inputFile, fileLine);
                outputFile << fileLine;
                counter++;
            }
            while (getline(inputFile, fileLine))
            {
                if (soldPet != counter)
                {
                    outputFile << endl << fileLine;
                }
                counter++;
            }

            /* Close all files
               remove previous "animals.txt" file
               rename the "temp.txt" file to "animals.txt"
            */
            outputFile.close();
            inputFile.close();
            remove("animals.txt");
            rename("temp.txt", "animals.txt");
            cout << "The animal has been removed from the file.";
        }
    } while (menuOption != 4);

    // MENU option 4
    // Break out of the loop when user presses option 4, print a goodbye message
    cout << "\nGoodbye!\n";
    return 0;
}