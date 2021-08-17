// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 3 - Map Class


#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>

using namespace std;


/* Defining the Map class and its list of function/data members */
class Map
{
    public:
        Map();
        Map(string list[int, int);
        void    setLocationCol(int);
        void    setLocationRow(int);
        int     getLocationCol();
        int     getLocationRow();
        void    setLocationRow(string);
        void    setLocationType(string);
        string  getLocationType();
        
    private:
        string        

};
#endif