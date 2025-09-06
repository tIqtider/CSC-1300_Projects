/****************************************************
   Title:    lab10_header.h
   Author:   Taseen Iqtider
   Date:  	 December 04, 2024
   Purpose:  To use header files for lab 10
****************************************************/

// File Guards
#ifndef LAB10_HEADER_H
#define LAB10_HEADER_H

// Program imports
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <string>
#include <ctime>

using namespace std;

// Function prototypes
void getProfit(double *, string *, int);
double getTotal(double *, int);
void getMax(double *, string *, int, double &, string &);
void getMin(double *, string *, int, double &, string &);

// Close Guards
#endif