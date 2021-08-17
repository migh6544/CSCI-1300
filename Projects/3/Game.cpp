// CS1300 Fall 2019
// Author: Michael Ghattas
// Recitation 103 - Tetsumichi Umada
// Project 3 - Game Class

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "Game.h"
#include "Pokemon.h"
#include "Trainer.h"

using namespace std;



/* The functions takes a line of strings, looks for a specific character and splits
the line int to 2 individual strings stored in an array.*/
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


/* Defining functions/data members, setters and getters functionallity for Game.h */
Game::Game()
{
    playerName = "";
    playerSelec = 0;
    for (int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            worldMap[i][j] = "";
        }
    }
}

void Game::setPlayerName(string name)
{
    playerName = name;
}

string Game::getPlayerName()
{
    return playerName;
}

void Game::setPlayerSelec(int choice)
{
    playerSelec = choice;
}

int Game::getPlayerSelec()
{
    return playerSelec;
}

void Game::setWorldMap(string fileName)
{
    ifstream inFile;
    string line = "";
    string a[16];
    int count = 0;
    inFile.open(fileName);
    if (inFile.is_open())
    {
        while (count < 25 && getline(inFile, line))
        {
            split(line, ',', a, 16);
            if (line != "")
            {
                for (int j = 0; j < 16; j++) 
                {
                    worldMap[count][j] = a[j];
                }
                count++;
            }
        }
    }
    else
    {
        cout << "File Error!" << endl;
    }
    inFile.close();
}

void Game::getWorldMap()
{
    string space = " ";
    string print = "";
    cout << "---------------------------------" << endl;
    for (int j = 0; j < 25; j++)
    {
        for (int i = 0; i < 16; i++)
        {
            if (j == player.getTrainerLocationRow() && i == player.getTrainerLocationCol())
            {
                print = print + space + "@";
            }
            else
            {
                print = print + space + worldMap[j][i];
            }
        }
        cout << print << endl;
        print = "";
    }
    cout << "---------------------------------" << endl;
}

Pokemon Game::getPokeAt(int idx)
{
    return allPokeList[idx];
}

void Game::setPokemon(string fileName)
{
    ifstream inFile;
    string  line = "";
    string  parse[9];
    string  pokeInfo[8];
    Pokemon temp;
    int count = 0;
    inFile.open(fileName);
    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            split(line, ',', parse, 9);
            if (line != "")
            {
                if (count != 0)
                {
                    for (int j = 1; j < 9; j++) 
                    {
                        pokeInfo[j] = parse[j];
                    }
                    temp.setPokeName(pokeInfo[1]);
                    temp.setPokeHealth(stoi(pokeInfo[2]));
                    temp.setPokeAttack(stoi(pokeInfo[3]));
                    temp.setPokeDefense(stoi(pokeInfo[4]));
                    temp.setPokeSpeed(stoi(pokeInfo[5]));
                    temp.setPokeMax(0);
                    temp.setPokeType(pokeInfo[7]);
                    temp.setPokeSpecial(pokeInfo[8]);
                    allPokeList.push_back(temp);
                }
                count++;
            }
        }
    }
    else
    {
        cout << "File Error!" << endl;
    }
    inFile.close();
}

void Game::setPlayer(int choice)
{
    player = allTrainersList[0];
    switch(choice)
    {
        case 1:
            player.setTrainerLocation(13, 7);
            break;
            
        case 2:
            player.setTrainerLocation(13, 8);
            break;
            
        case 3:
            player.setTrainerLocation(13, 9);
            break;
            
        case 4:
            player.setTrainerLocation(12, 9);
            break;
            
        default:
            cout << "Error in Pokemon selection!" << endl;
    }
}

void Game::setActivePoke(int num)
{
    activePoke = playerPokeList[num];
}

void Game::getActivePoke()
{
    cout << "Active Pokemon:" << endl;
    cout << "---------------" << endl;
    cout << "Name: " << activePoke.getPokeName() << endl;
    cout << "Health: " << activePoke.getPokeHealth() << endl;
    cout << "Attack: " << activePoke.getPokeAttack() << endl;
    cout << "Defense: " << activePoke.getPokeDefense() << endl;
    cout << "Speed: " << activePoke.getPokeSpeed() << endl;
    cout << "Max: " << activePoke.getPokeMax() << endl;
    cout << "Type: " << activePoke.getPokeType() << endl;
    cout << "Special: " << activePoke.getPokeSpecial() << endl;
    cout << "---------------" << endl;
}

void Game::setPlayerPokeList(Pokemon add, int num)
{
    playerPokeList[num] = add;
}

void Game::getPlayerPokeList()
{
    cout << "Party Pokemon List:" << endl;
    for (int i = 0; i < 6; i++)
    {
        if (playerPokeList[i].getPokeName() != "")
        {
            cout << "---------------" << endl;
            cout << "Name: " << playerPokeList[i].getPokeName() << endl;
            cout << "Health: " << playerPokeList[i].getPokeHealth() << endl;
            cout << "Attack: " << playerPokeList[i].getPokeAttack() << endl;
            cout << "Defense: " << playerPokeList[i].getPokeDefense() << endl;
            cout << "Speed: " << playerPokeList[i].getPokeSpeed() << endl;
            cout << "Max: " << playerPokeList[i].getPokeMax() << endl;
            cout << "Type: " << playerPokeList[i].getPokeType() << endl;
            if (playerPokeList[i].getPokeSpecial() != "" || playerPokeList[i].getPokeSpecial() != "\n" || playerPokeList[i].getPokeSpecial() != "\r")
            {
                cout << "Special: " << playerPokeList[i].getPokeSpecial() << endl;
            }
            else
            {
                cout << "Special: None" << endl;
            }
            cout << "---------------" << endl;
        }
    }
}

void Game::setTrainers()
{
    int idx = 0;
    Pokemon temp;
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if (worldMap[i][j] == "G")
            {
                idx++;
                allTrainersList[idx].setTrainerLocation(i, j);
                int count = rand() % 6;
                for (int k = 0; k < count; k++)
                {
                    int poke = rand() % 151;
                    temp = allPokeList[poke];
                    allTrainersList[idx].setPokeList(temp);
                }
            }  
        }
    }
}

void Game::setWildPokemon()
{
    for (int w = 0; w < 20; w++)
    {
        int wild = rand() % 151;
        wildPokeList[w] = allPokeList[wild];
    }
        for (int k = 0; k < 20; k++)
        {
            bool valid = true;
            while (valid == true)
            {
                int R = rand() % 25;
                int C = rand() % 16;
                bool free = true;
                for (int m = 0; m < k; m++)
                {
                    if ( R == wildPokeList[m].getPokeLocationRow() && C == wildPokeList[m].getPokeLocationCol())
                    {
                        free = false;
                    }
                }
                if (free == true && worldMap[R][C] == "p" && R != player.getTrainerLocationRow() && C != player.getTrainerLocationCol())
                {
                    wildPokeList[k].setPokeLocation(R, C);
                    valid = false;
                }
            }
        }
}

void Game::getWildPokemon()
{
    for (int i = 0; i < 20; i++)
    {
        cout << "Wild Pokemon:" << endl;
        cout << "---------------" << endl;
        cout << "Name: " << wildPokeList[i].getPokeName() << endl;
        cout << "Health: " << wildPokeList[i].getPokeHealth() << endl;
        cout << "Attack: " << wildPokeList[i].getPokeAttack() << endl;
        cout << "Defense: " << wildPokeList[i].getPokeDefense() << endl;
        cout << "Speed: " << wildPokeList[i].getPokeSpeed() << endl;
        cout << "Max: " << wildPokeList[i].getPokeMax() << endl;
        cout << "Type: " << wildPokeList[i].getPokeType() << endl;
        cout << "Special: " << wildPokeList[i].getPokeSpecial() << endl;
        cout << "Location: Row(" << wildPokeList[i].getPokeLocationRow() << ") Col(" << wildPokeList[i].getPokeLocationCol() << ")" << endl;
        cout << "---------------" << endl;
    }
}

void Game::getGamePlay()
{
    int select = 0;
    int direction = 0;
    bool run = true;
    while (run == true)
    {
        string space = " ";
        string print = "";
        for(int j = 0; j < 25; j++)
        {
            for (int i = 0; i < 16; i++)
            {
                if (worldMap[j][i] == "p")
                {
                    worldMap[j][i] = "*";
                }
                if (worldMap[j][i] == "w")
                {
                    worldMap[j][i] = "~";
                }
            }
        }
        cout << "---------------" << endl;
        for (int j = 0; j < 7; j++)
        {
            for (int i = 0; i < 7; i++)
            {
                if (j == 3 && i == 3)
                {
                    print = print + space + "@";
                }
                else
                {
                    print = print + space + worldMap[player.getTrainerLocationRow() - 3 + j][player.getTrainerLocationCol() - 3 + i];
                }
            }
            cout << print << endl;
            print = "";
        }
        cout << "---------------" << endl;
        cout << "The sun is shining, " << playerName << "!" << endl; 
        cout << "It’s a beautiful day, we have " << player.getNumPokeBalls() << " Pokéball left and your Pokémon are strong." << endl;
        cout << endl;
        cout << "---------------" << endl;
        cout << "Active Pokemon:" << endl;
        cout << "---------------" << endl;
        cout << "Name: " << activePoke.getPokeName() << endl;
        cout << "Health: " << activePoke.getPokeHealth() << endl;
        cout << "Attack: " << activePoke.getPokeAttack() << endl;
        cout << "Defense: " << activePoke.getPokeDefense() << endl;
        cout << "Speed: " << activePoke.getPokeSpeed() << endl;
        cout << "Max: " << activePoke.getPokeMax() << endl;
        cout << "Type: " << activePoke.getPokeType() << endl;
        cout << "Special: " << activePoke.getPokeSpecial() << endl;
        cout << "---------------" << endl;
        getPlayerPokeList();
        cout << "---------------" << endl;
        cout << "Please choose from the following options:" << endl;
        cout << "1. Travel" << endl;
        cout << "2. Rest" << endl;
        cout << "3. Try your luck" << endl;
        cout << "4. Quit the game" << endl;
        cout << "---------------" << endl;
        cin >> select;
        switch(select)
        {
            case 1:
                cout << "Where would you like to go " << playerName << "?" << endl;
                cout << "1. North" << endl;
                cout << "2. South" << endl;
                cout << "3. East" << endl;
                cout << "4. West" << endl;
                cout << "5. Pokemon Center" << endl;
                cin >> direction;
                switch(direction)
                {
                    case 1:
                        if (worldMap[player.getTrainerLocationRow() - 1][player.getTrainerLocationCol()] != "~")
                        {
                            player.setTrainerLocation(-1, 0);
                        }
                        
                        else
                        {
                            cout << "---------------" << endl;
                            cout << "No way! We can't go there..." << endl;
                            cout << "---------------" << endl;
                        }
                        break;
                        
                    case 2:
                        if (worldMap[player.getTrainerLocationRow() + 1][player.getTrainerLocationCol()] != "~")
                        {
                            player.setTrainerLocation(1, 0);
                        }
                        else
                        {
                            cout << "---------------" << endl;
                            cout << "No way! We can't go there..." << endl;
                            cout << "---------------" << endl;
                        }
                        break;
                        
                    case 3:
                        if (worldMap[player.getTrainerLocationRow()][player.getTrainerLocationCol() + 1] != "~")
                        {
                            player.setTrainerLocation(0, 1);
                        }
                        else
                        {
                            cout << "---------------" << endl;
                            cout << "No way! We can't go there..." << endl;
                            cout << "---------------" << endl;
                        }
                        break;
                        
                    case 4:
                        if (worldMap[player.getTrainerLocationRow()][player.getTrainerLocationCol() - 1] != "~")
                        {
                            player.setTrainerLocation(0, -1);
                        }
                        else
                        {
                            cout << "---------------" << endl;
                            cout << "No way! We can't go there..." << endl;
                            cout << "---------------" << endl;
                        }
                        break;
                        
                    case 5:
                        
                        break;
                        
                    default:
                            cout << "---------------" << endl;
                            cout << "No way! We can't go there..." << endl;
                            cout << "---------------" << endl;
                }
                break;
            
            case 2:
                for (int i = 0; i < 6; i++)
                {
                    playerPokeList[i].setPokeHealth(playerPokeList[i].getPokeHealth() + 1);
                }
                player.setNumPokeBalls(-1);
                break;
                
            case 3:
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 7; j++)
                    {
                        for (int k = 0; k < 7; k++)
                        {
                            if (player.getTrainerLocationRow() - 3 + j == wildPokeList[i].getPokeLocationRow() 
                            && player.getTrainerLocationCol() - 3 + k == wildPokeList[i].getPokeLocationCol() 
                            && wildPokeList[i].getPokeName() != "Found")
                            {
                                int chance = rand() % 2;
                                if (chance == 1)
                                {
                                    for (int l = 0; l < 6; l++)
                                    {
                                        if (playerPokeList[l].getPokeName() == "")
                                        {
                                            playerPokeList[l] = wildPokeList[i];
                                            break;
                                        }
                                        else
                                        {
                                            playerPokeDex.push_back(wildPokeList[i]);
                                        }
                                    }
                                    wildPokeList[i].setPokeName("Found");
                                    cout << "---------------" << endl;
                                    cout << "Congratulations! You have a new Pokemon." << endl;
                                    cout << "---------------" << endl;
                                }
                                else
                                {
                                    cout << "---------------" << endl;
                                    cout << "Better luck next time!" << endl;
                                    cout << "---------------" << endl;
                                    cout << endl;
                                }
                                i = 20;
                                j = 7;
                                k = 7;
                            }
                        }
                    }
                }
                break;
                
            case 4:
                
                break;
                
            default:
                cout << "---------------" << endl;
                cout << "Invalid selection!" << endl;
                cout << "---------------" << endl;
                cout << endl;
        }
    }
}