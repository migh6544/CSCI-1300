// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Practicum 1 - Problem 2

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


/*
The function takes two floating numbers and one operator and prints out the
answer based on arithmetic. Assume that there are no overflow, underflow and
division by zero cases. 
*/
    
void calculator(double a, double b, char c)
{
    double d = 0;
    switch (c)
    {
        case '+':
            d = ( a + b );
            cout << a << " " << c << " " << b << " " << "=" << " " << d << endl;
        break;
        
        case '-':
            d = ( a - b );
            cout << a << " " << c << " " << b << " " << "=" << " " << d << endl;
        break;
        
        case '*':
            d = ( a * b );
            cout << a << " " << c << " " << b << " " << "=" << " " << d << endl;
        break;
        
        case '/':
            d = ( a / b );
            cout << a << " " << c << " " << b << " " << "=" << " "; cout << fixed << setprecision(2) << d << endl;
        break;
        
        default:
            cout << "Invalid operator!" << endl;
        break;
    }
}


int main()
{
    /*
    Teast-1
    Expected Value:
    3 + 7 = 11
    */
    calculator(3, 7, '+');

    /*
    Teast-2
    Expected Value:
    3 - 7 = -4
    */
    calculator(3, 7, '-');

    /*
    Teast-3
    Expected Value:
    3 * 7 = 21
    */
    calculator(3, 7, '*');

    /*
    Teast-4
    Expected Value:
    3 / 7 = 0.43
    */
    calculator(3, 7, '/');

    /*
    Teast-5
    Expected Value:
    Invalid operator!
    */
    calculator(3, 7, '!');

	return 0;
}