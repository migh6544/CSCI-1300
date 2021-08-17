#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;


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
        while (numBooks < sizeBook && getline(inFile, line))
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

void Library::viewRatings(string userName, int Value)
{
    string Name = "";
    int position = 0;
    int Rating = 0;
    bool found = false;
    for(int i = 0; i < numUsers; i++)
    {
        Name = users[i].getUsername();
        if (Name == userName)
        {
            position = i;
            found = true;
        }
    }
    if (found == false)
    {
        cout << userName <<" does not exist." << endl;
    }
    else
    {
        cout << "Here are the books that " << userName << " rated" << endl;
        for (int j = 0; j < numBooks; j++)
        {
            Rating = users[position].getRatingAt(j);
            if (Rating != 0 && Rating >= Value)
            {
                cout << "Title : " << books[j].getTitle() << endl;
                cout << "Rating : " << Rating << endl;
                cout << "-----" << endl;
            }
            if (Rating == 0)
            {
                cout << userName <<" has not rated any books yet." << endl;
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
            rating += users[i].getRatingAt(position);                                       // Adding the values at the specified positions
            count++;
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
        if (upLow(authorName) == upLow(books[i].getAuthor()))                                 // Checking the conditions of user's names
        {
            position = i;
            count1++;
            for (int i = 0; i < numUsers; i++)
            {
                if (upLow(users[i].getUsername()) != "" && users[i].getRatingAt(position) != 0)       // Checking the conditions of user's names and values
                {
                    found++;
                    rating += users[i].getRatingAt(position);                                       // Adding the values at the specified positions
                    count++;
                }
                count2++;
            }
        }
    }
    if (found == 0)
    {
        return 0;
    }
    if (count1 == 0 || count2 == 0)
    {
        return -3;
    }
    avgRating = (double(rating)/double(count));
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
            if (upLow(userName) != upLow(users[i].getUsername()) && users[i].getUsername() == "")
            {
                users[i].setUsername(userName);
                numUsers++;
                return 1;
            }
            if (userName == users[i].getUsername())
            {
                return 0;
            }
        }
    }
}

/* This function takes in a new rating for a books object and updates its rating in the users array. */
int Library::checkOutBook(string userName, string bookTitle, int Rating)
{
    int positionUser = -1;
    int positionBook = -1;
    if (Rating < 0 || Rating > 5)
    {
        return -4;
    }
    for (int i = 0; i < numUsers; i++)
    {
         if (upLow(userName) == upLow(users[i].getUsername()))
            {
                positionUser = i;
            }
    }
    for (int i = 0; i < numBooks; i++)
    {
        if (upLow(bookTitle) == upLow(books[i].getTitle()))
        {
            positionBook = i;
            users[positionUser].setRatingAt(positionBook, Rating);
            return 1;
        }
    }
    if (positionBook == -1 || positionUser == -1)
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
    cout << "Here is the list of recommendations" << endl;
    for (int i = 0; i < numBooks; i++)
    {
        if (users[positionUser].getRatingAt(i) == 0 && users[positionMatch].getRatingAt(i) >= 3 && count < 5)
        {
            count++;
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
    if (count == 0)
    {
        cout << "There are no recommendations for " << userName << " at present." << endl;
    }
}


int main()
{
    return 0;
}