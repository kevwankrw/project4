/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * <#Heidi Schmidt, Kevin Wang#>
 * <#heschmid, kevwan#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <fstream>

#include "Player.h"


//Default constructor
Player::Player() {
	name = "";
	num_ships = 0;
	remaining_ships = 0;
	init_grid();
}


//Non-default constructor
Player::Player(string name_val) {
	name = name_val;
	num_ships = 0;
	remaining_ships = 0;
	init_grid();
}


//Initializes grid
void Player::init_grid() {
	for (int i = 0; i < MAX_GRID_SIZE; i++) {
		for (int j = 0; j < MAX_GRID_SIZE; j++) {
			grid[i][j] = EMPTY_LETTER;
			opponent_grid[i][j] = EMPTY_LETTER;
		}
	}
	return;
}


//Name getter
string Player::get_name() {
	return name;
}


//Number of Ships getter
int Player::get_num_ships() {
	return num_ships;
}


//Remaining ships getter
int Player::get_remaining_ships() {
	return remaining_ships;
}

//Position on grid getter
char Player::get_grid_at(int row, int col) {
	if (row <= MAX_GRID_SIZE && col <= MAX_GRID_SIZE) {
		if (row >= 0 && col >= 0) {
			return grid[row][col];
		}
	}
	return 'F';
}
//Position on opponent grid getter
char Player::get_opponent_grid_at(int row, int col) {
	if (row <= MAX_GRID_SIZE && col <= MAX_GRID_SIZE) {
		if (row >= 0 && col >= 0) {
			return opponent_grid[row][col];
		}
	}
	return 'F';
}

void Player::add_ship(Ship ship) {
	//Checks to see that the number of ships is less than MAX ships
	if (num_ships >= MAX_NUM_SHIPS) {
	}
	//sets the start of the ship to position start and same with end
	else {
		Position start = ship.get_start();
		Position end = ship.get_end();
		ships[num_ships] = ship;
		//Checks to see if the ship is horizontal 
		if (ships[num_ships].is_horizontal()) {
			//If the ship is horizontal then a ship letter is added
			//to represent where the ship is on the board 
			if (start.get_col() < end.get_col()) {
				for (int i = start.get_col(); i <= end.get_col(); ++i) {
					grid[start.get_row()][i] = SHIP_LETTER;
				}
			}
			//the else statement covers all possible ship combinations because 
			//start can be greater or less than the end
			else {
				for (int i = end.get_col(); i <= start.get_col(); ++i) {
					grid[start.get_row()][i] = SHIP_LETTER;
				}
			}
		}
		//If the ship isn't horizontal then the function 
		//does the same thing but with vertical ships
		else {
			if (start.get_row() < end.get_row()) {
				for (int i = start.get_row(); i <= end.get_row(); ++i) {
					grid[i][end.get_col()] = SHIP_LETTER;
				}
			}
			else {
				for (int i = end.get_row(); i <= start.get_row(); ++i) {
					grid[i][end.get_col()] = SHIP_LETTER;
				}
			}
		}
		//Finally the program adds to num ships and remaining ships 
		num_ships++;
		remaining_ships++;
	}
}




bool Player::position_not_hit(Position pos) {
	//Position not hit checks for an empty letter or a ship letter
	//If it is not one of those then the function returns false
	if (grid[pos.get_row()][pos.get_col()] == EMPTY_LETTER ||
		grid[pos.get_row()][pos.get_col()] == SHIP_LETTER) {
			return true;
	}
	else {
		return false;
	}
}



void Player::attack(Player &opponent, Position pos) {
	//If the position is not hit then the program will run through a series of checks
	if (opponent.position_not_hit(pos)) {
		//Initialization
		bool is_ship_there = false;
		int ship_num = 0;
		//Checks if these is a ship at pos and that the ship number is less than 
		//The number of opponent ships
		while (!is_ship_there && (ship_num < opponent.get_num_ships())) {
			//If there is a ship at the position, is ship there is set to true
			if (opponent.ships[ship_num].has_position(pos)) {
				is_ship_there = true;
			}
			//Otherwise ship num is increased to check the next ship
			else {
				++ship_num;
			}
		}
		//If there is no ship at the pos then a miss message is printed
		//and opponent_grid is set to MISS_LETTER
		if (!is_ship_there) {
			cout << name << " " << pos << " " << "miss\n";
			opponent_grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
			opponent.grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
		}
		//Otherwise, if a ship is there then the function checks to 
		//see if the ship has sunk of not
		else if (is_ship_there) {
			opponent.ships[ship_num].hit();
			if (opponent.ships[ship_num].has_sunk()) {
				//If the ship has sunk then remaining ships is
				//decrements and announce ship sunk is called
				opponent.remaining_ships--;
				announce_ship_sunk(opponent.ships[ship_num].get_size());
			}
		//If the shit is not sunk, the program then prints out a hit message and 
		// sets the pos on the oppponent grid to a hit letter
			cout << name << " " << pos << " " << "hit\n";
			opponent_grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
			opponent.grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
		}
	}
}

//This function looks at the size of the ship and prints out a message accordingly 
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
//load grid file looks at whether the first character is a number or a ')'
	char tempRowS;
	char tempRowE;
	char tempColS;
	char tempColE;
	char temp;
	int num_temp = 0;
	ifstream input;
	input.open(filename);
	if (!input.is_open()) return false;
	//If there is a (, then the functions assign the appropriate
	//characters to the correct spaces
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
			//Otherwise it will input the other format for position
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
