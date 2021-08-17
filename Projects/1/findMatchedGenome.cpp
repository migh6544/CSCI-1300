// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 1 - Problem 6

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


void findMatchedGenome(string g1, string g2, string g3, string s1)
{
    /*
    The functions take in three genomes and a sequence ( all strings) and prints
    the list of matched genomes and displays the similarities.
    */
    
    if (g1.length() == 0 || g2.length() == 0 || g3.length() == 0 || s1.length() == 0)
    /* Stating output for empty input */
    {  
        cout << "Genomes or sequence is empty." << endl;
    }
    else if ((g1.length() != g2.length()) || (g1.length() != g3.length()) || (g2.length() != g3.length()))
    /* Stating output for different lengths */
    {  
        cout << "Lengths of genomes are different." << endl;
    }
    else
    {
    double a = findBestSimScore(g1, s1);    /* Calculating similarity score */
    double b = findBestSimScore(g2, s1);    /* Calculating similarity score */
    double c = findBestSimScore(g3, s1);    /* Calculating similarity score */
    
        if (a >= b && a >= c)               /* Declaring output value */
        {
            cout << "Genome 1 is the best match." <<endl;
        }      
        if (b >= a && b >= c)               /* Declaring output value */
        {
            cout << "Genome 2 is the best match." <<endl;
        }
        if (c >= a && c >= b)               /* Declaring output value */
        {
            cout << "Genome 3 is the best match." <<endl;
        }
    }
}


int main()
{
    // Test 1
    // Expected output
    // 0.33
    findMatchedGenome("AATGTTTCAC", "GACCGACTAA", "AAGGTGCTCC", "TACTA");
    cout << endl;
    
    // Test 2
    // Expected output
    // 1
    findMatchedGenome("AACT", "AACT", "AATG", "AACT");
    cout << endl;
        
    // Test 3
    // Expected output
    // 0.8
    findMatchedGenome("AACTC", "AACT", "AATG", "AACT");
    cout << endl;
    
    // Test 4
    // Expected output
    // 0.8
    findMatchedGenome("AACTC", "", "AATG", "AACT");
    cout << endl;
    
    return 0;
}