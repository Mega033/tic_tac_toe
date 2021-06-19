#include <iostream>
#include <algorithm>
#include <vector>

void greet();

void display_board(std::vector<std::vector<char>> marks);

int get_input(std::vector<std::vector<char>> marks);

std::vector<std::vector<char>> transpose(std::vector<std::vector<char>> marks);

bool checkWinner(std::vector<std::vector<char>> marks, char mark);

bool checkStale(std::vector<std::vector<char>> marks);


