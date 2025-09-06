/*************************************************************************
   Title:    lab10_driver.cpp
   Author:   Taseen Iqtider
   Date:  	 December 04, 2024
   Purpose:  Creating a Theme Park Profit Calculator
*************************************************************************/

// Program header
#include "lab10.h"

int main()
{
    int numMonths;
    char choice = 'Y';
    string line;

    do
    {
        // Program Title
        cout << "\n-------------------------------------------------------------------------------------\n";
        cout << "\t       Welcome to Turkey Town Theme Park Profit Calculator!";
        cout << "\n-------------------------------------------------------------------------------------\n\n";

        // Print ASCII Art
        ifstream inputFile("turkey.txt");
        if (inputFile.is_open())
        {
            while (getline(inputFile, line))
            {
                cout << line << endl;
            }
            inputFile.close();
        }

        cout << "\n-------------------------------------------------------------------------------------\n";
        cout << "\nHow many months of profits do you wish to enter?    ";
        cin >> numMonths;

        // Validate the input
        while (!cin || numMonths < 1)
        {
            cin.clear(); // clears the error state
            // line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Whoa! That's not right. Enter a number greater than one!\n\n";
            cout << "How many months of profits do you wish to enter?    ";
            cin >> numMonths;
        }

        // Dynamically allocate profitArray
        double *profitArray;
        profitArray = new double[numMonths];

        // Dynamically allocate dateArray
        string *dateArray;
        dateArray = new string[numMonths];

        cout << "Let's enter some profits!\n";
        cout << "When you enter in the date, enter in the month & year like this:  'April 2024'.\n\n";

        // Call getProfit() function
        getProfit(profitArray, dateArray, numMonths);

        // Call getMax() function
        double highestProfit;
        string topMonth;
        getMax(profitArray, dateArray, numMonths, highestProfit, topMonth);

        // Call getMin() function
        double lowestProfit;
        string lowMonth;
        getMin(profitArray, dateArray, numMonths, lowestProfit, lowMonth);

        // Call getTotal() function
        double totalProfit = getTotal(profitArray, numMonths);

        // Find the average profit
        double avg = totalProfit / numMonths;

        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\t\t    TOTAL PROFITS:             \t$    " << totalProfit;
        cout << "\n\t\t   AVERAGE PROFIT:           \t$     " << avg;
        cout << "\n\t DATE WITH LARGEST PROFIT: \t\t " << topMonth << " totaling $" << highestProfit;
        cout << "\n\tDATE WITH SMALLEST PROFIT:\t\t " << lowMonth << " totaling $" << lowestProfit;
        cout << "\n------------------------------------------------------------------------------------\n";
        cout << "\n------------------------------------------------------------------------------------\n";

        // Release dynamically allocated arrays
        delete[] dateArray;
        delete[] profitArray;

        // Ask if the user wants to go again
        cout << "\nWould you like to run the program again?  (Y/N)\n";
        cin >> choice;
        cout << endl;

    } while (toupper(choice) != 'N');
    return 0;
}