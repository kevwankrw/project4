/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * <#Heidi Schmidt, Kevin Wang#>
 * <#heschmid, kevwan#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <cmath>
#include "Ship.h"


//Default constructor
Ship::Ship() {
	start.set_col(0);
	start.set_row(0);
	end.set_col(0);
	end.set_row(0);
	num_hits = 0;
	size = 0;
}


//Non-default constructor
Ship::Ship(Position start_in, Position end_in) {
	start = start_in;
	end = end_in;
	num_hits = 0;
	if (start.get_row() == end.get_row()) {
		size = abs(start.get_col() - end.get_col()) + 1;
	}
	else if (start.get_col() == end.get_col()) {
		size = abs(start.get_row() - end.get_row()) + 1;
	}
	else size = 0;
}


//start getter
Position Ship::get_start() {
	return start;
}


//end getter 
Position Ship::get_end() {
	return end;
}


//size getter
int Ship::get_size() {
	return size;
}


//checks to see if the ship is horizontal 
bool Ship::is_horizontal() {
	//If the row values are equal then the ship is horizontal
	if (start.get_row() == end.get_row()) {
		return true;
	}
	else {
		return false;
	}
}


//checks if position of the ship is possible
bool Ship::has_position(Position pos) {
	//If the col numbers the ship is vertical 
	if (start.get_col() == end.get_col()) {
		//if the start of the row is greater than the end
		if (start.get_row() > end.get_row()) {
			//makes sure that the position of the row is between the start and end positions
			if ((pos.get_row() <= start.get_row()) && (pos.get_row() >= end.get_row())) {
				return true;
			}
			//returns false if this is not true
			else {
				return false;
			}
		}
		//The program then checks is end is greater than start
		else if (start.get_row() < end.get_row()) {
			//makes sure position is between the two points and returns true if it is
			if ((pos.get_row() >= start.get_row()) && (pos.get_row() <= end.get_row())) {
				return true;
			}
			//Otherwise it returns false
			else {
				return false;
			}
		}
	}
	//Does the same as the above section but for horizontal ships
	else if (start.get_row() == end.get_row()) {
		if (start.get_col() > end.get_col()) {
			if ((pos.get_col() <= start.get_col()) && (pos.get_col() >= end.get_col())) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (start.get_col() < end.get_col()) {
			if ((pos.get_col() >= start.get_col()) && (pos.get_col() <= end.get_col())) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	//returns false if none of the conditions match
	return false;
}


//Hits the pos of the ship and only does so 
//if the hit does not sink the ship
void Ship::hit() {
	if (num_hits < size) {
		num_hits += 1;
	}
}


//Checks to see if the number of hits 
//is equal to the size of the ship
//returns true if they are equal 
bool Ship::has_sunk() {
	if (num_hits == size) {
		return true;
	}
	else {
		return false;
	}
}
