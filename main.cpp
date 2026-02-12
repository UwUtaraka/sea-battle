#include <iostream>
#include <string>
#define SIZE 5

using namespace std;

class Game{
    public:
    char field[SIZE][SIZE]{0};
    Game(){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                field[i][j] = '=';
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
    void makeMove(){
        cout << "введите координаты: ";
        int x, y;
        cin >> x >> y;
        field[x][y] = '#';
    }
    
};

int main(){
    Game game1;
    Game game2;
    game1.show();
    game1.makeMove();
    game1.show();
    cout << endl;

    cout << endl;

    game2.makeMove();
    cout << endl;
}