// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 3 - Pokemon Class

#include <iostream>
#include <fstream>
#include <string>
#include "Pokemon.h"
#include "Game.h"

using namespace std;



/* Defining functions/data members, setters and getters functionallity for Pokemon.h */
Pokemon::Pokemon()
{
    pokeName = "";
    pokeHealth = 0;
    pokeAttack = 0;
    pokeDefense = 0;
    pokeSpeed = 0;
    pokeMax = 0;
    pokeType = "None";
    pokeSpecial = "None";
    for (int i = 0; i < 2; i++)
    {
        pokeLocation[i] = 0;
    }
}

void Pokemon::setPokeName(string name)
{
    pokeName = name;
}

void Pokemon::setPokeHealth(int value)
{
    pokeHealth = value;
}

void Pokemon::setPokeAttack(int value)
{
    pokeAttack = value;
}

void Pokemon::setPokeDefense(int value)
{
    pokeDefense = value;
}

void Pokemon::setPokeSpeed(int value)
{
    pokeSpeed = value;
}

void Pokemon::setPokeMax(int value)
{
    pokeMax = value;
}

void Pokemon::setPokeSpecial(string ability)
{
    pokeSpecial = ability;
}

void Pokemon::setPokeType(string kind)
{
    pokeType = kind;
}

string Pokemon::getPokeName()
{
    return pokeName;
}

int Pokemon::getPokeHealth()
{
    return pokeHealth;
}

int Pokemon::getPokeAttack()
{
    return pokeAttack;
}

int Pokemon::getPokeDefense()
{
    return pokeDefense;
}

int Pokemon::getPokeSpeed()
{
    return pokeSpeed;
}

int Pokemon::getPokeMax()
{
    return pokeMax;
}

string Pokemon::getPokeType()
{
    return pokeType;
}

string Pokemon::getPokeSpecial()
{
    return pokeSpecial;
}

void Pokemon::setPokeLocation(int row, int col)
{
    pokeLocation[0] = row;
    pokeLocation[1] = col;
}

int Pokemon::getPokeLocationRow()
{
    return pokeLocation[0];
}

int Pokemon::getPokeLocationCol()
{
    return pokeLocation[1];
}