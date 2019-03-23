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
	Position pos7(-5, -7);
	Position pos9(0, 0);
	Position pos11('9', 'A');
	Position pos12(-0, -0);
	
	for (char i = '0'; i < '9' + 1; i++) {
		for (char j = 'a'; j < 'h' + 1; j++) {
			Position pos13(i, j);
			cout << pos13;
		}
	}

	for (char i = '0'; i < '9' + 1; i++) {
		for (char j = 'A'; j < 'H' + 1; j++) {
			Position pos14(i, j);
			cout << pos14;
		}
	}

	cout << pos1 << endl;
	cout << pos2 << endl;
	cout << pos3 << endl;
	cout << pos4 << endl;
	cout << pos5 << endl;
	cout << pos7 << endl;
	cout << pos9 << endl;
	cout << pos11 << endl;
	cout << pos12 << endl;
	

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
	Position pos4('4', 'h');
	Position pos5(10, 5);
	Position pos6('7', 'K');
	Position pos7(-5, -7);
	Position pos8(2, 1);
	Position pos9(4, 0);
	Position pos10(0, 0);
	Position pos11(9, 0);
	Position pos12(0, 9);
	Position pos13(0, 1);
	Position pos14(1, 0);

	Ship ship2(pos1, pos2);
	Ship ship3(pos2, pos1);
	Ship ship4(pos3, pos4);
	Ship ship5(pos4, pos3);
	Ship ship6(pos10, pos11);
	Ship ship7(pos10, pos12);
	Ship ship8(pos11, pos10);
	Ship ship9(pos12, pos10);
	Ship ship10(pos10, pos13);
	Ship ship11(pos10, pos14);
	Ship ship12(pos13, pos10);
	Ship ship13(pos14, pos10);
	

	cout << ship2.has_position(pos1) << endl;
	cout << ship4.has_position(pos3) << endl;
	cout << ship5.has_position(pos4) << endl;
	cout << ship6.has_position(pos5) << endl;
	cout << ship7.has_position(pos6) << endl;
	cout << ship8.has_position(pos7) << endl;
	cout << ship9.has_position(pos8) << endl;
	cout << ship10.has_position(pos9) << endl;
	for (int i = 0; i < 10; i++) {
		ship2.hit();
		cout << ship2.has_sunk();
		ship3.hit();
		cout << ship3.has_sunk();
		ship4.hit();
		cout << ship4.has_sunk();
		ship5.hit();
		cout << ship5.has_sunk();
		ship6.hit();
		cout << ship6.has_sunk();
		ship7.hit();
		cout << ship7.has_sunk();
		ship8.hit();
		cout << ship8.has_sunk();
		ship9.hit();
		cout << ship9.has_sunk();
		ship10.hit();
		cout << ship10.has_sunk();

	}


	return;
}



void test_player() {
	Player p1;
	cout << p1.get_name();
	cout << p1.get_num_ships();
	cout << p1.get_remaining_ships();
	p1.print_opponent_grid();
	p1.print_opponent_grid();
	Player p2("player1");
	Player p3("player2");
	Player p4("player3");
	Player p5("player4");
	Player p6("player5");


	Position pos1(5, 4);
	Position pos2('4', 'A');
	Position pos3(7, 8);
	Position pos4('4', 'h');
	Position pos5(10, 5);
	Position pos6('7', 'K');
	Position pos7(-5, -7);
	Position pos8(2, 1);
	Position pos9(4, 0);
	Position pos10(0, 0);
	Position pos11(9, 0);
	Position pos12(0, 9);
	Position pos13(0, 1);
	Position pos14(1, 0);

	Ship ship_list[12] = { { pos1, pos2 }, { pos2, pos1 }, {pos3, pos4 },{pos4, pos3},
						   {pos10, pos11}, {pos10,pos12},{pos11,pos10}, {pos12,pos10},
						   {pos10, pos13}, {pos10, pos14} ,{pos13, pos10}, {pos14,pos10 } };
	for (int i = 0; i < 12; i++) {
		p1.add_ship(ship_list[i]);
		cout << p1.get_num_ships();
		cout << p1.get_remaining_ships();
		p1.print_grid();
		p1.print_opponent_grid();
	}
	



	p2.position_not_hit(pos1);
	p3.position_not_hit(pos2);
	p4.position_not_hit(pos3);
	p5.position_not_hit(pos4);
	p6.position_not_hit(pos5);

	Position pos15(6, 5);
	Position pos16(3, 1);
	Position pos17(5, 0);
	Position pos18(0, 6);
	Position pos19(5, 5);


	p2.attack(p3, pos1);
	p3.print_grid();
	p2.print_opponent_grid();

	p3.attack(p4, pos2);
	p3.print_opponent_grid();
	p4.print_grid();

	p4.attack(p5, pos3);
	p4.print_opponent_grid();
	p5.print_grid();

	p5.attack(p6, pos4);
	p5.print_opponent_grid();
	p6.print_grid();

	p6.attack(p2, pos5);
	p6.print_opponent_grid();
	p2.print_grid();

	p3.attack(p2, pos8);
	p3.print_opponent_grid();
	p2.print_grid();

	p3.attack(p2, pos9);
	p3.print_opponent_grid();
	p2.print_grid();

	p3.attack(p2, pos10);
	p3.print_opponent_grid();
	p2.print_grid();

	p3.attack(p2, pos11);
	p3.print_opponent_grid();
	p2.print_grid();

	p3.attack(p2, pos12);
	p3.print_opponent_grid();
	p2.print_grid();



	p2.load_grid_file("grid1.txt");
	p4.load_grid_file("grid2.txt");
	p3.load_grid_file("");
	p5.load_grid_file("gridB.txt");
	p6.load_grid_file("dgdgdvjw.txt");
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
	Game game4();

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
