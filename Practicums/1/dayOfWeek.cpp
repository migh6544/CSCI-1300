// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Practicum 1 - Problem 3

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


/*
The function is given an integer value for the day of the week and will print
the type of the day in the week.

Note:
Your function will print the following values depending on the day (0 through 6):
1 print  "MONDAY"
2, 3, 4  print "WORKDAY"
5 print "FUNDAY"
6, 0 print "SLEEPDAY"
for any other value, print "INVALID"
*/

void dayOfWeek(int a)
{
    switch (a)
    {
        case 1:
            cout << "MONDAY"<< endl;
        break;
        
        case 2:
        case 3:
        case 4:
            cout << "WORKDAY"<< endl;
        break;
        
        case 5:
            cout << "FUNDAY"<< endl;
        break;

        case 6:
        case 0:
            cout << "SLEEPDAY"<< endl;
        break;
        
        default:
            cout << "INVALID" << endl;
        break;
    }
}


int main()
{
    /*
    Teast-1
    Expected Value:
    MONDAY
    */
    dayOfWeek(1);

    /*
    Teast-2
    Expected Value:
    WORKDAY
    */
    dayOfWeek(3);

    /*
    Teast-3
    Expected Value:
    FUNDAY
    */
    dayOfWeek(5);

    /*
    Teast-4
    Expected Value:
    SLEEPDAY
    */
    dayOfWeek(0);

    /*
    Teast-5
    Expected Value:
    INVALID
    */
    dayOfWeek(7);

	return 0;
}