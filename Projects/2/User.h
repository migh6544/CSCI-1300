// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Homework 7 - HeaderFile 1

#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

using namespace std;


/* Defining the class and its list of function/data members */
class User
{
    public:
        User();
        User(string, int a[], int);
        string  getUsername();
        void    setUsername(string);
        int     getRatingAt(int);
        bool    setRatingAt(int,int);
        int     getNumRatings();
        void    setNumRatings(int);
        int     getSize();
    
    private:
        string  userName;
        int     ratings[50];
        int     numRatings;
        int     size;
};
#endif