#include "Game.h"

int main() {
    srand(time(0));
    int mode;
    Game game1, game2;

    cout << "Выберите режим (0-PvP, 1-Bot): ";
    cin >> mode;
    
    game1.placement();
    if (mode == 1) game2.autoPlacement();
    else game2.placement();

    bool turn1 = true;
    while(game1.isAlive() && game2.isAlive()) {
        system("cls");
        if (turn1) {
            cout << "Ход игрока 1" << endl;
            game1.battleShow();
            if (!game1.attack(game2)) turn1 = false;
        } else {
            if (mode == 0) {
                cout << "Ход игрока 2" << endl;
                game2.battleShow();
                if (!game2.attack(game1)) turn1 = true;
            } else {
                if (!game2.autoAttack(game1)) turn1 = true;
                cin.get();
            }
        }
    }
    cout << "Игра окончена!" << endl;
    cin.get(), cin.get();
    return 0;
}