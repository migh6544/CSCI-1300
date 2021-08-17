// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 2 - DriverFile

#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"
#include <cmath>

using namespace std;


/* This function presents the user with a menu t choose from to intiate the program 
and its operation based on the users' choice. */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Read ratings" << endl;
    cout << "3. Print all books" << endl;
    cout << "4. Print books by author" << endl;
    cout << "5. Get rating" << endl;
    cout << "6. Find number of books user rated" << endl;
    cout << "7. View ratings" << endl;
    cout << "8. Get average rating" << endl;
    cout << "9. Get average rating by author" << endl;
    cout << "10. Add a user" << endl;
    cout << "11. Checkout a book" << endl;
    cout << "12. Get recommendations" << endl;
    cout << "13. Quit" << endl;
}

/* The functions takes a line of strings, looks for a specific character and splits
the line int to 2 individual strings stored in an array.*/
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

/* This function converts a string from any-case to lowercase */
string upLow(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}

/*
Defining constructors, setters, getters and functions/data members for Library.h
*/

/* Intializing all data-members' values */
Library::Library()
{
    sizeUser = 100;
    sizeBook = 50;
    numBooks = 0;
    numUsers = 0;
}

int Library::getSizeBook()
{
    return sizeBook;
}

int Library::getSizeUser()
{
    return sizeUser;
}

int Library::getNumBooks()
{
    return numBooks;
}

int Library::getNumUsers()
{
    return numUsers;
}

/* The function reads from a text file and stores its contents in an array that 
organizes them and returns the number of items it organized. */
int Library::readBooks(string fileName)
{
    /*
    Algorithm:
    1- Check if you can open the file
    2- Open the file
    3- Establish a stream
    4- Read the file line by line
    5- Split the line into 2 strings
    6- Store the strings in an array
    7- Assign the strings to existing arrays
    8- Close the stream
    9- End function
    */
    
    ifstream inFile;
    string line = "";
    
    inFile.open(fileName);
    if (numBooks == sizeBook)
    {
        return -2;
    }
    if (inFile.is_open())
    {
        if (numBooks < sizeBook)
        {
            while (getline(inFile, line))
            {
                if ( line != "")
                {
                string a[2];
                split(line, ',', a, 2);
                string title = a[0];
                string author = a[1];
                Book temp(author, title);
                books[numBooks] = temp;
                numBooks++;
                }
            }
        }
    }
    else
    {
        return -1;
    }
    inFile.close();
    return numBooks;
}

/* The function takes in a string of books and the number of books. The function
then lists the books with the name of each book's author, line by line.*/
void Library::printAllBooks()
{
    if (numBooks <= 0)
    {
        cout << "No books are stored" << endl;
    }
    else if (numBooks > 0)
    {
        cout << "Here is a list of books" << endl;
        for ( int i = 0; i < numBooks; i++)
        {
            books[0] = books[i];
            cout << books[i].getTitle() << " by ";
            cout << books[i].getAuthor() << endl;
        }
    }
}

/* The function takes in a string of book titles, the number of books and an author's name.
The function then prints a list of the books by the specified author. If there are no books, 
it prints a message leting the user know, and if there are no books by that specific author
it prints a message letting the user know.*/
void Library::printBooksByAuthor(string authorName)
{
    int count = 0;
    if (numBooks == 0)
    {
        cout << "No books are stored" << endl;
    }
    if (numBooks != 0)
    {

        for (int i = 0; i < numBooks; i++)
        {
            if (books[i].getAuthor() == authorName)
            {
                if(count == 0)
                {
                    cout << "Here is a list of books by " << authorName << endl;
                }
                cout << books[i].getTitle() << endl;
                count++;
            }
        }
    }
    if (numBooks != 0 && count == 0)
    {
        cout << "There are no books by " << authorName << endl;
    }
}

/* The function reads from a text file names of users and their ratings of books, 
then stores eache user and their ratings of each book an array, then 
returns the number of users it counted. If the file can not be read or the lines
have empty values, the function return a number indicating the error meesage.*/
int Library::readRatings(string fileName)
{
    ifstream inFile;
    string line = "";
    inFile.open(fileName);
    if (numUsers == sizeUser)
    {
        return -2;
    }
    if (inFile.is_open())
    {
        while (numUsers < sizeUser && getline(inFile, line))
        {
            string a[51];
            if (line != "")
            {
                int n = split(line, ',', a, 51);
                string name = a[0];
                int rates = (n-1);
                int temp[50];
                for (int j = 1; j < n; j++) 
                {
                    temp[j-1] = stoi(a[j]);
                }
                User tempUser = User(name, temp, rates);
                users[numUsers] = tempUser;
                numUsers++;
            }
        }
    }
    else
    {
        return -1;
        return numUsers;
    }
    inFile.close();
    return numUsers;
}

/* This function looks at the location of a book in an array and uses the location
to refrence a rating of a user in a different array, to return the rating of the
same book from the intial array. */
int Library::getRating(string userName, string bookTitle)
{
    int position = 0;
    int rating = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < numBooks; i++)
    {
        if (upLow(bookTitle) == upLow(books[i].getTitle()))
        {
            position = i;
            count1++;
        }
    }
    for (int i = 0; i < numUsers; i++)
    {
        if (upLow(userName) == upLow(users[i].getUsername()))
        {
            rating = users[i].getRatingAt(position);
            count2++;
        }
    }
    if (count1 == 0 || count2 == 0)
    {
        return -3;
    }
    return rating;
}

/* This function calculates the number of ratings each user has recorded. */
int Library::getCountReadBooks(string userName)
{
    int count = 0;
    int found = 0;
    for (int i = 0; i < numUsers; i++)
    {
        if (upLow(userName) == upLow(users[i].getUsername()))       // Checking the conditions of user's names
        {
            found++;
            for ( int j = 0; j < numBooks; j++)
            {
                if (users[i].getRatingAt(j) > 0)                    // Getting the value in the specified position
                {
                    count++;
                }
            }
        }
    }
    if (found == 0 || numUsers == 0 || numBooks == 0)
    {
        return -3;
    }
    return count;
}
/* This function checks if a specific user has rated a book at a specific minimum value. */
void Library::viewRatings(string userName, int Value)
{
    string Name = "";
    int position = 0;
    int Rating = 0;
    int count = 0;
    bool found = false;
    for(int i = 0; i < numUsers; i++)
    {
        Name = users[i].getUsername();
        if (upLow(Name) == upLow(userName))
        {
            found = true;
            position = i;
            break;
        }    
    }
    if (found == false)
    {
        cout << userName <<" does not exist." << endl;
    }
    else
    {
        for (int j = 0; j < numBooks; j++)
        {
            Rating = users[position].getRatingAt(j);
            if (Rating > 0 && Rating < 6)
            {
                count++;
            }
        }
        if (count == 0)
        {
            cout << userName <<" has not rated any books yet." << endl;
        }
        else
        {
            cout << "Here are the books that " << userName << " rated" << endl;
            for (int k = 0; k < numBooks; k++)
            {
                if (users[position].getRatingAt(k) >= Value)
                {
                    cout << "Title : " << books[k].getTitle() << endl;
                    cout << "Rating : " << users[position].getRatingAt(k) << endl;
                    cout << "-----" << endl;
                }
            }
        }
    }
}

/* This function calculates the average rating a book receives based on the user's total ratings.*/
double Library::calcAvgRating(string bookTitle)
{
    int position = 0;
    int rating = 0;
    int count = 0;
    int found = 0;
    int count1 = 0;
    int count2 = 0;
    double avgRating = 0;
    if (numUsers == 0)
    {
        return -3;
    }
    for (int i = 0; i < numBooks; i++)
    {
        if (upLow(bookTitle) == upLow(books[i].getTitle()))                                 // Checking the conditions of user's names
        {
            position = i;
            count1++;
        }
    }
    for (int i = 0; i < numUsers; i++)
    {
        if (upLow(users[i].getUsername()) != "" && users[i].getRatingAt(position) != 0)       // Checking the conditions of user's names and values
        {
            found++;
            count++;
            rating += users[i].getRatingAt(position);                                       // Adding the values at the specified positions
        }
        count2++;
    }
    if (found == 0)
    {
        return 0;
    }
    if (count1 == 0 || count2 == 0)
    {
        return -3;
    }
    avgRating = (double(rating)/count);
    return avgRating;
}

/* This function calculates the average rating a author provides based on the total ratings.*/
double Library::calcAvgRatingByAuthor(string authorName)
{
    int position = 0;
    int rating = 0;
    int ratingUpdate = 0;
    int authorCheck = 0;
    double avgRating = 0;
    if (numUsers == 0)
    {
        return -3;
    }
    for (int i = 0; i < numBooks; i++)
    {
        if (upLow(authorName) == upLow(books[i].getAuthor()))                                 // Checking the conditions of user's names
        {
            position = i;
            authorCheck++;
            for (int j = 0; j < numUsers; j++)
            {
                if (upLow(users[j].getUsername()) != "" && users[j].getRatingAt(position) != 0)       // Checking the conditions of user's names and values
                {
                    rating += users[j].getRatingAt(position);                                       // Adding the values at the specified positions
                    ratingUpdate++;
                }
            }
        }
    }
    if (authorCheck == 0 || numUsers == 0)
    {
        return -3;
    }
    if (ratingUpdate == 0)
    {
        return 0;
    }
    avgRating = (double(rating)/double(ratingUpdate));
    return avgRating;
}

/* This function adds an object to the users array if the array is not full and the username is new. */
int Library::addUser(string userName)
{
    if (numUsers >= sizeUser)
    {
        return -2;
    }
    if (userName != "")
    {
        for (int i = 0; i < sizeUser; i++)
        {
            if (upLow(userName) == upLow(users[i].getUsername()))
            {
                return 0;
            }
            if (upLow(userName) != upLow(users[i].getUsername()) && users[i].getUsername() == "")
            {
                users[i].setUsername(userName);
                numUsers++;
                return 1;
            }
        }
    }
}

/* This function takes in a new rating for a books object and updates its rating in the users array. */
int Library::checkOutBook(string userName, string bookTitle, int Rating)
{
    int position = -1;
    int position1 = 0;
    int count = 0;
    if (Rating < 0 || Rating > 5)
    {
        return -4;
    }
    if (Rating >= 0 && Rating <= 5)
    {
        for (int i = 0; i < numUsers; i++)
        {
             if (upLow(userName) == upLow(users[i].getUsername()))
            {
                position1 = i;
                count++;
                break;
            }
        }
        if(count == 0)
        {
            return -3;
        }
        for (int i = 0; i < numBooks; i++)
        {
            if (upLow(bookTitle) == upLow(books[i].getTitle()))
            {
                users[position1].setRatingAt(i, Rating);
                return 1;
            }
        }
    }
    if (position = -1)
    {
        return -3;
    }
}

/* This function claculates the best match of books for a user based on their ratings in relation
to other users' ratings. */
void Library::getRecommendations(string userName)
{
    int SSD = 0;
    int positionUser = 0;
    int positionMatch = 0;
    int calc = 0;
    int minSSD = 1111;
    int count = 0;
    int userCheck = 0;
    int printLimit = 0;
    for (int i = 0; i < numUsers; i++)
    {
        if (upLow(userName) == upLow(users[i].getUsername()))
        {
            userCheck++;
        }
    }
    if (userCheck == 0)
    {
        cout << userName << " does not exist." <<endl;
    }
    if (userCheck > 0)
    {
        for (int i = 0; i < numUsers; i++)
        {
            if (upLow(userName) == upLow(users[i].getUsername()))
            {
                positionUser = i;
            }
        }
        for (int i = 0; i < numUsers; i++)
        {
            SSD = 0;
            if (upLow(userName) != upLow(users[i].getUsername()))
            {
                if (getCountReadBooks(users[i].getUsername()) != 0)
                {
                    for (int j = 0; j < numBooks; j++)
                    {
                        calc = users[positionUser].getRatingAt(j) - users[i].getRatingAt(j);
                        SSD += pow(calc, 2);
                    }
                }
                if (minSSD > SSD && SSD != 0)
                {
                    minSSD = SSD;
                    positionMatch = i;
                }
            }
        }
        for (int i = 0; i < numBooks; i++)
        {
            if (users[positionUser].getRatingAt(i) == 0 && users[positionMatch].getRatingAt(i) >= 3)
            {
                count++;
            }
        }
        if(count > 5)
        {
            count = 5;
        }
        if (count == 0)
        {
            cout << "There are no recommendations for " << userName << " at present." << endl;
        }
        if (count !=0)
        {
            cout << "Here is the list of recommendations" << endl;
            for (int i = 0; i < numBooks; i++)
            {
                if (users[positionUser].getRatingAt(i) == 0 && users[positionMatch].getRatingAt(i) >= 3 && printLimit < 5)
                {
                    cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
                    printLimit++;
                }
            }
        }
    }
}


/* The function takes in a value based on the input choice from the printed menu,
then returns an output unique to each selection.*/
int output()
{
    double count;
    int option;
    Book books[50];
    User users[100];
    int numBooks = 0;
    int numUsers = 0;
    int sizeBook = 50;
    int sizeUser = 100;
    int minRating = 0;
    int newRating = 0;
    string input;
    string input1;
    string userName;
    string fileName;
    string bookTitle;
    string authorName;
    bool choice = true;
    Library library;
    while (choice == true)
    {
        displayMenu();
        cin >> option;
        switch(option)
        {
                case 1:
                    cout << "Enter a book file name:" << endl;
                    cin >> input;
                    fileName = input;
                    count = library.readBooks(fileName);
                    if (count == -1)
                    {
                        cout << "No books saved to the database." << endl;
                    }
                    if (count == -2)
                    {
                        cout << "Database is already full. No books were added." << endl;
                    }
                    if (count == sizeBook)
                    {
                        cout << "Database is full. Some books may have not been added." << endl;
                         numBooks = count;
                    }
                    if (count != -1 && count != -2 && count != sizeBook)
                    {
                        cout << "Total books in the database: " << count << endl;
                        numBooks = count;
                    }
                    cout << endl;
                    break;
                    
                case 2:
                    cout << "Enter a user file name:" << endl;
                    cin >> input;
                    fileName = input;
                    count = library.readRatings(fileName);
                    if (count == -1)
                    {
                        cout << "No users saved to the database." << endl;
                    }
                    if (count == -2)
                    {
                        cout << "Database is already full. No users were added." << endl;
                    }
                    if (count == sizeUser)
                    {
                        cout << "Database is full. Some users may have not been added." << endl;
                         numUsers = count;
                    }
                    if (count != -1 && count != -2 && count != sizeUser)
                    {
                        cout << "Total users in the database: " << count << endl;
                        numUsers = count;
                    }
                    cout << endl;
                    break;
                
                case 3:
                    if (library.getNumBooks() == 0 || library.getNumUsers() == 0)
                    {
                        cout << "Database has not been fully initialized." << endl;
                    }
                    else
                    {
                        library.printAllBooks();
                    }
                    cout << endl;
                    break;
                
                case 4:
                    if (library.getNumBooks() == 0 || library.getNumUsers() == 0)
                    {
                        cout << "Database has not been fully initialized." << endl;
                    }
                    else
                    {
                        cout << "Enter an author name:" << endl;
                        cin.ignore();
                        getline(cin, authorName);
                        library.printBooksByAuthor(authorName);
                    }
                    cout << endl;
                    break;
                    
                case 5:
                    if (library.getNumBooks() == 0 || library.getNumUsers() == 0)
                    {
                        cout << "Database has not been fully initialized." << endl;
                    }
                    cout << "Enter a user name:" << endl;
                    cin.ignore();
                    getline(cin, userName);
                    cout << "Enter a book title:" << endl;
                    getline(cin, bookTitle);
                    count = library.getRating(userName, bookTitle);
                    if (count == -3)
                    {
                        cout << userName << " or " << bookTitle << " does not exist." << endl;
                    }
                    if (count == 0)
                    {
                        cout << userName << " has not rated " << bookTitle << endl;
                    }
                    if (count != -3 && count != 0)
                    {
                        cout << userName << " rated " << bookTitle << " with " << count << endl;
                    }
                    cout << endl;
                    break;
                    
                case 6:
                    if (library.getNumBooks() == 0 || library.getNumUsers() == 0)
                    {
                        cout << "Database has not been fully initialized." << endl;
                    }
                    else
                    {
                        cout << "Enter a user name:" << endl;
                        cin.ignore();
                        getline(cin, userName);
                        count = library.getCountReadBooks(userName);
                        if (count == -3)
                        {
                            cout << userName << " does not exist." << endl;
                        }
                        if (count == 0)
                        {
                            cout << userName << " has not rated any books." << endl;
                        }
                        if (count != -3 && count != 0)
                        {
                            cout << userName << " rated " << count << " books." << endl;
                        }
                    }
                    cout << endl;
                    break;
                    
                case 7:
                    if (library.getNumBooks() == 0 || library.getNumUsers() == 0)
                    {
                        cout << "Database has not been fully initialized." << endl;
                    }
                    else
                    {
                        cout << "Enter a user name:" << endl;
                        cin >> userName;
                        cout << "Enter a minimum rating:" << endl;
                        cin >> minRating;
                        library.viewRatings(userName, minRating);
                    }
                    cout << endl;
                    break;
                    
                case 8:
                    if (library.getNumBooks() == 0 || library.getNumUsers() == 0)
                    {
                        cout << "Database has not been fully initialized." << endl;
                    }
                    else
                    {
                        cout << "Enter a book title:" << endl;
                        cin.ignore();
                        getline(cin, bookTitle);
                        count = library.calcAvgRating(bookTitle);
                        if (library.calcAvgRating(bookTitle) == -3)
                        {
                            cout << bookTitle << " does not exist." << endl;
                        }
                        else
                        {
                            if (library.calcAvgRating(bookTitle) != -3)
                            {
                                cout << "The average rating for " << bookTitle << " is " << count << endl;
                            }
                        }
                    }

                    cout << endl;
                    break;
                    
                case 9:
                    if (library.getNumBooks() == 0 || library.getNumUsers() == 0)
                    {
                        cout << "Database has not been fully initialized." << endl;
                    }
                    else
                    {
                        cout << "Enter an author name:" << endl;
                        cin.ignore();
                        getline(cin, authorName);
                        library.calcAvgRatingByAuthor(authorName);
                        if (library.calcAvgRatingByAuthor(authorName) != -3)
                        {
                            cout << "The average rating by " << authorName << " is " << library.calcAvgRatingByAuthor(authorName) << endl;
                        }
                        else
                        {
                            cout << authorName << " does not exist." << endl;
                        }
                    }
                    cout << endl;
                    break;
                    
                case 10:
                    cout << "Enter a user name:" << endl;
                    cin.ignore();
                    getline(cin, userName);
                    count = library.addUser(userName);
                    if (count == 1)
                    {
                        cout << "Welcome to the library " << userName << endl;
                    }
                    if (count == 0)
                    {
                        cout << userName << " already exists in the database." << endl;
                    }
                    if (count == -2)
                    {
                        cout << "Database is already full. " << userName << " was not added." << endl;
                    }
                    cout << endl;
                    break;
                    
                case 11:
                    if (library.getNumBooks() == 0 || library.getNumUsers() == 0)
                    {
                        cout << "Database has not been fully initialized." << endl;
                    }
                    else
                    {
                        cout << "Enter a user name:" << endl;
                        cin.ignore();
                        getline(cin, userName);
                        cout << "Enter a book title:" << endl;
                        getline(cin, bookTitle);
                        cout << "Enter a new rating:" << endl;
                        cin >> newRating;
                        library.checkOutBook(userName, bookTitle, newRating);
                        if (library.checkOutBook(userName, bookTitle, newRating) == 1)
                        {
                            cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                        }
                        else
                        {
                            if (library.checkOutBook(userName, bookTitle, newRating) == -4)
                            {
                                cout << newRating << " is not valid." << endl;
                            }
                            if (library.checkOutBook(userName, bookTitle, newRating) == -3)
                            {
                                cout << userName << " or " << bookTitle << " does not exist." << endl;
                            }
                        }
                    }
                    cout << endl;
                    break;
                    
                case 12:
                    if (library.getNumBooks() == 0 || library.getNumUsers() == 0)
                    {
                        cout << "Database has not been fully initialized." << endl;
                    }
                    else
                    {
                        cout << "Enter a user name:" << endl;
                        cin.ignore();
                        getline(cin, userName);
                        library.getRecommendations(userName);
                    }
                    cout << endl;
                    break;
                    
                case 13:
                    cout << "Good bye!" << endl;
                    return 0;
                    
                default:
                    if (option < 1 || option > 6)
                    {
                        cout << "Invalid input." << endl;
                    }
                    cout << endl;
        }
    }
}


/*
Algorithm:
1- Present Menu to user
2- Capture selection from user
3- Select run based on user input
4- Display message based on run
5- Present Menu to user until they Quit
6- End programme
*/

int main()
{
    output();
    return 0;
}