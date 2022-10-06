#include <iostream>
#include <string>
#include "Checkers.h"

using namespace std;

string Welcome() { //welcome message
	string s;
	cout << "Enter your name: ";
	cin >> s;
	system("cls");
	cout << "Welcome " << s << "!!!\n"<<"Let's play checkers.\n";
	system("pause");
	return s;
}

void Starter(char tab[10][10]) { // filling array with starting setup
	for (int i = 0; i <= 9; i++) { //blank tiles
		for (int j = 0; j <= 9; j++) {
			tab[i][j] = ' ';
		}
	}

	for (int i = 0; i <= 9; i++) { //black tiles
		for (int j = 0; j <= 9; j++) {
			if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8) {
				if (j <= 9) {
					tab[i][j] = '#';
				}
				j++;
			}
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9) {
				j++;
				if (j <= 9) {
					tab[i][j] = '#';
				}
			}
		}
	}

	for (int i = 0; i <= 9; i++) { //pawns
		for (int j = 0; j <= 9; j++) {
			if (i == 0 || i == 2) {
				if (j <= 9) {
					tab[i][j] = 'B';
				}
				j++;
			}
			if (i == 1 || i == 3) {
				j++;
				if (j <= 9) {
					tab[i][j] = 'B';
				}
			}
			if (i == 6 || i == 8) {
				if (j <= 9) {
					tab[i][j] = 'W';
				}
				j++;
			}
			if (i == 7 || i == 9) {
				j++;
				if (j <= 9) {
					tab[i][j] = 'W';
				}
			}
		}
	}
}

void Draw_Board(char tab[10][10],bool king) { //drawing board
	string a = "ABCDEFGHIJ";
	system("cls");
	cout << " X | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
	for (int i = 0; i <= 9; i++) {
		cout << "--------------------------------------------" << endl;
		cout << " "<<a[i] << " | ";
		for (int j = 0; j <= 9; j++) {
			cout << tab[i][j] << " | ";
		}
		cout << endl;
	}
	cout << " W - White pawns\n B - Black pawns\n # - tiles for move" << endl;
	if (king == true) {
		cout << " M - White King\n D - Black King" << endl;
	}
	cout << "numbers more than 9 --> A-F" << endl;
	cout << endl;
}

bool Check_King(char tab[10][10]) {
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (tab[i][j] == 'M' || tab[i][j] == 'D') {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

string convert(char c) {
	//cout << "char: " << c << endl;
	string s(1, c);
	//cout << "string: " << s << endl;
	return s;
}

string convert(int c) {
	//cout << "int: " << c << endl;
	string s=to_string(c);
	//cout << "string: " << s << endl;
	return s;
}

void Win(string s) {
	cout << "Congratulation, " << s << "!!! You Win!!!\n";
}

void Lose(string s) {
	cout << "GAME OVER. You lose, " << s << "!!!\n";
}