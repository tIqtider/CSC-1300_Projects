/*************************************************************************************
   Title:    lab10_functions.cpp
   Author:   Taseen Iqtider
   Date:  	 December 04, 2024
   Purpose:  Theme Park Profit Calculator Functions
**************************************************************************************/

// Program Header
#include "lab10.h"

/*******************************************************************************************
   Function name:     getProfit()
   Function type:     void
   Function purpose:  This function asks user for date & profit for the data & profit array
*******************************************************************************************/
void getProfit(double *profitArray, string *dateArray, int numMonths)
{
   for (int i = 0; i < numMonths; i++)
   {
      cin.ignore();
      cout << fixed << setprecision(2); // Read in months and profits
      cout << "DATE:   ";
      getline(cin, *(dateArray + i));
      cout << "PROFIT: $";
      cin >> *(profitArray + i);

      while (!cin || *(profitArray + i) < 1)
      {
         cin.clear(); // clears the error state
         // line below ignores the rest of the current line, up to '\n' or EOF - whichever comes first
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Whoa! That's not right. Enter a number greater than zero!\n";
         cout << "PROFIT: $";
         cin >> *(profitArray + i);
      }
   }
   return;
}

/************************************************************************************************
   Function name:     getTotal()
   Function type:     void
   Function purpose:  This function accumulates a running total of the profit array
************************************************************************************************/
double getTotal(double *profitArray, int numMonths)
{
   double total = 0.0;
   for (int i = 0; i < numMonths; i++)
   {
      total += *(profitArray + i); // Get Total profit
   }
   return total;
}

/************************************************************************************************
   Function name:     getMax()
   Function type:     double
   Function purpose:  This function finds the month with the largest profit in the profit array
************************************************************************************************/
void getMax(double *profitArray, string *dateArray, int numMonths, double &highestProfit, string &topMonth)
{
   highestProfit = *(profitArray + 0);
   topMonth = *(dateArray + 0);
   for (int i = 0; i < numMonths; i++)
   {
      if (*(profitArray + i) > highestProfit)
      {
         highestProfit = *(profitArray + i); // Find the month with highest profit
         topMonth = *(dateArray + i);
      }
   }
   return;
}

/************************************************************************************************
   Function name:     getMin()
   Function type:     double
   Function purpose:  This function finds the month with the smallest profit in the profit array
************************************************************************************************/
void getMin(double *profitArray, string *dateArray, int numMonths, double &lowestProfit, string &lowMonth)
{
   lowestProfit = *(profitArray + 0);
   lowMonth = *(dateArray + 0);
   for (int i = 0; i < numMonths; i++)
   {
      if (*(profitArray + i) < lowestProfit)
      {
         lowestProfit = *(profitArray + i); // Find the month with lowest profit
         lowMonth = *(dateArray + i);
      }
   }
   return;
}