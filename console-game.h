#ifndef TICTACTOE
#define TICTACTOE

#include <iostream>
#include <vector>

class TicTacToe
{
    private:
        bool game_over = false;
        short width, height;

        std::vector<std::vector<char>> my_table;
    public:
        void LandPage();
        void DrawTable();
        void Run();
        void GetInput();   
};

#endif