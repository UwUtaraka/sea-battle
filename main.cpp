#include <iostream>
#include <string>
#define SIZE 10

using namespace std;

class Game{
    public:
    char field[SIZE][SIZE];
    char battleField[SIZE][SIZE];
    int boat = 2;
    int destroyer = 1;

    Game(){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                field[i][j] = '_';
            }
        }
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                battleField[i][j] = '-';
            }
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

    void placement(){
        for (int i = 0; i < destroyer; i++){
            int x, y;
            string orientation;
            cout << "введите координаты для эсминца и его положение(вертикальное/горизонтальное(V/H)): ";
            cin >> x >> y >> orientation;
            if (orientation == "V"){
                if (x >= 0 && x + 1 < SIZE && y >= 0 && y < SIZE){
                    field[x][y] = '#';
                    field[x + 1][y] = '#';
                    
                }
                else{cout << "корабль выходит за границу" << endl;}
            }    
            else if (orientation == "H"){
                if (x >= 0 && x < SIZE && y >= 0 && y + 1 < SIZE){
                    field[x][y] = '#';
                    field[x][y + 1] = '#';
                    
                }
                else{cout << "корабль выходит за границу" << endl;}
            }
            show();
        }
        for (int i = 0; i < boat; i++){
            int x, y;
            cout << "введите координаты для катера: ";
            cin >> x >> y;
            if (field[x][y] != '#'){
                field[x][y] = '#';
            }
            else{cout << "данная клетка занята" << endl;}
            show();
        }
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
    Game game1;
    Game game2;
    cout << "Player 1" << endl;
    game1.show();
    game1.placement();
    cout << "для передачи управления нажмите Enter" << endl;

    cin.get();
    cin.get();

    system("cls");

    cout << endl;

    cout << "Player 2" << endl;
    game2.show();
    game2.placement();
    game2.show();

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
                cin.get();
                cin.get();
            }
            if (!game2.isAlive()){
                cout << "игрок 1 победил" << endl;
                end = true;
            }
        }
        else{
            cout << "ход игрока 2" << endl;
            game2.battleShow();
            if (!game2.attack(game1)){
                turn1 = true;
                cout << "для передачи управления, нажмите Enter" << endl;
                cin.get();
                cin.get();
            }
            if (!game1.isAlive()){
                cout << "игрок 2 победил" << endl;
                end = true;
            }
        }
    }
}