#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <ctime>

#define SIZE 10
using namespace std;

class Game {
public:
    char field[SIZE][SIZE];
    char battleField[SIZE][SIZE];

    Game();
    void autoPlacement();
    bool autoAttack(Game &enemy);
    void show();
    void battleShow();
    bool canPlace(int x, int y, int len, string orientation);
    void setShip(int len, string name);
    void placement();
    bool attack(Game &enemy);
    bool isAlive();
};

#endif