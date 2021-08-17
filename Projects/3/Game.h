// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 3 - Game Class


#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "Pokemon.h"
#include "Trainer.h"

using namespace std;



/* Defining the Game class and its list of function/data members */
class Game
{
    public:
        Game();
        void    setPlayerName(string);
        string  getPlayerName();
        void    setPlayerSelec(int);
        int     getPlayerSelec();
        void    setWorldMap(string);
        void    getWorldMap();
        void    setPokemon(string);
        Pokemon getPokeAt(int);
        void    setPlayer(int);
        void    setPlayerPokeList(Pokemon, int);
        void    getPlayerPokeList();
        void    setActivePoke(int);
        void    getActivePoke();
        void    setTrainers();
        void    setWildPokemon();
        void    getWildPokemon();
        void    getGamePlay();

    private:
        vector<Pokemon>     allPokeList;
        Pokemon             wildPokeList[20];
        Pokemon             playerPokeList[6];
        vector<Pokemon>     playerPokeDex;
        Trainer             player;
        Pokemon             activePoke;
        Trainer             allTrainersList[16];
        int                 playerSelec;
        string              playerName;
        string              worldMap[25][16];
};
#endif