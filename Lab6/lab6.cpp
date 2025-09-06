/***************************************************************************************
    Title:  	lab6(PURPLE).cpp
    Author:		Taseen Iqtider
    Date:		10/23/2024
    Purpose:    Creating a Halloween Town City- Monster Toys
***************************************************************************************/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

// Function Prototypes
int DisplayMenuGetChoice();
int DisplayCoolMessage(int imgCount);
void MonsterToys();

/**************************************************************************************
    main() function has a loop to keep the program running as long as the user wants
    & includes all other user-defined functions
***************************************************************************************/

int main()
{
    int userPick;
    int coolMessageCount = 0;

    do
    {
        // Call DisplayMenuGetChoice to print out the menu & take user's input
        userPick = DisplayMenuGetChoice();

        switch (userPick)
        {
        case 1:   // If user picked 1, call MonsterToys() function
            MonsterToys();
            break;
        case 2:   // If user picked 2, call DisplayCoolMessage() function
            coolMessageCount = DisplayCoolMessage(coolMessageCount);
            break;
        case 3:   // If user picked 3, display how many times the user displayed the ASCII arts & print Goodbye
            cout << "\n\nYou chose to display the cool message " << coolMessageCount << " times.\n\n";
            cout << "Bye!" << endl;
            break;
        }
    } while (userPick != 3);
    
    return 0;
}

/*************************************************************************************
    Function Name: DisplayMenuGetChoice
    Return Value:  int
    Parameters:    none
    Purpose:       To print a menu for the user to read & get their choice
**************************************************************************************/

int DisplayMenuGetChoice()
{
    // Display the menu & ask for a choice
    int choice;
    cout << "\n\nWELCOME TO HALLOWEEN TOWN!" << endl;
    cout << "Please choose one of the following options:" << endl;
    cout << "\t1 - Enter number of Monster toys\n";
    cout << "\t2 - Display Something Cool\n";
    cout << "\t3 - End the Program\n\n";
    cout << "CHOICE: ";
    cin >> choice;
    
    // Validate user choice
    while (choice < 1 || choice > 3)
    {
        cout << "Invalid choice. Please choose 1-3.\n";
        cout << "CHOICE: ";
        cin >> choice;
    }
    return choice;
}

/*****************************************************************************************
    Function Name: MonsterToys
    Return Type:   void
    Parameters:    none
    Purpose:       To display menu option 1 and print those texts in "monsters.txt" file
******************************************************************************************/

void MonsterToys()
{
    int monsterNum, toysInYear1, toysInYear2, toysInYear3;
    int toysCount = 0;
    ofstream outputFile;
    outputFile.open("monsters.txt");

    // Ask the user how many monsters were there
    cout << "\n\nHow many monster(s) worked on toys in Halloween Town during each of the last three years?" << endl;
    cin >> monsterNum;

    for (int i = 0; i < monsterNum; i++)
    {

        // Print toys production to the screen
        cout << "How many toys did Monster " << i + 1 << " make, during year 1 ?" << endl;
        cin >> toysInYear1;
        cout << "How many toys did Monster " << i + 1 << " make, during year 2 ?" << endl;
        cin >> toysInYear2;
        cout << "How many toys did Monster " << i + 1 << " make, during year 3 ?" << endl;
        cin >> toysInYear3;

        // Print to the "monsters.txt" file
        outputFile << "Monster " << i + 1 << ", year 1: " << toysInYear1 << " toys." << endl;
        outputFile << "Monster " << i + 1 << ", year 2: " << toysInYear2 << " toys." << endl;
        outputFile << "Monster " << i + 1 << ", year 3: " << toysInYear3 << " toys." << endl;

        toysCount += (toysInYear1 + toysInYear2 + toysInYear3);
    }

    // Print the total toys in the screen & the .txt file. Then close the file
    cout << "The " << monsterNum << " Monster(s) made a total of " << toysCount << " toys during the last 3 years";
    cout << endl << endl;
    outputFile << "The " << monsterNum << " Monster(s) made a total of " << toysCount << " toys during the last 3 years";
    outputFile.close();
    return;
}

/************************************************************************************
    Function Name: DisplayCoolMessage
    Return Value:  int
    Parameters:    Current number of times the ASCII images are shown
    Purpose:       To display the ASCII images and keeping a running image count
*************************************************************************************/

int DisplayCoolMessage(int imgCount)
{
    string fileName;
    ifstream inputFile;
    string lineOfData;

    cin.ignore();
    // Ask the user for the text file name
    cout << "What is the name of the text file with the ASCII image? ";
    getline (cin,fileName);

    inputFile.open(fileName);

    // Check to see if the file is in the same directory as the source file
    if (!inputFile.is_open())
    {
        cout << "Oh no! Looks like the file could not be opened.\n\n";
        return imgCount;
    }
    else if (inputFile.is_open())
    {
        // Loop through each line of the file & print it
        while (getline(inputFile, lineOfData)) {
            cout << lineOfData << endl;
        }
        // Close the file after each execution & keep a running image counter
        inputFile.close();
        imgCount ++;
        return imgCount;
    }
    return imgCount;
}