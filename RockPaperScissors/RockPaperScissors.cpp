//this program perform the rock paper scissors game
//this is a game between the computer and a single user

#include "std_lib_facilities.h"
#define quit 'q'

enum outcome {LOSE,WIN, RETRY};
enum game_options { ROCK, PAPER, SCISSORS };

int rand_num()
//this function return a random number from 1 to 3
{
	
	return randint(1, 4);

}

int choose_move() 
//the function enable the user to make a shoot by choosing between alternatives
{

	cout << "Please enter a number to make a move or 'q' to quit the game\n";
	cout << "1: Rock\n";
	cout << "2: Paper\n";
	cout << "3: Scissors\n";
	
	int num = 0;

	while (cin >> num) {
		
		if (((num == 1) || (num == 2) || (num == 3)))return num;
	}

	if (cin.fail()) {
		cin.unget();
		cin.clear();
		char ch = 0;
		cin >> ch;
		if (ch == quit)return num;
		return choose_move();
	}
	return num;
}

game_options to_gameOptions(const int n) {
	
	switch (n) {
	case 1:
		return ROCK;
	case 2:
		return PAPER;
	case 3:
		return SCISSORS;
	default:
	break;
	}

}

string from_gameOptions(const int gam) {

	if (gam == 1)return "ROCK";
	else if (gam == 2)return "PAPER";
	else if (gam == 3)return "SCISSORS";
}
outcome loose_win(const int us, const int co) {
	const game_options user = to_gameOptions(us);
	const game_options comp = to_gameOptions(co);

	if ( user == comp ) return RETRY;

	switch (user) {
	case ROCK:
		if(comp == PAPER)return LOSE;
		if (comp == SCISSORS) return WIN;

	case PAPER:
		if (comp == ROCK)return WIN;
		if (comp == SCISSORS) return LOSE;
	case SCISSORS:
		if (comp == ROCK)return LOSE;
		if (comp == PAPER) return WIN;
	default:
		return LOSE;
	}

}

void execute_game() {
	int ch =0;
	while (ch=choose_move()) {
		if (ch == 4)continue;

		int comp = rand_num();
		outcome outcom = loose_win(ch,comp);
		cout << "You choosed: " << from_gameOptions(ch) << " and computer choosed: " << from_gameOptions(comp) << endl;
		if(outcom == WIN) cout << "Congratulation: You win\n";
		else if (outcom == LOSE) cout << "You lose: but dont lose hope\n";
		else if (outcom == RETRY) cout << " Aww: You made a tie please try again\n";
	}
}
int main() {

	execute_game();
	keep_window_open();
	return 0;
}