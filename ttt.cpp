#include <iostream>
#include <algorithm>
#include <vector>

#include "ttt_funs.hpp"

int get_input(std::vector<std::vector<char>> marks);


std::vector<std::vector<char>>  update_board(std::vector<std::vector<char>> marks , int input, char marker ){
    int row = 2-(input-1)/3;
    int col = (input-1)%3;  
    marks[row][col] = marker;
    return marks;
}


int main()
{
    using namespace std;
    vector<vector<char>> marks(3, vector<char>(3, '_')); // 3x3 char vector


    char marker;
    char current_player = 'X';
    int input = 0;
    bool game_over = false;
    
    greet();
    display_board(marks);

        while (game_over==false)
        {            
            cout <<"Player: "<< current_player << " go!\n";

            input =0;
            while (input==0)  {
                input = get_input(marks);                
            }

            marks = update_board(marks, input, current_player);
            display_board(marks); 

            if (checkWinner(marks, current_player)){
                game_over = true;
                
                cout << "player: " << current_player << " won!";
            }
            else if (checkStale(marks)){
                game_over = true;
                cout << "Stalemate!";
            }
            else{
                if (current_player=='X') current_player='O';
                else current_player='X';
            }
            

        }

}

