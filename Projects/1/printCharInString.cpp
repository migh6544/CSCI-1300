// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 1 - Problem 1

#include <iostream>
#include <math.h>
#include <string>

using namespace std;


void printCharInString(string input)
{
    /*
    Algorithem: 
    The function takes a string argument and prints all the characters in the
    string on a new line. If the string has no entry, i.e. " ", then it prints
    "Given string is empty!".
    */

    int i = input.length(); /* Declaring the value of i befor calculation */
    int s = 0;              /* Declaring the value of i befor calculation */
    
    if (i <= 0)             /* Calculation and operation for empty input */
    {
        cout << "Given string is empty!" << endl;
    }
    while (s < i)           /* Calculation and loop operation for printing input */
    {
        cout <<  input[s] << endl;
        s++;
    }
}



int main()
{
    // Test 1
    // Expected output
    //" "
    printCharInString("");
    cout<<endl;
    
    // Test 2
    // Expected output
    // M i c h @ e l
    printCharInString("Mich@el");
    cout<<endl;
    
    // Test 3
    // Expected output
    // C S C I 1 3 0 0
    printCharInString("CSCI1300");
    cout<<endl;
    
    return 0;
}