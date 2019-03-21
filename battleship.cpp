/**
 * Copyright 2019 Umich EECS 183
 *
 * battleship.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * Project 4: Battleship
 *
 * Drive of the Battleship game.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <utility>
#include <limits>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


int main() {
	print_initial_header();

	cout << "Enter your name:";
	string name_val;
	cin >> name_val;
	cout << endl;

	cout << "Read your grid from file grid1.txt? (y or n):";
	char input1;
	cin >> input1;
	cout << endl;
	string p1grid;
	if (input1 == 'y') {
		p1grid = "grid1.txt";
	}
	else {
		p1grid = "no";
	}

	cout << "Read CPU grid from file grid2.txt? (y or n):";
	char input2;
	cin >> input2;
	cout << endl;
	string p2grid;
	if (input2 == 'y') {
		p2grid = "grid2.txt";
	}
	else {
		p2grid = "no";
	}

	Player p1(name_val);
	Player p2("CPU");
	Game playGame(p1, p1grid, p2, p2grid);

	int menu_choice = get_menu_choice();
	if (menu_choice == 4) {
		print_closer();
		return 0;
	}
	else {
		if (menu_choice == 1){
			cout << "Starting game with EASY AI" << endl;
		}
		else if (menu_choice == 2) {
			cout << "Starting game with MEDIUM AI" << endl;
		}
		else if (menu_choice == 3) {
			cout << "Starting game with CPU EMULATION" << endl;
		}
		playGame.start(menu_choice, MAX_ROUNDS);
		print_closer();
		return 0;
	}


}
