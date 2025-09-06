/*******************************************************************************************************************
    Title:  	halloween.cpp
    Author:		Taseen Iqtider
    Date:		11/06/2024
    Purpose:	Making my own Halloween Store & planning a Halloween Party
********************************************************************************************************************/

#include "Halloween.h"

// Global Constant Variables for guest[] & activities[]
const int MAX_GUESTS = 10;
const int MAX_ACTIVITIES = 10;

int main()
{
    int menuChoice;
    string guests[MAX_GUESTS];
    string activities[MAX_ACTIVITIES];
    string food[4] = {"Witch Finger Cookies", "Zombie Meatloaf", "Eyeball Punch", "Spider Web Cupcakes"};
    int servings[4] = {7, 6, 12, 15};
    int guestCount = 0;
    int activitiesCount = 0;

    cout << "\n~Time to plan my awesome Halloween party!~\n\n";

    do
    {
        // Call printMenu() to print main menu
        printMenu();
        cin >> menuChoice;
        cout << endl;

        // Validate user's menuChoice
        while (menuChoice < 1 || menuChoice > 5)
        {
            cout << "You must enter in a choice between 1 and 5.\n";
            cout << "CHOOSE 1-5: ";
            cin >> menuChoice;
            cout << endl;
        }

        if (menuChoice == 1)
        {
            // Call manageGuestList() to print menu option 1
            manageGuestList(guests, guestCount);
        }
        else if (menuChoice == 2)
        {
            // Call planHauntedActivities() to print menu option 2
            planHauntedActivities(activities, activitiesCount);
        }

        else if (menuChoice == 3)
        {
            // Call trackFood() to print menu option 3
            trackFood(food, servings);
        }

        else if (menuChoice == 4)
        {
            // Call saveToFile() to print menu option 4
            saveToFile(guests, guestCount, activities, activitiesCount, food, servings);
        }
    } while (menuChoice != 5);
    cout << "\nExiting Program.\n"; // Exit the program
    return 0;
}

/********************************************************************************************************************
    Function Name: printMenu()
    Return Value:  void
    Parameters:    none
    Purpose:       To print out main menu
********************************************************************************************************************/

void printMenu()
{
    cout << "1. Manage Guest List\n";
    cout << "2. Manage Activities\n";
    cout << "3. Manage Food\n";
    cout << "4. Save Party to File\n";
    cout << "5. Exit Party Planning\n";
    cout << "Enter a choice between 1 and 5.\n";
    cout << "CHOOSE 1-5: ";
    return;
}

/********************************************************************************************************************
    Function Name: manageGuestList()
    Return Value:  int
    Parameters:    guests array, numGuests
    Purpose:       To print guest list menu for the halloween party
********************************************************************************************************************/

int manageGuestList(string guests[], int &numGuests)
{
    int guestChoice, removeGuest;
    string guestName;
    cout << "Guest list:\n";
    for (int i = 0; i < numGuests; ++i)
    {
        cout << "\t" << (i + 1) << ". " << guests[i] << "\n"; // Print current guest list
    }
    do
    {
        // Print guestFunction menu
        cout << "1. Add Guest" << endl;
        cout << "2. Remove Guest" << endl;
        cout << "3. Modify Guest" << endl;
        cout << "4. Exit Guest List" << endl;
        cout << "Enter your choice: ";
        cin >> guestChoice;
        cout << endl;

        // Read in guestChoice and validate it
        while (guestChoice < 1 || guestChoice > 4)
        {
            cout << "You must enter in a choice between 1 and 4.\n"; // Input Validation
            cout << "CHOOSE 1-4: ";
            cin >> guestChoice;
        }
        switch (guestChoice)
        {

        case 1:
        {
            if (numGuests >= MAX_GUESTS)
            {
                cout << "Guest list is full\n"; // If array is full
                return -1;
            }
            if (numGuests <= MAX_GUESTS)
            {
                cout << "Enter the guest's name: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, guests[numGuests]);
                numGuests++; // Read in guest's name and increase guest count

                cout << "\nGuest list:\n";
                for (int i = 0; i < numGuests; ++i)
                {
                    cout << "\t" << (i + 1) << ". " << guests[i] << "\n"; // Iterate guest array elements
                }
            }
            break;
        }

        case 2:
        {
            if (numGuests == 0)
            {
                cout << "There are no guests currently invited!\n"; // If array is empty
                cout << "\nGuest list:\n";
                for (int i = 0; i < numGuests; ++i)
                {
                    cout << "\t" << (i + 1) << ". " << guests[i] << "\n"; // Print current guest list
                }
            }
            else
            {
                int guestToRemove;
                cout << "Enter the guest you want to remove: "; // Read user's input to remove a guest
                cin >> guestToRemove;

                while ((guestToRemove < 1) || (guestToRemove > numGuests))
                {
                    cout << "You must enter a number between 1 and " << numGuests << ": "; // Validate if the guest is inside guest list
                    cin >> guestToRemove;
                }
                if (guestToRemove <= numGuests)
                {
                    for (int i = guestToRemove - 1; i < numGuests - 1; ++i) // Shift guests down to remove the selected guest
                    {
                        guests[i] = guests[i + 1];
                    }
                    numGuests--; // Decrease guest count

                    cout << "\nGuest List:\n";
                    for (int i = 0; i < numGuests; ++i)
                    {
                        cout << "\t" << (i + 1) << ". " << guests[i] << "\n"; // Iterate guest array elements
                    }
                }
            }
            break;
        }

        case 3:
        {
            if (numGuests == 0)
            {
                cout << "There are no guests currently invited!\n"; // If array is empty
                cout << "\nGuest list:\n";
                for (int i = 0; i < numGuests; ++i)
                {
                    cout << "\t" << (i + 1) << ". " << guests[i] << "\n"; // Iterate activities array elements
                }
            }
            else
            {
                int guestToModify;
                cout << "Enter the number of the guest to modify: ";
                cin >> guestToModify;

                while (guestToModify < 1 || guestToModify > numGuests)
                {
                    cout << "You must enter a number between 1 and " << numGuests << ": "; // Validate if the guest is inside guest list
                    cin >> guestToModify;
                }
                if (guestToModify <= numGuests)
                {
                    cout << "Enter their new name: ";
                    cin.ignore();                            // Clear the newline character from input buffer
                    getline(cin, guests[guestToModify - 1]); // Update guest name

                    cout << "\nGuest List:\n";
                    for (int i = 0; i < numGuests; ++i) // Iterate current guest list
                    {
                        cout << "\t" << (i + 1) << ". " << guests[i] << "\n";
                    }
                }
            }
            break;
        }
        }
    } while (guestChoice != 4);
    cout << "***Exiting Guest List...***\n\n"; // Exit manageGuestList() function
    return 0;
}

/********************************************************************************************************************
    Function Name: planHauntedActivities()
    Return Value:  int
    Parameters:    activities array, numActivities
    Purpose:       To print activity list menu for the halloween party
********************************************************************************************************************/

int planHauntedActivities(string activities[], int &numActivities)
{
    int activityChoice;
    string activityName;
    cout << "Activities:\n";
    for (int i = 0; i < numActivities; ++i)
    {
        cout << "\t" << (i + 1) << ". " << activities[i] << "\n";
    }
    do
    {
        // Print activities function menu
        cout << "1. Add Activity" << endl;
        cout << "2. Remove Activity" << endl;
        cout << "3. Modify Activity" << endl;
        cout << "4. Exit Activity List" << endl;
        cout << "Enter your choice: ";
        cin >> activityChoice;
        cout << endl;

        while (activityChoice < 1 || activityChoice > 4)
        {
            cout << "You must enter in a choice between 1 and 4.\n"; // Validate user's activity choice
            cout << "CHOOSE 1-4: ";
            cin >> activityChoice;
        }
        switch (activityChoice)
        {

        case 1:
        {
            if (numActivities >= MAX_GUESTS)
            {
                cout << "Activity list is full\n"; // If array is full
            }
            if (numActivities <= MAX_ACTIVITIES)
            {
                cout << "Enter an activity: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, activities[numActivities]);
                numActivities++; // Read in activity name and increase activities count

                cout << "\nActivities:\n";
                for (int i = 0; i < numActivities; ++i)
                {
                    cout << "\t" << (i + 1) << ". " << activities[i] << "\n"; // Iterate activities array elements
                }
            }
            break;
        }

        case 2:
        {
            if (numActivities == 0)
            {
                cout << "You have no activities planned!\n"; // If array is empty
                cout << "\nActivities:\n";
                for (int i = 0; i < numActivities; ++i)
                {
                    cout << "\t" << (i + 1) << ". " << activities[i] << "\n"; // Iterate current activity list
                }
            }
            else
            {
                int activityToRemove;
                cout << "Enter the activity you want to remove: ";
                cin >> activityToRemove;

                while ((activityToRemove < 1) || (activityToRemove > numActivities))
                {
                    cout << "You must enter a number between 1 and " << numActivities << ": "; // Validate user input
                    cin >> activityToRemove;
                }
                if (activityToRemove <= numActivities)
                {
                    for (int i = activityToRemove - 1; i < numActivities - 1; ++i)
                    {
                        activities[i] = activities[i + 1]; // Shift activity down to remove the selected activity
                    }
                    numActivities--; // Decrease activities count

                    cout << "\nActivities:\n";
                    for (int i = 0; i < numActivities; ++i)
                    {
                        cout << "\t" << (i + 1) << ". " << activities[i] << "\n"; // Iterate activities array elements
                    }
                }
            }
            break;
        }

        case 3:
        {
            if (numActivities == 0)
            {
                cout << "You have no activities planned!\n"; // If array is empty
                cout << "\nActivities:\n";
                for (int i = 0; i < numActivities; ++i)
                {
                    cout << "\t" << (i + 1) << ". " << activities[i] << "\n"; // Iterate current activities
                }
            }
            else
            {
                int activityToModify;
                cout << "Enter the activity you would like to modify: ";
                cin >> activityToModify;
                while (activityToModify < 1 || activityToModify > numActivities)
                {
                    cout << "You must enter a number between 1 and " << numActivities << ": "; // Validate user input
                    cin >> activityToModify;
                }
                if (activityToModify <= numActivities)
                {
                    cout << "Enter the new activity: ";
                    cin.ignore();                                   // Clear the newline character from input buffer
                    getline(cin, activities[activityToModify - 1]); // Update the activity name

                    cout << "\nActivities:\n";
                    for (int i = 0; i < numActivities; ++i)
                    {
                        cout << "\t" << (i + 1) << ". " << activities[i] << "\n"; // Iterate activities array elements
                    }
                }
            }
            break;
        }
        }

    } while (activityChoice != 4);
    cout << "***Exiting Activity List...***\n\n"; // Exit Activity List
    return 0;
}

/********************************************************************************************************************
    Function Name: trackFood()
    Return Value:  void
    Parameters:    food array, servings array
    Purpose:       To print out available food options for the halloween party
********************************************************************************************************************/

void trackFood(string food[], int servings[])
{
    for (int i = 0; i < 4; ++i)
    {
        cout << food[i] << " has " << servings[i] << " servings prepared.\n"; // Iterate food[] & servings[] elements
    }
    cout << endl;
    return;
}

/********************************************************************************************************************
    Function Name: saveToFile()
    Return Value:  void
    Parameters:    guests array, numGuests; activities array, numActivities; food array, servings array
    Purpose:       To write all array elements to a text file
********************************************************************************************************************/

void saveToFile(string guests[], int &guestCount, string activities[], int &activiesCount, string food[], int servings[])
{
    string fileName;
    ofstream outputFile;

    cin.ignore();
    cout << "What do you want to name your file? (name.txt) "; // Prompt the user to name the text file
    getline(cin, fileName);
    outputFile.open(fileName);

    outputFile << "Guest List:\n";
    for (int i = 0; i < guestCount; i++)
    {
        outputFile << "\t " << guests[i] << "\n"; // Iterate guests[] elements & print them to text file
    }

    outputFile << "Planned Activities:\n";
    for (int i = 0; i < activiesCount; i++)
    {
        outputFile << "\t " << activities[i] << "\n"; // Iterate activities[] elements & print them to text file
    }

    // Save foods to file
    outputFile << "Food:\n";
    for (int i = 0; i < 4; i++)
    {
        outputFile << "\t " << food[i] << ": " << servings[i] << "\n"; // Iterate food[] & servings[] elements & print them to text file
    }
    outputFile.close();
    cout << "Party Details have been printed to " << fileName << "!\n\n"; // Copy arrays' data to (name.txt) file
    return;
}