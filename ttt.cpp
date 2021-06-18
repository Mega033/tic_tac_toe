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

int main(){
    using namespace std;
    

    greet();


}
