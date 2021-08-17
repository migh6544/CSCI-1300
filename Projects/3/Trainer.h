// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 3 - Trainer Class


#ifndef TRAINER_H
#define TRAINER_H
#include <iostream>
#include <string>
#include "Game.h"

using namespace std;


/* Defining the Trainer class and its list of function/data members */
class Trainer
{
    public:
        Trainer();
        void        setNumBadges(int);
        int         getNumBadges();
        void        setNumPokeBalls(int);
        int         getNumPokeBalls();
        void        setNumPoints(int);
        int         getNumPoints();
        void        setPokeList(Pokemon);
        Pokemon     getPokeList();
        void        setTrainerLocation(int, int);
        int         getTrainerLocationRow();
        int         getTrainerLocationCol();

    private:
        int             numBadges;
        int             numPokeBalls;
        int             numPoints;
        vector<Pokemon> pokeList;
        int             trainerLocation[2];
};
#endif