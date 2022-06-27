#include "board.h"

normal_board::normal_board()
{
	cells.clear();
	game_players.clear();
	game_ladders.clear();
	game_snakes.clear();
	game_dice = new normal_dice();
	game_player_factory = new uniform_player_factory();
	game_ladder_factory = new normal_ladder_factory();
	game_snake_factory = new base_snake_factory();
}

void normal_board::set_num_cells(int n)
{
	cells.resize(n+1, pair<int, int>({ 0,0 }));
}

void normal_board::initialize_players(int n, vector<string>& names)
{
	game_players = game_player_factory->generate_players(n, names);
}

void normal_board::initialize_ladders(int n, vector<pair<int, int>> pos)
{
	game_ladders = game_ladder_factory->generate_ladders(n, pos);
}

void normal_board::initialize_snakes(int n, vector<pair<int, int>> pos)
{
	game_snakes = game_snake_factory->generate_snakes(n, pos);
}

void normal_board::initialize_dice(int n, int seed)
{
	game_dice->set_num_faces(n);
	game_dice->set_seed(seed);
}

void normal_board::initialize_board()
{
	int num_snakes = game_snakes.size();
	for (int i = 0; i < num_snakes; i++)
	{
		pair<int, int> pos = game_snakes[i]->get_snake_pos();
		cells[pos.first].first = -1;
		cells[pos.first].second = pos.second;
	}
	int num_ladders = game_ladders.size();
	for (int i = 0; i < num_ladders; i++)
	{
		pair<int, int> pos = game_ladders[i]->get_ladder_pos();
		cells[pos.first].first = 1;
		cells[pos.first].second = pos.second;
	}
}

void normal_board::simulate_game()
{
	cout << "\nGame played between following players (in order)\n";
	int num_players = game_players.size();
	for (int i = 0; i < num_players; i++)
		cout << "Player " << i + 1 << " - " << game_players[i]->get_name() << " at starting position = " << game_players[i]->get_curr_pos() << "\n";

	cout << "\nStarting the Game\n\n";
	int win_pos = cells.size() - 1;
	while (true)
	{
		bool flag_finished = false;
		for (int i = 0; i < num_players; i++)
		{
			int dice_roll_val = game_dice->do_roll();
			int curr_pos = game_players[i]->get_curr_pos();
			
			// winner found
			if (curr_pos + dice_roll_val == win_pos)
			{
				cout << game_players[i]->get_name() << " rolled a " << dice_roll_val << " and moved from " << curr_pos << " to " << win_pos << "\n";
				cout << game_players[i]->get_name() << " wins the game\n";
				game_players[i]->set_curr_pos(win_pos);
				flag_finished = true;
				break;
			}

			// going out of the board - no movement
			if (curr_pos + dice_roll_val > win_pos)
			{
				cout << game_players[i]->get_name() << " rolled a " << dice_roll_val << " and moved from " << curr_pos << " to " << curr_pos << "\n";
				continue;
			}

			int prev_pos = curr_pos;
			curr_pos += dice_roll_val;
			while (cells[curr_pos].first != 0)
				curr_pos = cells[curr_pos].second;

			cout << game_players[i]->get_name() << " rolled a " << dice_roll_val << " and moved from " << prev_pos << " to " << curr_pos << "\n";
			game_players[i]->set_curr_pos(curr_pos);
			if (curr_pos == win_pos)
			{
				cout << game_players[i]->get_name() << " wins the game\n";
				flag_finished = true;
				break;
			}
		}
		if (flag_finished) break;
		cout << "\n";
	}
	cout << "Game finished\n" << endl;
}