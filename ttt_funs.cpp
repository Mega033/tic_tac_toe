#include <algorithm>
#include <vector>
#include <iostream>

void display_board(std::vector<std::vector<char>> marks)
{
    std::string board[3]= { "___|___|___", // "_1_|_5_|_9_",
                            "___|___|___",
                            "___|___|___" };
    for (int row=0; row <3; row++){
        for (int col=0; col <3; col++){            
            board[row][col*4+1] = marks[row][col];
        }
        std::cout << board[row] << "\n";
    }
}

void greet(){
    using namespace std;
    string msg ;
    char any_btn;
    msg += "=============\n" ;
    msg += "Tic Tac Toe: \n";
    msg += "=============\n";
    msg += "Instructions: Get 3 in row before the other player!\n";
    msg += "Player1 uses X and Player2 uses O \n";
    cout << msg;
    cout << "This how the tiles are mapped: \n";

    vector<vector<char>> map = {{'7', '8', '9'},      // "c1_|_5_|_9_", r0
                                {'4', '5', '6'},      // "c1_|_5_|_9_", r1
                                {'1', '2', '3'}};    // "c1_|_5_|_9_", r2
    display_board(map);
    cout << "Press any button to continue: \n";
    cin >> any_btn;      
}

int get_input(std::vector<std::vector<char>> marks)
{ //return false if bad input
// if good input returns true and updates player markers
    using namespace std;
    int input = 0;
    int row;
    int col;

    cin >> input;

    if (cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input a number \n";
        return 0;
    }

    if ( not(input > 0 && input <10)){
        cout << "Input a number: 1-9\n";
        return 0 ;
    }

    row = 2-(input-1)/3;
    col = (input-1)%3;
    if (marks[row][col] == '_')
    {
        return input;
    }
    cout << "Tile already taken, use another one! \n";

    return 0;
}

std::vector<std::vector<char>> transpose(std::vector<std::vector<char>> marks)
{
    using namespace std;
    int rows = marks.size();
    int cols = marks[0].size();
    vector<vector<char>> t_marks (3, vector<char>(3, '_')); //3x3 vector 
    
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)            
        {
            t_marks[c][r]= marks[r][c];
            }
    }
    return t_marks;
}

bool checkWinner(std::vector<std::vector<char>> marks, char mark){
    using namespace std;
    bool winner = false;

    vector<vector<char>> tmarks = transpose( marks);

    for (int r=0; r <3; r++){
        if ( (marks[r][0] == mark) && (marks[r][1] == mark) && (marks[r][2] == mark) )  
        return true; //if rows
        
        if ( (tmarks[r][0] == mark) && (tmarks[r][1] == mark) && (tmarks[r][2] == mark) )
        return true;  // if cols 
    }

    if ( (marks[0][0] == mark) && (marks[1][1] == mark) && (marks[2][2] == mark) )
    return true; // if diags 1

    if ( (marks[2][0] == mark) && (marks[1][1] == mark) && (marks[0][2] == mark) )
    return true; // if diags 2

    return false;
}

bool checkStale(std::vector<std::vector<char>> marks){
    using namespace std;
    bool filled = false;
    char open = '_';

    for (int r=0; r <3; r++)
    {
        for(int c=0; c<3; ++c)
        {
            if (marks[r][c] ==open){
                return false; // is not stalemate
            }
        }
    }
    return true;

}
