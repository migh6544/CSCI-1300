// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 3 - Pokemon Class


#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>

using namespace std;


/* Defining the Pokemon class and its list of function/data members */
class Pokemon
{
    public:
        Pokemon();
        void    setPokeName(string);
        string  getPokeName();
        void    setPokeHealth(int);
        int     getPokeHealth();
        void    setPokeAttack(int);
        int     getPokeAttack();
        void    setPokeDefense(int);
        int     getPokeDefense();
        void    setPokeSpeed(int);
        int     getPokeSpeed();
        void    setPokeMax(int);
        int     getPokeMax();
        void    setPokeType(string);
        string  getPokeType();
        void    setPokeSpecial(string);
        string  getPokeSpecial();
        void    setPokeLocation(int, int);
        int     getPokeLocationRow();
        int     getPokeLocationCol();

    private:
        string  pokeName;
        int     pokeHealth;
        int     pokeAttack;
        int     pokeDefense;
        int     pokeSpeed;
        int     pokeMax;
        string  pokeType;
        string  pokeSpecial;
        int     pokeLocation[2];
};
#endif