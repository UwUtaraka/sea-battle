#include <iostream>
#include <string>
#define SIZE 5

using namespace std;

class Game{
    public:
    char field[SIZE][SIZE]{0};
    int boat = 2;
    int destroyer = 1;

    Game(){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                field[i][j] = '-';
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
        }
        for (int i = 0; i < boat; i++){
            int x, y;
            cout << "введите координаты для катера: ";
            cin >> x >> y;
            if (field[x][y] != '#'){
                field[x][y] = '#';
            }
            else{cout << "данная клетка занята" << endl;}
            
        }
    }
};

int main(){
    Game game1;
    Game game2;
    cout << "Player 1" << endl;
    game1.show();
    game1.placement();
    game1.show();
    cout << "для передачи управления нажмит Enter" << endl;

    cin.get();
    cin.get();

    system("cls");

    cout << endl;

    cout << "Player 2" << endl;
    game2.show();
    game2.placement();
    game2.show();

}