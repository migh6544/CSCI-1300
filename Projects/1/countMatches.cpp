// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 1 - Problem 2

#include <iostream>
#include <math.h>
#include <string>

using namespace std;


int countMatches(string a, string b)
{
    /* 
    Algorithem: 
    The function receives a string and searches for a substring within the given
    string, then returns how many times that specific substring appears within
    the string.
    */

    int i = a.length();
    int s = b.length();
    int y = 0;
    int e = -1;
    
    if (i == 0 || s == 0)           /* Calculation and operation for empty input */
    {
        return e;
    }
    for (int j = 0; j < i; j++)     /* Operation for identifing repetition */
    {
        if (a.substr(j,s) == b)     /* calculation of number of repetitions */
        {
            y++;
        }
    }
    return y;
}



int main()
{
    // Test 1
    // Expected output
    // 2
    cout << countMatches("sisi", "si") << endl;
    
    // Test 2
    // Expected output
    // 2
    cout << countMatches("voodoo", "oo") << endl;
    
    // Test 3
    // Expected output
    // 1
    cout << countMatches("joint", "in") << endl;
    
    return 0;
}