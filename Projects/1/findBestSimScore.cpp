// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 1 - Problem 5

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
    for (int l = 0; l < s1; l++)            /* Evaluating code differences */
    {
        if(sq1[l] != sq2[l])
        {
            h++;
        }
    }
    double s = (double)(s1 - h)/s2;         /* Calculating similarity score */
    return s;
}


double findBestSimScore(string g, string s)
{
    /*
    The function takes in a string of a genome and a sequence within that genome
    and returns a value for the highest similarity score found in the genome.
    */
    
    int j = g.length();
    int c = s.length();
    double max = 0; 
    if (j < c)
    {
        return 0;
    }
    for (int a = 0; a <= j-c; a++)      /* Operation for identifing repetition */
    {
        string x = g.substr(a,c); 
        double h = calcSimScore(x,s);   /* Declaration of similarity value */
            
            if (max < h)
            {
                 max = h;               /* Declaring output value */
            }
    }
    return max;
}


int main()
{
    // Test 1
    // Expected output
    // 0.33
    cout << findBestSimScore("ATACGC", "ACT") << endl;
    
    // Test 2
    // Expected output
    // 1
    cout << findBestSimScore("ATACCC", "T") << endl;
    
    // Test 3
    // Expected output
    // 0.8
    cout << findBestSimScore("ATACCAGACCTTAGGAGCG", "AGATC") << endl;
    
    return 0;
}