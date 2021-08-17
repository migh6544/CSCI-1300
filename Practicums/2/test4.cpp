/* This function converts a string from any-case to lowercase */
/*string upLow(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}*/

/* The functions takes a line of strings, looks for a specific character and splits
the line int to 2 individual strings stored in an array.*/
/*int split(string s, char c, string a[], int l)
{
    string(w) = "";
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != c)
        {
            w = w + s[i];
        }
        else if (w != "")
        {
            a[n] = w;
            n++;
            w = "";
        }
    }
    if(w != "")
    {
        a[n] = w;
        n++;
    }
    return n;
}*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int split(string s, char c, string a[], int l)
{
    string(w) = "";
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != c)
        {
            w = w + s[i];
        }
        else if (w != "")
        {
            a[n] = w;
            n++;
            w = "";
        }
    }
    if(w != "")
    {
        a[n] = w;
        n++;
    }
    return n;
}


float calcProduce(string fileName)
{
    ifstream inFile;
    string line = "";
    char dil = ',';
    string arr[3];
    int l = 0;
    inFile.open(fileName);
    if (inFile.is_open())
    {
        while (l < line.length() && getline(inFile, line))
        {
            if ( line != "")
            {
                
            }
        }
    }
    else
    {
        l = -1;
        return l;
    }
    inFile.close();
    return l;
}