/*
    Title:  	lab2c.cpp
    Author:		Robby Molloy & Taseen Iqtider
    Date:		9/18/2024
    Purpose:	This program is written to decipher hidden messages using the Caesar Cipher

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // defined variables, ones in Spanish are the final stored values
    char one, two, three, four, five, six, seven;
    char uno, dos, tres, cuatro, cinco, seis, siete;
    int shift;

    // Beginning portion where we ask for seven characters, inputting them into char variables as we do, and then ask for an amount shift

    cout << "\nEnter in seven characters and I will use a modified Caesar Cipher to decode it." << endl;
    cout << "\nFirst character: ";
    cin >> one;
    cout << "Second character: ";
    cin >> two;
    cout << "Third character: ";
    cin >> three;
    cout << "Fourth character: ";
    cin >> four;
    cout << "Fifth character: ";
    cin >> five;
    cout << "Sixth character: ";
    cin >> six;
    cout << "Seventh character: ";
    cin >> seven;

    // shifting the initial variables, storing them into their final values

    cout << "\nYou entered " << one << two << three << four << five << six << seven << endl;
    cout << "\nWhat integer should I use for the shift variable? ";
    cin >> shift;
    uno = (one + shift);
    dos = (two + shift);
    tres = (three + shift);
    cuatro = (four + shift);
    cinco = (five + shift);
    seis = (six + shift);
    siete = (seven + shift);

    // deciphering the characters entered using the shift

    cout << "\nThe text deciphered is " << uno << dos << tres << cuatro << cinco << seis << siete;

    return 0;
}