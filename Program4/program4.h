/*****************************************************************
 *****************************************************************
	Title: 			program4.h
	Authors: 		April Crockett and Taseen Iqtider
	Date Created: 	11/19/2024
	Last Updateed: 	11/22/2024
	Purpose: 		Creature Fight Game
******************************************************************
******************************************************************/

// File Guards
#ifndef PROGRAM4_H
#define PROGRAM4_H

// Program Imports
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <limits>

using namespace std;

// Struct Definitions
struct Stats
{
	int hitPoints;
	int healthPoints;
	char special[3];
};
struct Creatures
{
	string name;
	string description;
	double length;
	double height;
	string location;
	bool ferocity;
	Stats creaStats;
};

// Function Prototypes
int enterCreatures(int, int &, Creatures *);
int fight(int, Creatures *);
void calculateModifier(int, Creatures *, int &);
int deleteCreature(int &, Creatures *);
bool moveArrayElements(string, int &, Creatures *);
void printCreatures(int, Creatures *);
void printStats(int, Creatures *);
void saveCreaturesToFile(int, Creatures *);

// Close guards
#endif