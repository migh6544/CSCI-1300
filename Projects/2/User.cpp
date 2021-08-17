// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Homework 7 - SourceFile 1

#include <iostream>
#include <string>
#include "User.h"

using namespace std;


/*
Defining constructors, setters, getters and functions/data members for user.h
*/

/* Intializing all data-members' values */
User::User()
{
    userName = "";
    numRatings = 0;
    size = 50;
    for (int i = 0; i < size; i++)
    {
        ratings[i] = 0;
    }
}
/* Linking input varubles to data-members */
User::User(string name, int list[], int count)
{
    userName = name;
    numRatings = count;
    for (int i = 0; i < 50; i++)
    {
        if (i < numRatings)
        {
            ratings[i] = list[i];
        }
        else 
        {
        ratings[i] = 0;
        }
    }
}
/* Setting user-name value */
void User::setUsername(string name)
{
    userName = name;
}
string User::getUsername()
{
    return userName;
}
/* Setting ratings values at each index value */
bool User::setRatingAt(int indx,int value)
{
   if (value < 0 || value > 5 || indx < 0 || indx >= 50)
   {
        return false;
   }
   ratings[indx] = value;
   return true;
}
int User::getRatingAt(int indx)
{
    if (indx < 0 || indx >= 50)
    {
        return -1;
    }
    return ratings[indx];
    
}
/* Setting the count of ratings */
void User::setNumRatings(int value)
{
    numRatings = value;
}
int User::getNumRatings()
{
    return numRatings;
}
int User::getSize()
{
    return size;
}