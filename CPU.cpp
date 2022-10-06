#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Checkers.h"

using namespace std;

bool CPU_move(char tab[10][10]) {
	srand(time(NULL));
	vector<int> move;
	bool attack = false;
	int move_counter = 0;
	int choose = 0;

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			if (tab[i][j] == 'B') {
				if (i<=7 && j<=7) {
					if (tab[i + 1][j + 1] == 'W' || tab[i + 1][j + 1] == 'M') {
						if (tab[i + 2][j + 2] == '#') {
							attack = true;
							move.push_back(i);
							move.push_back(j);
							move_counter += 1;
						}
					}
				}
				if (i <= 7 && j >= 2) {
					if (tab[i + 1][j - 1] == 'W' || tab[i + 1][j - 1] == 'M') {
						if (tab[i + 2][j - 2] == '#') {
							attack = true;
							move.push_back(i);
							move.push_back(j);
							move_counter += 1;
						}
					}
				}
			}
		}
	}

	if (attack == false) {
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				if (tab[i][j] == 'B') {
					if (i <= 8 && j <= 8) {
						if (tab[i + 1][j + 1] == '#') {
							move.push_back(i);
							move.push_back(j);
							move_counter += 1;
						}
					}
					if (i <= 8 && j >= 1) {
						if (tab[i + 1][j - 1] == '#') {
							move.push_back(i);
							move.push_back(j);
							move_counter += 1;
						}
					}
				}
			}
		}
	}

	if (move_counter != 0) {
		choose = rand() % move_counter;
		int A, B ,X;
		A = move[choose * 2];
		B = move[(choose * 2) + 1];
		move.clear();
		choose = 0;
		move_counter = 0;
		if (attack == true) {
			if (A <= 7 && B <= 7) {
				if (tab[A + 1][B + 1] == 'W' || tab[A + 1][B + 1] == 'M') {
					if (tab[A + 2][B + 2] == '#') {
						move.push_back(A);
						move.push_back(B);
						move_counter += 1;
						X = 0;
					}
				}
			}
			if (A <= 7 && B >= 2) {
				if (tab[A + 1][B - 1] == 'W' || tab[A + 1][B - 1] == 'M') {
					if (tab[A + 2][B - 2] == '#') {
						move.push_back(A);
						move.push_back(B);
						move_counter += 1;
						X = 1;
					}
				}
			}
		}
		if (attack == false) {
			if (A <= 8 && B <= 8) {
				if (tab[A + 1][B + 1] == '#') {
					move.push_back(A);
					move.push_back(B);
					move_counter += 1;
					X = 0;
				}
			}
			if (A <= 8 && B >= 1) {
				if (tab[A + 1][B - 1] == '#') {
					move.push_back(A);
					move.push_back(B);
					move_counter += 1;
					X = 1;
				}
			}
		}

		choose = rand() % move_counter;
		A = move[choose * 2];
		B = move[(choose * 2) + 1];

		if (move_counter > 2) {
			X = choose;
		}

		if (attack == true) {
			tab[A][B] = '#';
			if (X == 0) {
				tab[A + 1][B + 1] = '#';
				tab[A + 2][B + 2] = 'B';
			}
			if (X == 1) {
				tab[A + 1][B + 1] = '#';
				tab[A + 2][B + 2] = 'B';
			}
		}
		if (attack == false) {
			tab[A][B] = '#';
			if (X == 0) {
				tab[A + 1][B + 1] = 'B';
			}
			if (X == 1) {
				tab[A + 1][B + 1] = 'B';
			}
		}
		return false;
	}
	else {
		return true;
	}


}