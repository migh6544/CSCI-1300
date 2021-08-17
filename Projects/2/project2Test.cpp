#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"

using namespace std;


int main()
{
    Library myLib;
    myLib.readBooks("bookFile.txt");
    myLib.readRatings("ratingFile.txt");
    myLib.getRecommendations("User5");
}