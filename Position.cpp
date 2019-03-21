/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * <#Heidi Schmidt, Kevin Wang#>
 * <#heschmid, kevwan#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include "Position.h"
#include "utility.h"


//Default constructor
Position::Position() {
	row = 0;
	col = 0;
	return;
}


//Non-Default constructor
Position::Position(int row_in, int col_in) {

	row = check_range(row_in);
	col = check_range(col_in);

	return;
}

//Non-default constructor
Position::Position(char row_in, char col_in) {

	row = check_range((int)(row_in - '1'));
	if (col_in >= 'A' && col_in <= 'Z') {
		col = check_range((int)col_in - 'A');
	}
	else if (col_in >= 'a' && col_in <= 'z') {
		col = check_range((int)col_in - 'a');
	}
}

//row getter
int Position::get_row() {
	return row;
}

//row setter
void Position::set_row(int row_in) {
	row = check_range(row_in);
	return;
}

//col getter
int Position::get_col() {
	return col;
}

//col setter
void Position::set_col(int col_in) {
	col = check_range(col_in);
	return;
}

//Reading in the file 
void Position::read(istream &is) {
	char char1, char2, char3, char4, char5;
	is >> char1;
		if(char1 == '(') {
			is >> char2 >> char3 >> char4 >> char5;
			row = check_range(char2 - '1');
			col = check_range(tolower(char4) - 'a');

		}
		else{
			is >> char2;
				row = check_range(char1 - '1');
				col = check_range(tolower(char2) - 'a');
		}
}

//Writing to the file
void Position::write(ostream &os) {
	char tempRow = '1' + row;
	char tempCol = 'A' + col;
	cout << "(" << tempRow << "," << tempCol << ")";
}


//checks the range of row and col and makes sure 
//that they do not go out of bounds
int Position::check_range(int val) {
	if (val >= 0 && val < MAX_GRID_SIZE) {
		return val;
	}
	else if (val < 0) {
		return 0;
	}
	else {
		return MAX_GRID_SIZE - 1;
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


