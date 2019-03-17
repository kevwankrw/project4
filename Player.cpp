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
	return 'F';;
}

void Player::add_ship(Ship ship) {
	if (num_ships >= MAX_NUM_SHIPS) {
		return;
	}
	else if () {

	}
    return;
}

bool Player::position_not_hit(Position pos) {
	for (int i = 0; i < MAX_GRID_SIZE; i++) {
		for (int j = 0; j < MAX_GRID_SIZE; j++) {
			if (grid[i][j] == EMPTY_LETTER || grid[i][j] == SHIP_LETTER) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

void Player::attack(Player &opponent, Position pos) {
	if (position_not_hit(pos) == false) {
		opponent_grid[pos.get_row][pos.get_col] = HIT_LETTER;
		cout << opponent << " " << pos << " hit" << endl;
	}
	else if(position_not_hit(pos) == true) {
		opponent_grid[pos.get_row][pos.get_col] = MISS_LETTER;
		cout << opponent << " " << pos << " miss" << endl;
	}

	
    return;
}

void Player::announce_ship_sunk(int size) {
	if (size == 2) {
		cout << "Congratulations " << get_name << " ! You sunk a Destroyer" << endl;
	}
	else if (size == 3) {
		cout << "Congratulations " << get_name << " ! You sunk a Submarine" << endl;
	}
	else if (size == 4) {
		cout << "Congratulations " << get_name << " ! You sunk a Battleship" << endl;
	}
	else if (size == 5) {
		cout << "Congratulations " << get_name << " ! You sunk a Carrier" << endl;
	}

    return;
}

bool Player::load_grid_file(string filename) {
	ifstream("grid1.txt");
	
    return false;
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
