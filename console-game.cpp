#include <iostream>
#include <vector>
#include "console-game.h"

void TicTacToe::LandPage()
{
    system("cls"); //* Clear terminal screen.
    
    //* Announcement.
    printf("Tic Tac Toe [Version 0.0.1.2025]\n");
    printf("The first C/C++ project since 2025.\n");

    //*Choosing the size of table.
    std::cout << "\nPlease choose the size of table.\n";
    do{
        std::cin >> TicTacToe::width >> TicTacToe::height;
        if(TicTacToe::width <= 0 || TicTacToe::height <= 0){
            std::cout << "Please enter positive numbers.\n";
        }
    }while(TicTacToe::width <= 0 || TicTacToe::height <= 0);

    TicTacToe::my_table.resize(TicTacToe::height, std::vector<char>(TicTacToe::width, ' '));
}
void TicTacToe::DrawTable() {

    std::cout << std::endl;
    system("cls"); //* Clear screen
    printf("You chose %dx%d table.\nTry to beat me.\n", TicTacToe::width, TicTacToe::height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << " " << my_table[i][j] << " ";
            if (j < width - 1) std::cout << "|";  
        }
        std::cout << std::endl;
        
        if (i < height - 1) {
            for (int j = 0; j < width; j++) {
                std::cout << "---";
                if (j < width - 1) std::cout << "+";
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}
void TicTacToe::Run()
{
    DrawTable();
    while(!TicTacToe::game_over){
        GetInput();

        system("cls");
        DrawTable();
    }
}
void TicTacToe::GetInput()
{
    int i, j;

    do{
        std::cout << "Enter your cell in 1-index: ";
        std::cin >> i >> j;

        if((i < 1 || j < 1) || (i > TicTacToe::height || j > TicTacToe::width)){
            std::cout << "Please enter a valid cell." << std::endl;
        }
        if(TicTacToe::my_table[i - 1][j - 1] != ' '){
            std::cout << "This cell was used before. Please enter another cell." << std::endl;
            i = -1, j = -1;
        }

    }while((i < 1 || j < 1) || (i > TicTacToe::height || j > TicTacToe::width));

    TicTacToe::my_table[i - 1][j - 1] = 'x';
}