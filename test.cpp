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
	test_game();
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
	Position pos8('0', 'z');
	Position pos9(0, 0);
	Position pos10('A', '1');
	Position pos11('9', 'A');

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
	Ship ship1;
	cout << ship1.get_start() << endl;
	cout << ship1.get_end() << endl;
	cout << ship1.get_size() << endl;

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

	cout << ship2.has_position(pos1) << endl;
	cout << ship3.has_position(pos2) << endl;
	cout << ship4.has_position(pos3) << endl;
	cout << ship5.has_position(pos4) << endl;
	cout << ship6.has_position(pos5) << endl;
	cout << ship7.has_position(pos6) << endl;

	ship2.hit();
	ship2.hit();
	ship2.hit();
	ship3.hit();
	ship4.hit();
	ship5.hit();
	ship6.hit();
	ship7.hit();

	return;
}

void test_player() {
	Player p1;
	Player p2("player1");
	Player p3("player2");
	Player p4("player3");
	Player p5("player4");
	Player p6("player5");

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


	p2.add_ship(ship2);
	p3.add_ship(ship3);
	p4.add_ship(ship4);
	p5.add_ship(ship5);
	p6.add_ship(ship6);

	p2.position_not_hit(pos1);
	p3.position_not_hit(pos2);
	p4.position_not_hit(pos3);
	p5.position_not_hit(pos4);
	p6.position_not_hit(pos5);

	p2.attack(p3, pos1);
	p3.attack(p4, pos2);
	p4.attack(p5, pos3);
	p5.attack(p6, pos4);
	p6.attack(p2, pos5);

	p2.load_grid_file("grid1.txt");
	p4.load_grid_file("grid2.txt");
	return;
}

void test_game() {
	Player p1("B");
	Player p2("Y");
	string grid1 = "yes";
	string grid2 = "no";
	Game game1(p1, "grid1.txt", p2, "grid2.txt");
	Game game2(p1, "", p2, "");
	Game game3(p1, grid1, p2, grid2);

	Player p3 = game1.get_p1();
	cout << p3.get_name();
	Player p4 = game2.get_p2();
	cout << p4.get_name();

	cout << game1.check_valid_move("1a") << endl;
	cout << game1.check_valid_move("1A") << endl;
	cout << game1.check_valid_move("1h") << endl;
	cout << game1.check_valid_move("1H") << endl;
	cout << game1.check_valid_move("8A") << endl;
	cout << game1.check_valid_move("8H") << endl;
	cout << game1.check_valid_move("9C") << endl;
	cout << game1.check_valid_move("3D") << endl;
	cout << game1.check_valid_move("3I") << endl;
	cout << game1.check_valid_move("0A") << endl;
	cout << game1.check_valid_move("(1,A)") << endl;
	cout << game1.check_valid_move("12H") << endl;
	cout << game1.check_valid_move("1,D") << endl;
}

