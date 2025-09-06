/*************************************************************************************************
  Title:  	lab3b.cpp
  Author:		Taseen Iqtider
  Date:		  09/19/2024
  Purpose:	Using random number generator to it easier for the pig to pick the food.
**************************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

  // variable definitions
  int food;
  char decision;

  srand(time(0)); // seed random number generator

  /*Generate a random food item between 1 and 3
    where, 1(apple) = healthy food
           2(mud) = bad food
           3(corn) = healthy food
  */

  food = rand() % (3 - 1 + 1) + 1;

  // Output the first message
  cout << "\nYour pig is going on a picnic in the mountains!" << endl
    << endl;

  /*Finding a random food and deciding whether or not to eat it.
    e = eat the food
    l = leave the food
  */

   if (food == 1)
  {
    cout << "The pig found an apple! ";
    cout << "Should it eat it (e) or leave it (l)? ";
  }
  else if (food == 2)
  {
    cout << "The pig found some mud! ";
    cout << "Should it eat it (e) or leave it (l)? ";
  }
  else
  {
    cout << "The pig found some corn! ";
    cout << "Should it eat it (e) or leave it (l)? ";
  }

  // Asking user to input their choice
  cin >> decision;

  // Showing results depending on pig's choice

  if (decision == 'e')
  {
    if (food == 1 || food == 3)
    {
      cout << "Yum! The pig enjoyed the food." << endl;
    }
    else
    {
      cout << "Yuck! The pig got sick from eating the mud." << endl;
    }
  }
  else if (decision == 'l')
  {
    if (food == 1 || food == 2 || food == 3)
    {
      cout << "The pig decided to leave the food and continue the picnic." << endl;
    }
  }
  else
  {
    cout << "Invalid choice! The pig decided to walk away." << endl; // Print Invalid Choice when user inputs anything other than (e/l)
  }

  return 0;
}
