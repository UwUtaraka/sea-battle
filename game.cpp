#include "Game.h"

Game::Game() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            field[i][j] = '_';
            battleField[i][j] = '_';
        }
    }
}

void Game::battleShow() {
    cout << "вражеское поле       ваше поле" << endl;
    cout << "  0123456789         0123456789   # - корабль; Х - попадание; * - промах" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) cout << battleField[i][j];
        cout << "       " << i << " ";
        for (int j = 0; j < SIZE; j++) cout << field[i][j];
        cout << endl;
    }
}

bool Game::attack(Game &enemy) {
    int x, y;
    cout << "Введите координаты выстрела: "; 
    cin >> x >> y;
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) return true;

    if (enemy.field[x][y] == '#') {
        enemy.field[x][y] = 'X';
        battleField[x][y] = 'X';
        return true; 
    } 
    enemy.field[x][y] = '*';
    battleField[x][y] = '*';
    return false;
}

void Game::show(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout << field[i][j];
        }
        cout << endl;
            
    }
}
bool Game::canPlace(int x, int y, int len, string orientation){
    for (int i = 0; i < len; i++){
        int curX, curY;
        if (orientation == "V"){
            curX = x + i;
            curY = y;
        }
        else{
            curX = x;
            curY = y + i;
        }
        if (curX < 0 || curX >= SIZE || curY < 0 || curY >= SIZE) {
            return false;
        }
        for (int r = curX - 1; r <= curX + 1; r++){
            for (int c = curY - 1; c <= curY + 1; c++){
                if (r >= 0 && r < SIZE && c >= 0 && c < SIZE){
                    if (field[r][c] == '#'){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void Game::setShip(int len, string name){
    int x, y;
    string orientation;
    bool next = false;
    while (!next){
        cout << "введите координаты для " << name << endl;
        cin >> x >> y;
        if (len > 1){
            cout << "введите положение корабля:\nV - вертикальное\nH - горизонтальное" << endl;
            cin >> orientation;
        }
        else{orientation = 'H';}
        if (canPlace(x, y, len, orientation)){
            for (int i = 0; i < len; i++){
                if (orientation == "V"){
                    field[x + i][y] = '#';
                }
                else{
                    field[x][y + i] = '#';
                }
            }
            show();
            next = true;
        }
        else{
            cout << "корабрь нельзя ставить за границу или вплотную к другому кораблю" << endl;
        }
    }
}

void Game::placement(){
    show();
    setShip(4, "Линкор");
    setShip(3, "Крейсер");
    setShip(2, "Эсминец");
    setShip(2, "Эсминец");
    setShip(1, "Катер");
    setShip(1, "Катер");
    setShip(1, "Катер");
}

bool Game::isAlive(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (field[i][j] == '#'){
                return true;
            }
        }
    }
    return false;
}
