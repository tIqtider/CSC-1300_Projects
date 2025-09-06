/*******************************************************************************************************************
    Title:  	lab5.cpp
    Author:		Taseen Iqtider
    Date:		10/09/2024
    Purpose:	Creating a fantastical game (similar to the idea of Rock-Paper-Scissors) where you play with the CPU
********************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    /* Variable declaration
       "numPlayers, nameOfplayers, playerChoice, counterPlayerWin" are associated with the contestant.
       "cpuChoice, counterCpuWin" are associated with the computer.
    */

    string nameOfPlayer;
    int playerChoice, cpuChoice;
    int totalRoundsPlayed = 0;
    int ties = 0;
    double avg, numPlayers;

    // Display the game title.

    cout << "\n\n\t\t\t\t*************************";
    cout << "SONG OF ICE AND FIRE";
    cout << "*************************" << endl  << endl;
    cout << "\t\t\t\t\t  This game's idea is inspired by GAME OF THRONES." << endl;

    // Ask how many users are playing
    cout << "\nHow many contestants are playing? ";
    cin >> numPlayers;
    cout << endl << endl;

    // Verify if number of contestants is greater than 1; if not ask for a valid input
    while (numPlayers < 1)
    {
        cout << "Do you want to play? :( " << endl;
        cout << "Please have at least 1 contestant: ";
        cin >> numPlayers;
        cout << endl << endl;
    }

    // Seed random cpu choice
    srand(time(0));

    // Reiterate the game for each contestants
    for (int i = 1; i <= numPlayers; i++)
    {
        int counterPlayerWin = 0;
        int counterCpuWin = 0;
        int roundsPlayed = 0;

        cin.ignore();
        cout << "\nWhat's your name contestant " << i << "? ";
        getline(cin, nameOfPlayer);
        cout << endl;
        cout << "Pick your power wisely, for the fate of the realm rests in your hands." << endl << endl;
        do
        {
            cout << "Choose your power:\n"; // Print the menu
            cout << "1. Dragon" << endl;
            cout << "2. Valyrian Sword" << endl;
            cout << "3. Night King" << endl;
            cin >> playerChoice;
            cout << endl;

            /*
            In GAME OF THRONES,

            The Iron Throne is forged from hundreds of Valyrian swords, melted down with dragon fire into an uneven seat.
                That's why:
                (1) Dragon defeats the Valyrian Sword.
            Arya Stark of House Stark killed the Night King with mighty Valyrian Sword. But it's not easy to kill a dragon with a Valyrian Sword.
                That's why:
                (2) Valyrian Sword defeats the Night King.
            A dragon named Drogon tried to kill the Night King with its fire but couldn't kill him, while earlier in the season, the Night King killed another dragon named Tessarion with his lethal icy spears.
                That's why:
                (3) Night King defeats Dragons.
            */

            // Validate contestant's weapon selection
            while (playerChoice < 1 || playerChoice > 3)
            {
                cout << "No specialty moves. Choose option 1-3: ";
                cin >> playerChoice;
                cout << endl;
            }

            // Generate random cpu choice between 1-3
            cpuChoice = rand() % 3 + 1;

            if ((playerChoice == 1) && (cpuChoice == 1))
            {
                cout << "You chose Dragon." << endl;  
                cout << "Computer chose Dragon too." << endl;
                roundsPlayed++;   
                cout << "Round " << roundsPlayed << " is a tie!!\n\n";  // Dragon vs Dragon: TIE
                ties++;
            }
            else if ((playerChoice == 1) && (cpuChoice == 2))
            {
                cout << "You chose Dragon." << endl;
                cout << "Computer chose Valyrian Sword." << endl;
                roundsPlayed++;  
                cout << "Round " << roundsPlayed << ": " << nameOfPlayer << " wins!!\n\n";  // Dragon vs Valyrian Sword: Dragon wins
                counterPlayerWin++;
            }
            else if ((playerChoice == 1) && (cpuChoice == 3))
            {
                cout << "You chose Dragon." << endl;
                cout << "Computer chose Night King." << endl;
                roundsPlayed++;   
                cout << "Round " << roundsPlayed << ": Computer wins :( \n\n";  // Dragon vs Night King: Night King wins
                counterCpuWin++;
            }
            else if ((playerChoice == 2) && (cpuChoice == 1))
            {
                cout << "You chose Valyrian Sword." << endl;
                cout << "Computer chose Dragon." << endl;
                roundsPlayed++;  
                cout << "Round " << roundsPlayed << ": Computer wins :( \n\n";  // Valyrian Sword vs Dragon: Dragon wins
                counterCpuWin++;
            }
            else if ((playerChoice == 2) && (cpuChoice == 2))
            {

                cout << "You chose Valyrian Sword." << endl;
                cout << "Computer chose Valyrian Sword too" << endl;
                roundsPlayed++;
                cout << "Round " << roundsPlayed << " is a tie!!\n\n";  // Valyrian Sword vs Valyrian Sword: TIE
                ties++;
            }
            else if ((playerChoice == 2) && (cpuChoice == 3))
            {
                cout << "You chose Valyrian Sword." << endl;
                cout << "Computer chose Night King." << endl;
                roundsPlayed++;
                cout << "Round " << roundsPlayed << ": " << nameOfPlayer << " wins!!\n\n";  // Valyrian Sword vs Night King: Valyrian Sword wins
                counterPlayerWin++;
            }
            else if ((playerChoice == 3) && (cpuChoice == 1))
            {
                cout << "You chose Night King." << endl;
                cout << "Computer chose Dragon." << endl;
                roundsPlayed++;
                cout << "Round " << roundsPlayed << ": " << nameOfPlayer << " wins!!\n\n";  // Night King vs Dragon: Night King wins
                counterPlayerWin++;
            }
            else if ((playerChoice == 3) && (cpuChoice == 2))
            {
                cout << "You chose Night King." << endl;
                cout << "Computer chose Valyrian Sword." << endl;
                roundsPlayed++;
                cout << "Round " << roundsPlayed << ": Computer wins :( \n\n";  // Night King vs Valyrian Sword: Valyrian Sword wins
                counterCpuWin++;
            }
            else if ((playerChoice == 3) && (cpuChoice == 3))
            {
                cout << "You chose Night King." << endl;
                cout << "Computer chose Night King." << endl;
                roundsPlayed++;
                cout << "Round " << roundsPlayed << " is a tie!!\n\n";  // Night King vs Night King: TIE
                ties++;
            }

        } while (counterPlayerWin < 3 && counterCpuWin < 3);

        totalRoundsPlayed += roundsPlayed;

        // Announce the game winner
        if (counterPlayerWin == 3)
        {
            cout << nameOfPlayer << " wins!! So proud :)" << endl << endl;
        }
        else
        {
            cout << "The computer wins :( womp womp" << endl << endl;
        }
    }
    // Print total rounds for each contestant, average rounds they palyed, & total ties they had in the game
    cout << "Total Rounds: " << totalRoundsPlayed << endl;
    avg = totalRoundsPlayed / numPlayers;
    cout << "Average rounds per contestant: " << avg << endl;
    cout << "Total Ties: " << ties << endl;

    return 0;
}