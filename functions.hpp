// ~~~~~~ functions.hpp ~~~~~~
#include <iostream>
#include <vector>
using namespace std;

void set_positions();

void display();

void change_player();

void check_entry(int entry);

void change_square(int playerno, int entry);

bool iswinner();

bool is_board_full();

void take_turn();

void game_over();