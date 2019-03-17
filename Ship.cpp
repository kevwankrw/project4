/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * <Kevin Wang and Heidi Schmidt>
 * <kevwan and heschmid>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <cmath>

#include "Ship.h"


Ship::Ship() {
	start.set_col = 0;
	start.set_row = 0;
	end.set_col = 0;
	end.set_row = 0;
	num_hits = 0;
	size = 0;
}

Ship::Ship(Position start_in, Position end_in) {
	start = start_in;
	end = end_in;
	num_hits = 0;
	if (start.get_row() == end.get_row()) {
		size = abs(start.get_col() - end.get_col());
	}
	else if (start.get_col() == end.get_col()) {
		size = abs(start.get_row() - end.get_row());
	}
}

Position Ship::get_start() {
    return start;
}

Position Ship::get_end() {
	return end;
}

int Ship::get_size() {
	return size;
}

bool Ship::is_horizontal() {
	if (start.get_row() == end.get_row()) {
		return true;
	}
	else {
		return false;
	}
}

bool Ship::has_position(Position pos) {
	if (start.get_col() == end.get_col()) {
		if (start.get_row() > end.get_row()) {
			if ((pos.get_row <= start.get_row()) && (pos.get_row() >= end.get_row())) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (start.get_row() < end.get_row()) {
			if ((pos.get_row >= start.get_row()) && (pos.get_row() <= end.get_row())) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else if (start.get_row() == end.get_row()) {
		if (start.get_col() > end.get_col()) {
			if ((pos.get_col <= start.get_col()) && (pos.get_col() >= end.get_col())) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (start.get_col() < end.get_col()) {
			if ((pos.get_col >= start.get_col()) && (pos.get_col() <= end.get_col())) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

void Ship::hit() {
	if (num_hits > size) {
		num_hits += 1;
	}
}

bool Ship::has_sunk() {
	if (num_hits == size) {
		return true;
	}
	else {
		return false;
	}
}
