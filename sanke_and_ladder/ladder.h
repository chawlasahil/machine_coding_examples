#pragma once
#include <utility>

using namespace std;

class ladder
{
public:
	virtual ~ladder() {}
	virtual void set_ladder_pos(int s, int e) = 0;
	virtual pair<int, int> get_ladder_pos() = 0;
};

class normal_ladder : public ladder
{
public:
	normal_ladder() {}
	void set_ladder_pos(int s, int e)
	{
		pos.first = s;
		pos.second = e;
	}
	pair<int, int> get_ladder_pos()
	{
		return pos;
	}
private:
	pair<int, int> pos;
};

