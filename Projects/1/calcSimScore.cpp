// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 1 - Problem 4

#include <iostream>
#include <math.h>
#include <string>

using namespace std;


double calcSimScore(string sq1, string sq2)
{
    /*
    The function takes in the genetic code sequence for two different genomes,
    evaluates the length of their code and eveluates the value of their similarity.
    */
    
    int s1 = sq1.length();
    int s2 = sq2.length();
    int h = 0;
    
    if (s1 == 0 || s2 == 0 || s1 != s2)     /* Evluating length compatability */
    {  
        return 0;
    }
    for (int l = 0; l < s1 && l < s2; l++)  /* Evaluating code differences */
    {
        if(sq1[l] != sq2[l])
        {
            h++;
        }
    }
    double s = (double)(s1 - h)/s2;         /* Calculating similarity score */
    return s;
}


int main()
{
    // Test 1
    // Expected output
    // 0.75
    cout << calcSimScore("ATGC", "ATGA") << endl;
    
    // Test 2
    // Expected output
    // 1
    cout << calcSimScore("CCDCCD", "CCDCCD") << endl;
    
    // Test 3
    // Expected output
    // 0
    cout << calcSimScore("ACCDT", "ACT") << endl;
    
    return 0;
}