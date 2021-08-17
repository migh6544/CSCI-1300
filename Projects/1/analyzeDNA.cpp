// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 1 - Problem 7

#include <iostream>
#include <math.h>
#include <string>

using namespace std;


void showMenu()                             /* Show menu function */
{
    cout << "Select a numerical option:" << endl;
    cout << "=== menu ===" << endl;
    cout << "1. Find similarity score" << endl;
    cout << "2. Find the best similarity score" << endl;
    cout << "3. Analyze the genome sequences" << endl;
    cout << "4. Quit" << endl;
}


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
    /* 
    Algorithem: 
    1 - Show menu
    2 - Capture selection
    3 - Execute operation based on selection
    4 - Loop where applicable
    5 - End program
    */
    
    string sq1, sq2, g, s, g1, g2, g3, s1;
    double k, max;
    int z = 0;

    while (z != 4)                  /* Setting loop for operation */
    {
    showMenu();
    cin >> z;

        switch (z)
        {   
            case 1:
                z == 1,         /* Option 1. Calculate similarity score */
                cout << "Enter sequence 1:" << endl;
                cin  >> sq1;
                cout << "Enter sequence 2:" << endl;
                cin  >> sq2;
                k = calcSimScore( sq1, sq2);
                cout << "Similarity score: " << k << endl;
                break;
            
            case 2:             /* Option 2. Find the best similarity score */
                z == 2,
                cout << "Enter genome:" << endl;
                cin  >> g;
                cout << "Enter sequence:" << endl;
                cin  >> s;
                max = findBestSimScore(g, s);
                cout << "Best similarity score: " << max << endl;
                break;
    
            case 3:             /* Option 3. Analyze the genome sequences */
                z == 3,
                cout << "Enter genome 1:" << endl;
                cin  >> g1;
                cout << "Enter genome 2:" << endl;
                cin  >> g2;
                cout << "Enter genome 3:" << endl;
                cin  >> g3;
                cout << "Enter sequence:" << endl;
                cin  >> s1;
                findMatchedGenome( g1, g2, g3, s1);
                break;
                
            case 4:             /* Otion 4. Quit */
                z == 4,
                cout << "Good bye!" << endl;
                break;;
                
            default:            /* All other invalid input values */
                cout << "Invalid option." << endl;
                break;
        }
    }
    return 0;
}