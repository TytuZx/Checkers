#include <iostream>
#include "Checkers.h"

int main()
{
    char Board[10][10];
    std::string s;
    bool King = false;
    bool Player_Win = false;
    bool CPU_Win = false;
    s = Welcome();
    Starter(Board);
    while (true) {
        King = Check_King(Board);
        Draw_Board(Board, King);
        CPU_Win = Player_move(Board, s);
        if (CPU_Win) { break; };
        King = Check_King(Board);
        Draw_Board(Board, King);
        Player_Win = CPU_move(Board);
        if (Player_Win) { break; };
    }

    if (Player_Win) {
        Win(s);
    }

    if (CPU_Win) {
        Lose(s);
    }

}