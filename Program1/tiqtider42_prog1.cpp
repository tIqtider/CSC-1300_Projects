/************************************************************************
 *	Filename: tiqtider42_prog1.cpp                                      *
 *	Author:   Taseen Iqtider                                            *
 *	Date:     September 25, 2024                                        *
 *	Purpose:  Creating Alien Space Carnival game using while loop       *
 ************************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Variable declaration
    string name;
    int counter, blastedCounter;
    double distance, speed;
    double timeToReach;
    char choice;

    cout << fixed << setprecision(2);

    // Print game title on top the screen
    cout << "********************************" << endl;
    cout << "*     " << "ALIEN CARNIVAL GAME      " << "*" << endl;
    cout << "********************************" << endl;

    // Asking user to input their name as the Game Master
    cout << "\nEnter your name as the Game Master: ";
    getline(cin, name);
    cout << endl
         << endl;

    // Print Welcome message to the Game Master
    cout << "Welcome, Game Master " << name << ", to the Alien Blaster Showdown!";
    cout << endl
         << endl
         << endl;

    choice = 'y';
    counter = 0;
    blastedCounter = 0;

    // Run the game if it's 'y' or 'Y'
    while ((choice == 'y') || (choice == 'Y'))
    {

        /* Print messaages where it asks the user to input value for saucer's distance & speed
           Distance, Speed and Time cannot be negative
                                                      */

        cout << "Enter the distance of the alien saucer in meters: ";
        cin >> distance;
        cout << "Enter the speed of the alien saucer in meters per second: ";
        cin >> speed;

        // Calculate how much time it'll need for the saucer to reach the crowd
        timeToReach = distance / speed;

        // Print saucer is detected
        cout << "Alien saucer detected! ";
        cout << "Time until it reaches the crowd: " << timeToReach << " second(s)." << endl;

        // Reaction based on saucer's distance
        if (timeToReach < 5)
        {
            cout << "Blast it with foam cannons! It's zooming in too fast!" << endl;
            blastedCounter = blastedCounter + 1;
        }
        else if ((timeToReach >= 5) && (timeToReach <= 15))
        {
            cout << "Hold fire! Let's cheer for the saucer as it zooms by!" << endl;
        }
        else if (timeToReach > 15)
        {
            cout << "No need to worry. It's just hovering around. Keep enjoying the show!" << endl;
        }

        // Ask the user if they want to play again
        cout << "\n\nIs there another saucer approaching? (y/n) : "; // Type (y/n) only
        cin >> choice;
        counter = counter + 1;
    }

    // Print these texts when the user types 'n' & calculate how many saucers they got
    cout << "\nThe Alien Blaster Showdown has ended! ";
    cout << "You tracked " << counter << " saucers.\n";

    if (blastedCounter > 7)
    {
        cout << "That was intense! " << "The crowd loved it-10/10 entertainment!";
    }
    else if (blastedCounter <= 7)
    {
        cout << "What a peaceful show! " << "Everyone left with smiles on their faces.";
    }

    return 0;
}