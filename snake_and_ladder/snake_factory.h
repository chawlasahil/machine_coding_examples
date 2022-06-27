#pragma once
#include "snake.h"
#include <vector>

using namespace std;
class snake_factory
{
public:
	virtual ~snake_factory() {}
	virtual vector<snake*> generate_snakes(int n, vector<pair<int, int>> pos) = 0;
};


// concrete implementation - creates all snakes as base_snakes
class base_snake_factory : public snake_factory
{
public:
	base_snake_factory() {}
	vector<snake*> generate_snakes(int n, vector<pair<int, int>> pos)
	{
		vector<snake*> all_snakes;
		for (int i = 0; i < n; i++)
		{
			snake* obj = new normal_snake();
			obj->set_snake_pos(pos[i].first, pos[i].second);
			all_snakes.push_back(obj);
		}
		return all_snakes;
	}
};

