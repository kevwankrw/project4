/**
 * Copyright 2019 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 4cd2d66df3154b6c8b0ff27aa6791edb
 *
 * Project 4: Battleship
 *
 * Contains functions for testing classes in the project. 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


void test_position();
void test_ship();
void test_player();
void test_game();

int main() {
    test_position();
    test_ship();
    test_player();
    return 0;
}

void test_position() {
    	Position start_pos;
	Position end_pos;
	cout << "Testing Position::Position() - default constructor\n";
	cout << "start_pos, expected output: (1,A) actual output: " << start_pos << endl;
	cout << "end_pos, expected output: (1,A) actual output: " << end_pos << endl;

	start_pos.set_row(4);
	cout << start_pos << endl;
	start_pos.set_col(5);
	cout << start_pos << endl;
	start_pos.set_col(10);
	cout << start_pos << endl;
	start_pos.set_col(4);
	cout << start_pos << endl;

	Position pos1(5, 4);
	Position pos2('4', 'A');
	Position pos3(7, 8);
	Position pos4('5', 'h');
	Position pos5(10, 5);
	Position pos6('7', 'K');
	Position pos7(-5, -7);

	cout << pos1 << endl;
	cout << pos2 << endl;
	cout << pos3 << endl;
	cout << pos4 << endl;
	cout << pos5 << endl;
	cout << pos6 << endl;
	cout << pos7 << endl;


	ifstream input_file;
	input_file.open("grid1.txt");
	if (input_file.good()) {

		start_pos.read(input_file);

		input_file >> end_pos;

		cout << "\nTesting Position::read()\n";
		cout << "start_pos, expected output: (1,A) actual output: " << start_pos << endl;
		cout << "end_pos, expected output: (4,A) actual output: " << end_pos << endl;
	}
	else {
		cout << "\nError opening grid1.txt\n";
	}
    return;
}

void test_ship() {
    Ship ship1();
	Position pos1(5, 4);
	Position pos2('4', 'A');
	Position pos3(7, 8);
	Position pos4('5', 'h');
	Position pos5(10, 5);
	Position pos6('7', 'K');
	Position pos7(-5, -7);
	Ship ship2(pos1, pos2);
	Ship ship3(pos2, pos3);
	Ship ship4(pos3, pos4);
	Ship ship5(pos4, pos5);
	Ship ship6(pos5, pos6);
	Ship ship7(pos6, pos7);

	ship2.has_position(pos1);
	ship3.has_position(pos2);
	ship4.has_position(pos3);
	ship5.has_position(pos4);
	ship6.has_position(pos5);
	ship7.has_position(pos6);

	ship2.hit();
	ship3.hit();
	ship4.hit();
	ship5.hit();
	ship6.hit();
	ship7.hit();

    return;
}

void test_player() {
    // Write your tests here
    return;
}

