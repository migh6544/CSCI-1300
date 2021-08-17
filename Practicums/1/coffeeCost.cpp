// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Practicum 1 - Problem 1

#include <iostream>
#include <cmath>

using namespace std;


/* 
The function calculates the cost of a student's coffee consumption. The function
will take an integer for the number of cups of coffee and a floating point value
for the cost per cup. The function will return a floating point value for the
total cost of coffee.
    
Note:
The students use a coffee house that rewards the student for caffeine overload
by giving a free cup for buying every 12 cups.
*/

double coffeeCost(int c, double p)
{
    double t;
    if (c > 12)
    {
        t = (( c * p) - (( c / 12) * p));
    }
    else
    {
        t = ( c * p);
    }
    return double(t);
}


int main()
{
    /*
    Teast-1
    Expected Value:
    36
    */
    cout << coffeeCost(12, 3) << endl;

    /*
    Teast-2
    Expected Value:
    39
    */
    cout << coffeeCost(14, 3) << endl;

    /*
    Teast-3
    Expected Value:
    37.5
    */
    cout << coffeeCost(27,1.5) << endl;

	return 0;
}