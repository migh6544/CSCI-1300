// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 3 - Map Class

#include <iostream>
#include <string>
#include "Map.h"

using namespace std;


/* Defining functions/data members, setters and getters functionallity for Players.h */
Map::Map()
{
    
}

Map::Map(int row, int col, string type)
{
    locationRow = row;
    locationCol = col;
    locationType = type;
}

void Map::setLocationCol(int col)
{
    locationCol = col;
}

void Map::setLocationRow(int row)
{
    locationRow = row;
}

int Map::getLocationCol()
{
    return locationCol;
}

int Map::getLocationRow()
{
    return locationRow;
}

void Map::setLocationType(string type)
{
    locationType = type;
}
string Map::getLocationType()
{
    return locationType;
}