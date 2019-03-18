/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <fstream>

#include "Player.h"


Player::Player() {
	name = "";
	num_ships = 0;
	remaining_ships = 0;
	init_grid();
}



Player::Player(string name_val) {
	name = name_val;
	num_ships = 0;
	remaining_ships = 0;
	init_grid();
}



void Player::init_grid() {
	for (int i = 0; i < MAX_GRID_SIZE; i++) {
		for (int j = 0; j < MAX_GRID_SIZE; j++) {
			grid[i][j] = EMPTY_LETTER;
			opponent_grid[i][j] = EMPTY_LETTER;
		}
	}
	return;
}



string Player::get_name() {
	return name;
}



int Player::get_num_ships() {
	return num_ships;
}



int Player::get_remaining_ships() {
	return remaining_ships;
}


char Player::get_grid_at(int row, int col) {
	if (row <= MAX_GRID_SIZE && col <= MAX_GRID_SIZE) {
		if (row >= 0 && col >= 0) {
			return grid[row][col];
		}
	}
	return 'F';
}

char Player::get_opponent_grid_at(int row, int col) {
	if (row <= MAX_GRID_SIZE && col <= MAX_GRID_SIZE) {
		if (row >= 0 && col >= 0) {
			return opponent_grid[row][col];
		}
	}
	return 'F';
}

void Player::add_ship(Ship ship) {
	if (num_ships >= MAX_NUM_SHIPS) {
	}
	else {
		Position start = ship.get_start();
		Position end = ship.get_end();
		ships[num_ships] = ship;
		if (ships[num_ships].is_horizontal()) {
			for (int i = start.get_col(); i <= end.get_col(); ++i) {
				grid[start.get_row()][i] = SHIP_LETTER;
			}
		}
		else {
			for (int i = start.get_row(); i <= end.get_row(); ++i) {
				grid[i][end.get_col()] = SHIP_LETTER;
			}
		}
		num_ships++;
		remaining_ships++;
	}
}




bool Player::position_not_hit(Position pos) {
	if (grid[pos.get_row()][pos.get_col()] == EMPTY_LETTER ||
		grid[pos.get_row()][pos.get_col()] == SHIP_LETTER) {
			return true;
	}
	else {
		return false;
	}
}



void Player::attack(Player &opponent, Position pos) {
	if (!position_not_hit(pos)) {
		return;
	}
	else if (position_not_hit(pos)) {
		bool test = false;
		int ship_num = 0;
		while (!test && (ship_num < num_ships)) {
			if (ships[ship_num].has_position(pos)) {
				test = true;
			}
			else {
				test = false;
			}
			++ship_num;
		}
		if (!test) {
			cout << name << " " << pos << " " << "miss\n";
			opponent_grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
			opponent.grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
		}
		else if (test) {
			cout << name << " " << pos  << " " << "hit\n";
			opponent_grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
			opponent.grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
			ships[ship_num].hit();
			if (ships[ship_num].has_sunk()) {
				remaining_ships--;
				announce_ship_sunk(ships[ship_num].get_size());
			}
		}
	}
	return;
}



void Player::announce_ship_sunk(int size) {
	if (size == 2) {
		cout << "Congratulations " << get_name() << "! You sunk a Destroyer" << endl;
	}
	else if (size == 3) {
		cout << "Congratulations " << get_name() << "! You sunk a Submarine" << endl;
	}
	else if (size == 4) {
		cout << "Congratulations " << get_name() << "! You sunk a Battleship" << endl;
	}
	else if (size == 5) {
		cout << "Congratulations " << get_name() << "! You sunk a Carrier" << endl;
	}

	return;
}



bool Player::load_grid_file(string filename) {
	char tempRowS;
	char tempRowE;
	char tempColS;
	char tempColE;
	char temp;
	int num_temp = 0;
	ifstream input;
	input.open(filename);
	if (!input.is_open()) return false;
	while (input >> temp) {
		if (temp == ' ' || temp == '(' || temp == ',' || temp == ')');
		else {
			++num_temp;
			if (temp >= '1' && temp <= '9') {
				if (num_temp == 1) {
					tempRowS = temp;
				}
				if (num_temp == 3) {
					tempRowE = temp;
				}
			}
			else if ((temp >= 'A' && temp <= 'Z') || (temp <= 'a' && temp >= 'z')) {
				if (num_temp == 2) {
					tempColS = temp;
				}
				if (num_temp == 4) {
					tempColE = temp;
				}
			}
		}
		if (num_temp == 4) {
			num_temp = 0;
			Position start(tempRowS, tempColS);
			Position end(tempRowE, tempColE);
			Ship ship(start, end);
			add_ship(ship);
		}
	}
	return true;
}



bool Player::destroyed() {
	if (remaining_ships == 0) {
		return true;
	}
	else {
		return false;
	}
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
	::print_grid(grid);
}

void Player::print_opponent_grid() {
	::print_grid(opponent_grid);
}
