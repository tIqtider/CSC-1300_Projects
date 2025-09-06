/********************************************************************************************************************
    Title:  	Halloween.h
    Author:		Taseen Iqtider
    Date:		11/06/2024
    Purpose:	Halloween.h header file for the halloween party
********************************************************************************************************************/

// File Guards
#ifndef HALLOWEEN_H
#define HALLOWEEN_H

// Program Imports
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

// Function Prototypes
void printMenu();
int manageGuestList(string[], int &);
int planHauntedActivities(string[], int &);
void trackFood(string[], int[]);
void saveToFile(string[], int &, string[], int &, string[], int[]);

// Close guards
#endif