// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Homework 6 - HeaderFile 2

#ifndef BOOK_H
#define BOOK_H
#include <iostream>

using namespace std;


/* Defining the class and its list of function/data members */
class Book
{
    public:
    Book();
    Book(string, string);
    string getTitle();
    void setTitle(string);
    string getAuthor();
    void setAuthor(string);
    
    private:
    string bookTitle;
    string bookAuthor;
};
#endif