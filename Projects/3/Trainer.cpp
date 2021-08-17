// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 3 - Trainer Class

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "Game.h"
#include "Pokemon.h"
#include "Trainer.h"

using namespace std;



/* Defining functions/data members, setters and getters functionallity for Trainers.h */
Trainer::Trainer()
{
    numBadges = 0;
    numPokeBalls = 10;
    numPoints = 0;
    for (int i = 0; i < 2; i++)
    {
        trainerLocation[i] = 0;
    }
}

void Trainer::setNumBadges(int num)
{
    numBadges = numBadges + num;
}

int Trainer::getNumBadges()
{
    return numBadges;
}

void Trainer::setNumPokeBalls(int num)
{
    numPokeBalls = numPokeBalls + num;
}

int Trainer::getNumPokeBalls()
{
    return numPokeBalls;
}

void Trainer::setNumPoints(int num)
{
    numPoints = numPoints + num;
}

int Trainer::getNumPoints()
{
    return numPoints;
}

void Trainer::setPokeList(Pokemon add)
{
    pokeList.push_back(add);
}

Pokemon Trainer::getPokeList()
{
    cout << "Trainer Pokemon List:" << endl;
    for (int i = 0; i < pokeList.size(); i++)
    {
        cout << "---------------------------------" << endl;
        cout << "Name: " << pokeList[i].getPokeName() << endl;
        cout << "Health: " << pokeList[i].getPokeHealth() << endl;
        cout << "Attack: " << pokeList[i].getPokeAttack() << endl;
        cout << "Defense: " << pokeList[i].getPokeDefense() << endl;
        cout << "Speed: " << pokeList[i].getPokeSpeed() << endl;
        cout << "Max: " << pokeList[i].getPokeMax() << endl;
        cout << "Type: " << pokeList[i].getPokeType() << endl;
        cout << "Special: " << pokeList[i].getPokeSpecial() << endl;
        cout << "---------------------------------" << endl;
    }
}

void Trainer::setTrainerLocation(int row, int col)
{
    if (trainerLocation[0] + row < 25 && trainerLocation[1] + col < 16)
    {
        trainerLocation[0] += row;
        trainerLocation[1] += col;
    }
}

int Trainer::getTrainerLocationRow()
{
    return trainerLocation[0];
}

int Trainer::getTrainerLocationCol()
{
    return trainerLocation[1];
}