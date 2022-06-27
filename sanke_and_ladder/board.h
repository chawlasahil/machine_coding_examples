#pragma once
#include "dice.h"
#include "ladder_factory.h"
#include "player_factory.h"
#include "snake_factory.h"
#include <iostream>

using namespace std;

class board
{
public:
	virtual ~board() {};
};

class normal_board : public board
{
public:
	normal_board();
	void set_num_cells(int n);
	void initialize_players(int n, vector<string>& names);
	void initialize_ladders(int n, vector<pair<int, int>> pos);
	void initialize_snakes(int n, vector<pair<int, int>> pos);
	void initialize_dice(int n, int seed);
	void initialize_board(); // sets up the values of cells
	void simulate_game();

private:
	vector<pair<int,int>> cells; // 0 -> no ladder or snake, -1 -> snake, 1 -> ladder | 2nd value denotes the final position it goes to if snake or ladder
	vector<player*> game_players;
	vector<snake*> game_snakes;
	vector<ladder*> game_ladders;
	dice* game_dice = nullptr;
	player_factory* game_player_factory = nullptr;
	ladder_factory* game_ladder_factory = nullptr;
	snake_factory* game_snake_factory = nullptr;
};