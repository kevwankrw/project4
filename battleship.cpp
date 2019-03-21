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
	//This prints the initial header
	print_initial_header();

	//The player then receives a prompt to enter their name 
	cout << "Enter your name:";
	string name_val;
	//The player then inputs their name 
	cin >> name_val;
	cout << endl;

	//Then the program asks which grid to read for the player
	cout << "Read your grid from file grid1.txt? (y or n):";
	char input1;
	cin >> input1;
	cout << endl;
	string p1grid;
	//If the player types in 'y' then the program will input the grid1
	if (input1 == 'y') {
		p1grid = "grid1.txt";
	}
	//Otherwise it will return a blank grid
	else {
		p1grid = "";
	}

	//The program then asks which grid the CPU should be playing from
	cout << "Read CPU grid from file grid2.txt? (y or n):";
	char input2;
	cin >> input2;
	cout << endl;
	string p2grid;
	//If the player inputs 'y' then CPU uses grid 2
	if (input2 == 'y') {
		p2grid = "grid2.txt";
	}
	//Otherwise the CPU is assigned a blank grid
	else {
		p2grid = "";
	}

	//This names the players and begins to play the game
	Player p1(name_val);
	Player p2("CPU");
	Game playGame(p1, p1grid, p2, p2grid);

	int menu_choice = get_menu_choice();
	//If the player picks menu choice 4 then the closer prints and the program ends
	if (menu_choice == 4) {
		print_closer();
		return 0;
	}
	//If menu choice is 1 then the player plays a round with an easy AI. 
	//Once the game is over, the closer prints and the program ends.
	if (menu_choice == 1) {
		cout << "Starting game with EASY AI" << endl;
		playGame.start(EASY, MAX_ROUNDS);
		print_closer();
		return 0;
	}
	//If menu choice is 2 then the player plays a round with an medium AI. 
	//Once the game is over, the closer prints and the program ends.
	else if (menu_choice == 2) {
		cout << "Starting game with MEDIUM AI" << endl;
		playGame.start(MEDIUM, MAX_ROUNDS);
		print_closer();
		return 0;
	}
	//If menu choice is 3 then the player plays a round with another person. 
	//Once the game is over, the closer prints and the program ends.
	else if (menu_choice == 3) {
		cout << "Starting game with CPU EMULATION" << endl;
		playGame.start(EMULATE, MAX_ROUNDS);
		print_closer();
		return 0;
	}
}
