#include <iostream>
#include <string>

using namespace std;

class Game{
    public:
    int field[5][5]{};
};
int main(){
    Game game;
    for (size_t i = 0; i < sizeof(game.field) / sizeof(game.field[0]); i++){
        for (size_t j = 0; j < sizeof(game.field) / sizeof(game.field[0]); j++){
            cout << game.field[i][j] << " ";
        }
        cout << endl;
    }
}