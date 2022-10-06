#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "Checkers.h"


using namespace std;

bool Player_move(char tab[10][10], string s) {
	string move_str = check_move(tab);
	int pick_move_i;
	char pick_move_c;
	if (move_str == "GAMEOVER") {
		cout << "GAME OVER" << endl;
		return true;
	}
	else {
		vector<string> move_array=Fill_move_array(move_str);
		cout << "Your move " << s << "!\n";
		cout << "You can move pawns :\n";
		for (int i = 0; i < move_array.size(); i++) {
			cout << i + 1 << ". " << move_array[i] << endl;
		}
		cout << "choose pawn to move (pick number)" << endl;
		
		while (true) {
			pick_move_c = _getch();
			//pick_move_i = pick_move_c - '0';
			if (pick_move_c == '1' || pick_move_c == '2' || pick_move_c == '3' || pick_move_c == '4' || pick_move_c == '5' || pick_move_c == '6' || pick_move_c == '7' || pick_move_c == '8' || pick_move_c == '9') {
				pick_move_i = pick_move_c - '0';
			}
			else {
				pick_move_i = pick_move_c - 87;
			}
			if (pick_move_i <= move_array.size() && pick_move_i > 0) {
				break;
			}
			else {
			cout << "ERROR!!! Choose proper move." << endl;
			}
		}
		make_move_player(pick_move_i, move_array, tab);
		return false;
	}
}

string check_move(char tab[10][10]) {
	string help = "ABCDEFGHIJ";
	string attack_move, normal_move;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			int breakpoint=0;
			if (tab[i][j] == 'W' ) {
				if (j >= 2 && i >= 2) {
					if (tab[i - 1][j - 1] == 'B' || tab[i - 1][j - 1] == 'D') {
						if (tab[i - 2][j - 2] == '#') {
							if (breakpoint == 0) {
							attack_move += convert(help[i]);
							attack_move += convert(j);
							breakpoint += 1;
							}
						}
					}
				}
				if (j <= 7 && i >= 2) {
					if (tab[i - 1][j + 1] == 'B' || tab[i - 1][j + 1] == 'D') {
						if (tab[i - 2][j + 2] == '#') {
							if (breakpoint == 0) {
							attack_move += convert(help[i]);
							attack_move += convert(j);
							breakpoint += 1;
							}
						}
					}
				}
				if (j >= 1 && i >= 1) {
					if (tab[i - 1][j - 1] == '#') {
						if (breakpoint == 0) {
						normal_move += convert(help[i]);
						normal_move += convert(j);
						breakpoint += 1;
						}
					}
				}
				if (j <= 8 && i >= 1) {
					if (tab[i - 1][j + 1] == '#') {
						if (breakpoint == 0) {
						normal_move += convert(help[i]);
						normal_move += convert(j);
						breakpoint += 1;
						}
					}
				}
			}
		}
	}
	if (attack_move.length() > 0) {
		return attack_move;
	}
	else if (normal_move.length() > 0) {
		return normal_move;
	}
	else {
		return "GAMEOVER";
	}
}

vector<string> Fill_move_array(string base) {
	string help;
	vector<string> move_tab;
	for (int i = 0; i < base.size()/2; i++) {
		help = "";
		help.push_back(base[i*2]);
		help.push_back(base[(i*2)+1]);
		move_tab.push_back(help);
	}
	return move_tab;
}

void make_move_player(int pick, vector<string> move_array, char tab[10][10]) {
	string move = move_array[pick - 1];
	string help = "ABCDEFGHIJ";
	int A, B;
	bool attack = false;
	string move1 = "";
	string move2 = "";
	int pick_move_i;
	char pick_move_c;

	B = move[1] - '0';

	for (int i = 0; i <= 9; i++) {
		if (move[0] == help[i]) {
			A = i;
		}
	}

	if (A >= 2 && B >= 2) {
		if (tab[A - 1][B - 1] == 'B' || tab[A - 1][B - 1] == 'D') {
			if (tab[A - 2][B - 2] == '#') {
				attack = true;
				move1 += convert(help[A - 2]);
				move1 += convert(B - 2);
			}
		}
	}

	if (A >= 2 && B <= 7) {
		if (tab[A - 1][B + 1] == 'B' || tab[A - 1][B + 1] == 'D') {
			if (tab[A - 2][B + 2] == '#') {
				attack = true;
				move2 += convert(help[A - 2]);
				move2 += convert(B + 2);
			}
		}
	}

	if (A >= 1 && B >= 1 && attack == false) {
		if (tab[A - 1][B - 1] == '#') {
			move1 += convert(help[A - 1]);
			move1 += convert(B - 1);
		}
	}

	if (A >= 1 && B <= 8 && attack == false) {
		if (tab[A - 1][B + 1] == '#') {
			move2 += convert(help[A - 1]);
			move2 += convert(B + 1);
		}
	}

	cout << "Choose where you want to move. :";
	if (attack == true) {
		cout << "Attack" << endl;
	}
	else {
		cout << "Normal move" << endl;
	}
	if (move1 != "") {
		cout << "1. " << move1 << endl;
	}
	if (move2 != "") {
		cout << "2. " << move2 << endl;
	}

	while (true) {
		pick_move_c = _getch();
		pick_move_i = pick_move_c - '0';
		if (pick_move_i <= 2 && pick_move_i > 0) {
			if (pick_move_i == 1 && move1 != "") {
				break;
			}
			if (pick_move_i == 2 && move2 != "") {
				break;
			}
		}
		else {
			cout << "ERROR!!! Choose proper move." << endl;
		}
	}

	if (pick_move_i == 1) {
		tab[A][B] = '#';
		if (attack == true) {
			tab[A - 1][B - 1] = '#';
			tab[A - 2][B - 2] = 'W';
		}
		else {
			tab[A - 1][B - 1] = 'W';
		}
	}

	if (pick_move_i == 2) {
		tab[A][B] = '#';
		if (attack == true) {
			tab[A - 1][B + 1] = '#';
			tab[A - 2][B + 2] = 'W';
		}
		else {
			tab[A - 1][B + 1] = 'W';
		}
	}


}