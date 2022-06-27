#pragma once
#include "board.h"

int main()
{
	// setting up input
	int num_snakes = 0; cin >> num_snakes;
	vector<pair<int,int>> snake_pos;
	for (int i = 0; i < num_snakes; i++)
	{
		pair<int, int> pos; cin >> pos.first >> pos.second;
		snake_pos.push_back(pos);
	}

	int num_ladders = 0; cin >> num_ladders;
	vector<pair<int, int>> ladder_pos;
	for (int i = 0; i < num_ladders; i++)
	{
		pair<int, int> pos; cin >> pos.first >> pos.second;
		ladder_pos.push_back(pos);
	}

	int num_players = 0; cin >> num_players;
	vector<string> names;
	for (int i = 0; i < num_players; i++)
	{
		string s; cin >> s;
		names.push_back(s);
	}

	// setting up board
	normal_board* brd = new normal_board();
	brd->set_num_cells(100);
	brd->initialize_dice(6, 100); // dice with 6 sides and seed = 100 for random generator
	brd->initialize_players(num_players, names);
	brd->initialize_ladders(num_ladders, ladder_pos);
	brd->initialize_snakes(num_snakes, snake_pos);
	brd->initialize_board();
	brd->simulate_game();

	return 0;
}

/* sample input:
9
62 5
33 6
49 9
88 16
41 20
56 53
98 64
93 73
95 75
8
2 37
27 46
10 32
51 68
61 79
65 84
71 91
81 100
3
Gaurav
Sagar
Sahil
*/