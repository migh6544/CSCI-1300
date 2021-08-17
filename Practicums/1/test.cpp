// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Practicum 1 - Problem 2

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


void printSeriesSquareFifth(int n)
{
    int i = 1;
    int x = 0;
    int y = 0;
    while (i <= n)
    {
        if (i == n)
        { 
            if ((i % 5) != 0)
            {
                x = i;
                cout << x ;
                y = y + x;
            }
            else if ((i % 5) == 0)
            {
                x = i * i;
                cout << x ;
                y=y+x;
            }
            i++;
        }
        else
        {
            if ((i % 5) != 0)
            {
                x = i;
                cout << x << " + ";
                y=y+x;
            }
            else if ((i % 5) == 0)
            {
                x = i * i;
                cout << x << " + ";
                y=y+x;
            }
            i++;
        }
    }
    cout << endl << "Result of the series is " << y << endl;
}


int main()
{
    printSeriesSquareFifth(10);
	return 0;
}