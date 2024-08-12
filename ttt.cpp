#include <iostream>
#include <vector>
#include "functions.hpp"
using namespace std;


int main() {

//print empty board
  set_positions();
  display();
  cout << "Player 1: You are noughts\n";
  cout<< "Player 2: You are crosses\n";

  //bool board_full = is_board_full();
  //cout << board_full;  

  while(!is_board_full() && !iswinner()){
    //player chooses square
    take_turn();
  }

  
//game over if board full or player wins
    game_over();
    
}
