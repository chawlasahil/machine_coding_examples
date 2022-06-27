#pragma once
#include "player.h"
#include <vector>

using namespace std;

// factory for player generation
class player_factory
{
public:
	virtual ~player_factory() {};
	virtual vector<player*> generate_players(int n, vector<string>& names) = 0;
};

// concrete implementation
class uniform_player_factory : public player_factory
{
	// implements normal_player only
public:
	uniform_player_factory() {}
	vector<player*> generate_players(int n, vector<string>& names)
	{
		vector<player*> list_of_players;
		for (int i = 0; i < n; i++)
		{
			player* new_player = new normal_player();
			new_player->set_name(names[i]);
			new_player->set_curr_pos(0);
			list_of_players.push_back(new_player);
		}
		return list_of_players;
	}
};