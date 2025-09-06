/*************************************************************************************
   Title:    lab7_functions.cpp
   Author:   Taseen Iqtider
   Date:  	 October 29, 2024
   Purpose:  Predicting the user's future with validation and functions
**************************************************************************************/

// Program header
#include "lab7_header.h"

/*************************************************************************************
    Function Name: generateRandomInt
    Return Value:  int
    Parameters:    maximum & minimum value
    Purpose:       To generate a random number between a certain range
**************************************************************************************/

int generateRandomInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

/*************************************************************************************
    Function Name: getNumChildren
    Return Value:  void
    Parameters:    numOne, numTwo, numThree
    Purpose:       To read in three numbers for user's child count
**************************************************************************************/

void getNumChildren(int &numOne, int &numTwo, int &numThree)
{

    cout << "\nEnter a number between 1 and 100: ";
    cin >> numOne;

    // Validate the input
    while (!cin || numOne < 1 || numOne > 100)
    {
        cin.clear(); // clears the error state
        // line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The number you entered was invalid.\n";
        cout << "Enter a number between 1 and 100: ";
        cin >> numOne;
    }

    cout << "\nEnter another number between 1 and 100: ";
    cin >> numTwo;

    // Validate the input
    while (!cin || numTwo < 1 || numTwo > 100)
    {
        cin.clear(); // clears the error state
        // line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The number you entered was invalid.\n";
        cout << "Enter a number between 1 and 100: ";
        cin >> numTwo;
    }

    cout << "\nEnter another number between 1 and 100: ";
    cin >> numThree;

    // Validate the input
    while (!cin || numThree < 1 || numThree > 100)
    {
        cin.clear(); // clears the error state
        // line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The number you entered was invalid.\n";
        cout << "Enter a number between 1 and 100: ";
        cin >> numThree;
    }
    cin.ignore();
    return;
}

/*************************************************************************************
    Function Name: getSalary
    Return Value:  void
    Parameters:    salOne, salTwo, salThree
    Purpose:       To read in three numbers for user's salary
**************************************************************************************/

void getSalary(double &salOne, double &salTwo, double &salThree)
{
    cout << "\nEnter a number between 10,000 and 500,000: ";
    cin >> salOne;

    // Validate the input
    while (!cin || salOne < 10000 || salOne > 500000)
    {
        cin.clear(); // clears the error state
        // line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The number you entered was invalid.\n";
        cout << "Enter a number between 10,000 and 500,000: ";
        cin >> salOne;
    }

    cout << "\nEnter another number between 10,000 and 500,000: ";
    cin >> salTwo;

    // Validate the input
    while (!cin || salTwo < 10000 || salTwo > 500000)
    {
        cin.clear(); // clears the error state
        // line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The number you entered was invalid.\n";
        cout << "Enter a number between 10,000 and 500,000: ";
        cin >> salTwo;
    }

    cout << "\nEnter another number between 10,000 and 500,000: ";
    cin >> salThree;

    // Validate the input
    while (!cin || salThree < 10000 || salThree > 500000)
    {
        cin.clear(); // clears the error state
        // line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The number you entered was invalid.\n";
        cout << "Enter a number between 10,000 and 500,000: ";
        cin >> salThree;
    }
    cout << endl << endl;
    return;
}