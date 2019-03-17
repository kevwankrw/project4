/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * <Kevin Wang and Heidi Schmidt>
 * <kevwan and heschmid>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include "Position.h"
#include "utility.h"


Position::Position() {
	row = check_range(0);
	col = check_range(0);
}

Position::Position(int row_in, int col_in) {
	row = check_range(row_in);
	col = check_range(col_in);
}

Position::Position(char row_in, char col_in) {
	int tempCol;
	if (col_in >= 'a' && col_in <= 'z') {
		tempCol = col_in - 'a';
	}
	else if (col_in >= 'A' && col_in <= 'Z') {
		tempCol = col_in - 'A';
	}
	col = check_range(tempCol);
	int tempRow;
	if (row_in >= '1' && row_in <= '9') {
		tempRow = row_in - '1';
	}
	row = check_range(tempRow);
}

int Position::get_row() {
	return row;
}

void Position::set_row(int row_in) {
	row = check_range(row_in);
}

int Position::get_col() {
	return col;
}

void Position::set_col(int col_in) {
	col = check_range(col_in);
}

void Position::read(istream &is) {
	char tempRow;
	char tempCol;
	char temp;
	for (int i = 0; i < 2; ++i) {
		is >> temp;
		if (temp == '(' || temp == ',' || temp == ')') {
			is >> temp;
		}
		if (temp >= '1' && temp <= '9') {
			tempRow = temp;
		}
		if ((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z')) {
			tempCol = temp;
		}
	}
	int itempCol;
	if (tempCol >= 'a' && tempCol <= 'z') {
		itempCol = tempCol - 'a';
	}
	else if (tempCol >= 'A' && tempCol <= 'Z') {
		itempCol = tempCol - 'A';
	}
	col = check_range(itempCol);
	int itempRow;
	if (tempRow >= '1' && tempRow <= '9') {
		itempRow = tempRow - '1';
	}
	row = check_range(itempRow);
}

void Position::write(ostream &os) {
	char tempRow = '1' + row;
	char tempCol = 'A' + col;
	cout << "(" << tempRow << "," << tempCol << ")";
}

int Position::check_range(int val) {
	if (val >= 0 && val < MAX_GRID_SIZE) {
		return val;
	}
	else {
		if (val < 0) {
			return 0;
		}
		else {
			return MAX_GRID_SIZE - 1;
		}
	}
}


// Your code goes above this line.
// Don't change the implementations below!

istream &operator>>(istream &is, Position &pos) {
	pos.read(is);
	return is;
}

ostream &operator<<(ostream &os, Position pos) {
	pos.write(os);
	return os;
}
