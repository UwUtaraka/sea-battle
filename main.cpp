#include <iostream>
#include <string>
#include <ctime>
#define SIZE 10

using namespace std;

class Game{
    public:
    char field[SIZE][SIZE];
    char battleField[SIZE][SIZE];

    Game(){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                field[i][j] = '_';
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                battleField[i][j] = '_';
            }
        }
    }

    void autoPlacement() {
        int ships[10][3] = {
            {0, 0, 4}, {2, 0, 3}, {4, 0, 3}, {6, 0, 2}, {8, 0, 2}, {0, 5, 2}, {2, 5, 1}, {4, 5, 1}, {6, 5, 1}, {8, 5, 1}
        };
        for (int i = 0; i < 10; i++) {
            int x = ships[i][0];
            int y = ships[i][1];
            int len = ships[i][2];
            for (int j = 0; j < len; j++){
                field[x][y + j] = '#';
            }
        }
    }

    bool autoAttack(Game &enemy) {
        int x, y;
        do {
            x = rand() % SIZE;
            y = rand() % SIZE;
        } 
        while (enemy.field[x][y] == 'X' || enemy.field[x][y] == '*');

        if (enemy.field[x][y] == '#') {
            enemy.field[x][y] = 'X';
            battleField[x][y] = 'X';
            return true;
        } 
        else {
            enemy.field[x][y] = '*';
            battleField[x][y] = '*';
            return false;
        }
    }

    void show(){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                cout << field[i][j];
            }
            cout << endl;
        }
    }

    void battleShow(){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                cout << battleField[i][j];
            }
            cout << endl;
        }
    }

    bool canPlace(int x, int y, int len, string orientation){
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

    void setShip(int len, string name){
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

    void placement(){
        show();
        setShip(4, "Линкор");
        setShip(3, "Крейсер");
        setShip(3, "Крейсер");
        setShip(2, "Эсминец");
        setShip(2, "Эсминец");
        setShip(2, "Эсминец");
        setShip(1, "Катер");
        setShip(1, "Катер");
        setShip(1, "Катер");
        setShip(1, "Катер");

    }

    bool attack(Game &enemy){
        int x, y;
        cout << "Введите координаты выстрела: "; 
        cin >> x >> y;
        
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            cout << "Снаряд улетел за пределы поля!" << endl;
            return true;
        }

        if (enemy.field[x][y] == '#') {
            enemy.field[x][y] = 'X';
            this->battleField[x][y] = 'X';
            cout << "ПОПАЛ! Ходите снова." << endl;
            return true; 
        } 
        else if (enemy.field[x][y] == 'X' || enemy.field[x][y] == '*'){
            cout << "сюда уже стреляли" << endl;
            return true;
        }
        else {
            enemy.field[x][y] = '*';
            this->battleField[x][y] = '*';
            cout << "ПРОМАХ!" << endl; 
            return false; 
        }
    }

    bool isAlive(){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                if (field[i][j] == '#'){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    srand(time(0));
    int mode;
    Game game1, game2;

    cout << "выберите режим игры(0-игра в паре; 1-игра с ботом): " << endl;
    cin >> mode;
    
    cout << "Player 1" << endl;
    game1.placement();

    
    

    if (mode == 0){
        cout << "для передачи управления нажмите Enter" << endl;
        cin.get(); cin.get();
        system("cls");
        cout << "Player 2" << endl;
        game2.placement();
    }
    else if (mode == 1){
        cout << "бот ставит корабли" << endl;
        game2.autoPlacement();
        cout << "Нажмите Enter, чтобы начать бой" << endl;
        cin.get(); cin.get();
    }
    else {cout << "error" << endl;}

    system("cls");


    bool turn1 = true;
    bool end = false;

    while(!end){
        system("cls");
        if (turn1){
            cout << "ход игрока 1" << endl;
            game1.battleShow();
            if (!game1.attack(game2)){
                turn1 = false;
                cout << "для передачи управления, нажмите Enter" << endl;
                cin.get(); cin.get();
            }
            if (!game2.isAlive()){
                cout << "игрок 1 победил" << endl;
                end = true;
            }
        }
        else{
            if (mode == 0){
                cout << "ход игрока 2" << endl;
                game2.battleShow();
                if (!game2.attack(game1)){
                    turn1 = true;
                    cout << "для передачи управления, нажмите Enter" << endl;
                    cin.get(); cin.get();
                }
            }
            else{
                game2.battleShow();
                if (game2.autoAttack(game1)){
                    turn1 = true;
                    cin.get(); cin.get();
                }
                else{
                    cin.get(); cin.get();
                }
            }
            
            if (!game1.isAlive()){
                cout << "игрок 2 победил" << endl;
                end = true;
            }
        }
        
    }
    cout << "игра окончена, нажмите Enter для закрытия" << endl;
    cin.get();
    cin.get();
}