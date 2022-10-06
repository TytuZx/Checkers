#pragma once
#include <vector>

std::string Welcome(); //functions.cpp
void Starter(char tab[10][10]); //functions.cpp
void Draw_Board(char tab[10][10], bool); //functions.cpp
bool Check_King(char tab[10][10]); //functions.cpp
std::string convert(char); //functions.cpp
std::string convert(int); //functions.cpp
void Win(std::string); //functions.cpp
void Lose(std::string); //functions.cpp

bool Player_move(char tab[10][10], std::string); //player.cpp
std::string check_move(char tab[10][10]); //player.cpp
std::vector<std::string> Fill_move_array(std::string); //player.cpp
void make_move_player(int, std::vector<std::string>, char tab[10][10]); //player.cpp

bool CPU_move(char tab[10][10]);//cpu.cpp