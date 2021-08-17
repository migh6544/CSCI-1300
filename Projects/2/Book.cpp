// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Homework 6 - SourceFile 2

#include <iostream>
#include "Book.h"

using namespace std;


/* Defining functions/data members, setters and getters functionallity for planet.h */
Book::Book()
{
    bookTitle = "";
    bookAuthor = "";
}
Book::Book(string title, string author)
{
    bookTitle = title;
    bookAuthor = author;
}
string Book::getTitle()
{
    return bookTitle;
}
void Book::setTitle(string title)
{
    bookTitle = title;
}
string Book::getAuthor()
{
    return bookAuthor;
}
void Book::setAuthor(string author)
{
    bookAuthor = author;
}