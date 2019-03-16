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
    // TODO: write implementation here.
    return '?';
}

void Player::add_ship(Ship ship) {
    // TODO: write implementation here.
    return;
}

bool Player::position_not_hit(Position pos) {
    // TODO: write implementation here.
    return false;
}

void Player::attack(Player &opponent, Position pos) {
    // TODO: write implementation here.
    return;
}

void Player::announce_ship_sunk(int size) {
    // TODO: write implementation here.
    return;
}

bool Player::load_grid_file(string filename) {
    // TODO: write implementation here.
    return false;
}

bool Player::destroyed() {
    // TODO: write implementation here.
    return false;
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_opponent_grid() {
    ::print_grid(opponent_grid);
}
