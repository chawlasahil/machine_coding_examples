#pragma once
#include <utility>

using namespace std;

// interface for snake objects
class snake
{
public:
	virtual ~snake() {};
	virtual void set_snake_pos(int s, int e) = 0;
	virtual pair<int, int> get_snake_pos() = 0;
};

// concrete snakes - can be of different types in the future for UI
class normal_snake : public snake
{
public:
	normal_snake() {}
	void set_snake_pos(int s, int e)
	{
		pos.first = s;
		pos.second = e;
	}
	pair<int, int> get_snake_pos()
	{
		return pos;
	}
private:
	pair<int, int> pos; // start, end
};
