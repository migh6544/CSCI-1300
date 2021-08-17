// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 1 - Problem 3

#include <iostream>
#include <math.h>
#include <string>

using namespace std;


void printMenu()    /* showMenu function for problem 3 in proj 1 */
{
	cout << "Select a numerical option:" << endl;
	cout << "=== menu ===" << endl;
	cout << "1. Fox" << endl;
	cout << "2. Bunny" << endl;
	cout << "3. Sloth" << endl;
	cout << "4. Quit" << endl;
}

int hireScore(int a)
{
    double ag = 0;
    double st = 0;
    double sp = 0;
    
    switch (a) 
    {
    /*
    The function takes in the species of each candidate based on the input from
    the printed menu, then requests a score for their attributes in agility,
    strength and speed for each candidate. Finally the function produces a hire
    score for each candidate.
    */
        double hs;
        case 1:         /* Fox calculation */
            a == 1;     
            cout << "Enter agility:" << endl;
            cin >> ag;
            cout << "Enter strength:" << endl;
            cin >> st;
            hs = (1.8 * ag) + (2.16 * st);
            cout << "Hire Score: " << hs << endl;
            return 0;
        
        case 2:         /* Bunny calculation */
            a == 2;     
            cout << "Enter agility:" << endl;
            cin >> ag;
            cout << "Enter speed:" << endl;
            cin >> sp;
            hs = (1.8 * ag) + (3.24 * sp);
            cout << "Hire Score: " << hs << endl;
            return 0;
        
        case 3:         /* Sloth calculation */
            a == 3;     
            cout << "Enter strength:" << endl;
            cin >> st;
            cout << "Enter speed:" << endl;
            cin >> sp;
            hs = (2.16 * st) + (3.24 * sp);
            cout << "Hire Score: " << hs << endl;
            return 0;
            
        default:        /* All other invalid input values or option 4*/
            return 0;
    }
}

int main()
{
    /* 
    Algorithem: 
    0- Requests value of candidate type
    1- Request value for agility
    2- Request value for strength
    3- Request value for speed
    4- Calculate hire score
    5- Print hire score
    6- End program
    */
    
    printMenu();
    int a;
    cin >> a;
    
    while (a > 0 && a < 4)
    {
        hireScore(a);
        printMenu();
        cin >> a;
    }
}