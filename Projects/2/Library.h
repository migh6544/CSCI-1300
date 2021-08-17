// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 2 - HeaderFile - Library

#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
#include "User.h"
#include "Book.h"

using namespace std;


/* Defining the class and its list of function/data members */
class Library
{
    private:
        int     sizeBook;
        int     sizeUser;
        Book    books[50];
        User    users[100];
        int     numBooks;
        int     numUsers;
        
    public:
        Library();
        int     getSizeBook();
        int     getSizeUser();
        int     getNumBooks();
        int     getNumUsers();
        int     readBooks(string);
        void    printAllBooks();
        void    printBooksByAuthor(string);
        int     readRatings(string);
        int     getRating(string, string);
        int     getCountReadBooks(string);
        void    viewRatings(string, int);
        double  calcAvgRating(string);
        double  calcAvgRatingByAuthor(string);
        int     addUser(string);
        int     checkOutBook(string, string, int);
        void    getRecommendations(string);
};
#endif