#pragma once
#include "ladder.h"
#include <vector>

using namespace std;

// ladder factory interface
class ladder_factory
{
public:
	virtual ~ladder_factory() {}
	virtual vector<ladder*> generate_ladders(int n, vector<pair<int, int>> pos) = 0;
};


// concrete implementation of ladder factory
class normal_ladder_factory : public ladder_factory
{
public:
	normal_ladder_factory() {}
	vector<ladder*> generate_ladders(int n, vector<pair<int, int>> pos)
	{
		vector<ladder*> all_ladders;
		for (int i = 0; i < n; i++)
		{
			ladder* obj = new normal_ladder();
			obj->set_ladder_pos(pos[i].first, pos[i].second);
			all_ladders.push_back(obj);
		}
		return all_ladders;
	}
private:
};
