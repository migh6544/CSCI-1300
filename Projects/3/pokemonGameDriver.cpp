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



/*
Algorithm:

(Game Skeleton)
- Open map and pokemon files
- Import information from files and sort accourdingly
- Initialize map locations and pokemon assignments
- Randomize wild pokemon assignment to locations within game parameters
- Print intro message
- Capture player name
- Print customized message and game menu
- Capture player's selection

(Selction Skeleton)
<Travel>
- Move player accourding to map parameters
- Update classes data members accourding to travel outcome
<Rest>
- Update pokemon stats
- Reduce player's number of PokeBalls by one
<Try Your Luck>
- Search map, 7x7 only, for wild pokemon in all directions
- Update and print player's pokemon list accourding to search outcome
<Quit The Game>
- End the game

(Engine Skeleton)
- Print populated map tp player, 7x7 only
- Print number of PokeBalls, list of Pokemon and their stats
- Print Game Menu
- Capture menu selection
- Execute functions accourding to selection choice

(Interaction Skeleton)
<Wild Pokemon Encounter>
- Search map for wild pokemon, 2x2 only, in all directions
- Print wild and player's active pokemon info/stats
- Print Wild Ecounter Menu
- Capture player's selection
    [Firght]
    - Calculate count of player's  wild pokemon encounter 
    - Calculate chances of wild pokemon joining the player's team
    - Print encounter info
    - Execute calculations and operation bsed on encounter
    - Print encounter outcome info
    - Update classes data members accourding to outcome results
    [Switch]
    - Present switch menu and list of player's pokemon
    - Capture player's pokemon selection
    - Print active pokemon updated info and stats
    - Print Wild Ecounter Menu
    [Run]
    - Calculate player's escape chances
    - Execute run operation based on calculation results
    - Update classes data members accourdingly
    - Move player to closest Pokemon center accourding to outcome
    - Print Pokedex List Menu
    - Capture player's menu selection
    - Update player's pokemon list, 6 only, and classes data members accourdingly
    - Print players active pokemon menu
<Trainer Pokemon Encounter>
- Search map for Gym, 7x7 only, in all directions
- Print opponent's and player's active pokemon info/stats
- Print Trainer Ecounter Menu
- Capture player's selection
- Calculate fight outcome
- Execute calculations and operation bsed on encounter
- Print encounter outcome info
- Update classes data members accourding to outcome results

{Repeat as needed within game parameters}
{Game ends if players quit, collects 6 Badges or collects 8 different pokemon types}
*/



int main()
{
    srand(time(0));
    string name = "";
    int choice = 0;
    Game test;
    cout << endl;
    cout << "---------------" << endl;
    cout << "Welcome to Pokémon!" << endl;
    cout << "Please state your name:" << endl;
    cin >> name;
    test.setPlayerName(name);
    cout << "---------------" << endl;
    cout << "Welcome, "<< test.getPlayerName() << "!" << endl;
    cout << endl;
    cout << "Before you can begin your Pokémon adventure," << endl;
    cout << "you must choose a starting Pokémon, courtesy of the Professor." << endl;
    cout << endl;
    bool check = true;
    while (check == true)
    {
        cout << "Please choose from the following Pokémon:" << endl;
        cout << "1. Bulbasaur" << endl;
        cout << "2. Charmander" << endl;
        cout << "3. Squirtle" << endl;
        cout << "4. Pikachu" << endl;
        cin >> choice;
        if (choice != 4 && choice != 3 && choice != 2 && choice != 1)
        {
            cout << endl;
            cout << "---------------" << endl;
            cout << "That is not a valid selection!" << endl;
            cout << "---------------" << endl;
            cout << endl;
        }
        else
        {
            check = false;
        }
    }
    test.setPlayerSelec(choice);
    test.setWorldMap("mapPoke.txt");
    test.setPokemon("pokemon.txt");
    test.setPlayer(choice);
    Pokemon first;
    switch (choice)
    {
        case 1:
            for (int i = 0; i < 151; i++)
            {
                if (test.getPokeAt(i).getPokeName() == "Bulbasaur")
                {
                    first = test.getPokeAt(i);
                }
            }
            break;
            
        case 2:
            for (int i = 0; i < 151; i++)
            {
                if (test.getPokeAt(i).getPokeName() == "Charmander")
                {
                    first = test.getPokeAt(i);
                }
            }
            break;
            
        case 3:
            for (int i = 0; i < 151; i++)
            {
                if (test.getPokeAt(i).getPokeName() == "Squirtle")
                {
                    first = test.getPokeAt(i);
                }
            }
            break;
            
        case 4:
            for (int i = 0; i < 151; i++)
            {
                if (test.getPokeAt(i).getPokeName() == "Pikachu")
                {
                    first = test.getPokeAt(i);
                }
            }
            break;
            
        default:
            cout << "Error in Pokemon selection!" << endl;
    }
    test.setPlayerPokeList(first, 0);
    test.setActivePoke(0);
    test.setTrainers();
    test.setWildPokemon();
    test.getGamePlay();
    return 0;
}