#include <iostream>
#include <vector>
//#include "functions.hpp"
using namespace std;

int playerno = 1;
int no_of_goes = 0;
vector<string> positions = {"0","1","2","3","4","5","6","7","8","9"};
vector<string> symbols2 = { "                   \n", "1","2","3","4","5","6","7","8","9", "   ", "  |  ", "   \n", " _____|_____|______\n", "      |     |      \n", "   " };

void set_positions() {

    symbols2[1] = positions[1];
	symbols2[2] = positions[2];
	symbols2[3] = positions[3];
	symbols2[4] = positions[4];
	symbols2[5] = positions[5];
	symbols2[6] = positions[6];
	symbols2[7] = positions[7];
	symbols2[8] = positions[8];
	symbols2[9] = positions[9];
}

void display() {
	
	
	cout << symbols2[0] << symbols2[10] << symbols2[1] << symbols2[11] << symbols2[2] << symbols2[11] << symbols2[3] << symbols2[12];
	cout << symbols2[13] << symbols2[14];
	cout << symbols2[10] << symbols2[4] << symbols2[11] << symbols2[5] << symbols2[11] << symbols2[6] << symbols2[12];
	cout << symbols2[13] << symbols2[14];
	cout << symbols2[10] << symbols2[7] << symbols2[11] << symbols2[8] << symbols2[11] << symbols2[9] << symbols2[12] << symbols2[0];
	//OR, same as below
	// display's 9 elements is equivelent to the 9 console outputs below:
	//cout << "                   \n"; //1, 0
	//cout << "   1  |  2  |  3   \n"; //2, 10,1,2,3,12
	//cout << " _____|_____|______\n"; //3, 13
	//cout << "      |     |      \n"; //4, 14
	//cout << "   4  |  5  |  6   \n"; //5, 10,4,5,6,12
	//cout << " _____|_____|______\n"; //6, 13
	//cout << "      |     |      \n"; //7, 14
	//cout << "   7  |  8  |  9   \n"; //8, 10,7,8,9,12
	//cout << "                   \n"; //9, 0*/
};

void check_entry(int entry){

        if (cin.fail()){
            cout << "You must input an integer, try again\n";
            cin >> entry;
            check_entry(entry);
        }
        if(entry < 1 || entry > 9){
            cout << "This was not in the selection, try again\n";
            cin >> entry;
            check_entry(entry);
        }
        auto str = to_string(entry);
        if (symbols2[entry] != str) {
            cout << "You have picked this square already. Try again\n";
            cin >> entry;
            check_entry(entry);
            };

};

void change_square(int playerno, int entry){

    if (playerno == 1) {
        symbols2[entry] = "X";
    };
        
    if (playerno == 2) {
        symbols2[entry] = "O";
    };
    
};

void change_player(){

  if (playerno == 1) {
    playerno++;
  }
  else
  {
    playerno--;
  }
};

bool iswinner() {

    bool iswinner = false;
    if (symbols2[1] == symbols2[2] && symbols2[2]== symbols2[3] && symbols2[1] != " ") {
        iswinner = true;
    };
    if (symbols2[4] == symbols2[5] && symbols2[5]== symbols2[6] && symbols2[4] != " ") {
        iswinner = true;
    };
    if (symbols2[7] == symbols2[8] && symbols2[8]== symbols2[9] && symbols2[7] != " ") {
        iswinner = true;
    };
    if (symbols2[1] == symbols2[4] && symbols2[4]== symbols2[7] && symbols2[1] != " ") {
        iswinner = true;
    };
    if (symbols2[2] == symbols2[5] && symbols2[5]== symbols2[8] && symbols2[2] != " ") {
        iswinner = true;
    };
    if (symbols2[3] == symbols2[6] && symbols2[6]== symbols2[9] && symbols2[3] != " ") {
        iswinner = true;
    };
    if (symbols2[1] == symbols2[5] && symbols2[5]== symbols2[9] && symbols2[1] != " ") {
        iswinner = true;
    };
    if (symbols2[3] == symbols2[5] && symbols2[5]== symbols2[7] && symbols2[3] != " ") {
        iswinner = true;
    };
    return iswinner;
};

bool is_board_full(){

    bool is_board_full = false;

    if (no_of_goes == 9) {
        is_board_full = true;
    };

    return is_board_full;
}

void take_turn(){
    
    //declaration of entry variable to be used
    int entry;

    //player chooses square
    cout<< "Player " << playerno << ": Choose a square(1-9)\n";
    cin >> entry;
    cout << "\n";

    //Check for valid entry
    //check_entry(entry);

    //if entry is valid, change the square accordingly
    change_square(playerno, entry);

    //keep count of number of turns taken
    no_of_goes++;

    //redisplay board
    display();
    
    //check for winner
    iswinner();

    //check if board is full for a draw
    is_board_full();
    //change player if no win
    change_player();
}



void game_over(){
    change_player();

    if(iswinner()) {
        cout << "Congratulations Player "<< playerno << ". You are the winner.\n";
    };
    if(is_board_full()) {
        cout << "This game was a draw.\n";
    };
}
