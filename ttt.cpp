#include <iostream>


void greet(){
  using namespace std;
  string msg ;
  msg += "=============\n" ;
  msg += "Tic Tac Toe: n";
  msg += "=============\n";
  msg += "Instructions: Get 3 in row before the other player!\n";
  cout << msg;
}


void display_state(bool p1_marks[3][3], bool p2_marks[3][3], bool is_player1)
{
    using namespace std;

    string board[3]= {  "___|___|___",
                        "___|___|___",
                        "   |   |   " };

}


int main()
{
    using namespace std;

    bool p1_marks[3][3] = {false};
    bool p2_marks[3][3] = {false};

    bool is_player1 = true;

    display_state(p1_marks, p2_marks, is_player1);





    greet();


}
