#include <iostream>
#include <string>
#define SIZE 5

using namespace std;

class Game{
    public:
    char field[SIZE][SIZE]{0};
    void create(){
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                field[i][j] = '=';
            }
        }
    }
    void makeMove(){
        cout << "введите координаты: ";
        int x, y;
        cin >> x >> y;
        field[x][y] = '#';
    }
    void show(){
        for (size_t i = 0; i < SIZE; i++){
            for (size_t j = 0; j < SIZE; j++){
                cout << field[i][j] << " ";
            }
            cout << endl;
        }
    };
};

int main(){
    Game game1;
    Game game2;
    game1.create();
    game1.show();
    game1.makeMove();
    cout << endl;
    game1.show();

    cout << endl;

    game2.show();
    game2.makeMove();
    cout << endl;
    game2.show();
}