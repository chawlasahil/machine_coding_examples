#pragma once
#include <iostream>
#include <string>

using namespace std;


// player interface
class player
{
public:
	virtual ~player() {};
	virtual void set_curr_pos(int n) = 0;
	virtual void set_name(string s) = 0;
	virtual int get_curr_pos() = 0;
	virtual string get_name() = 0;
};

// concrete players
class normal_player : public player
{
public:
	normal_player()
	{
		curr_pos = 0;
		name = "";
	}
	void set_curr_pos(int n)
	{
		curr_pos = n;
	}
	void set_name(string s)
	{
		name = s;
	}
	int get_curr_pos()
	{
		return curr_pos;
	}
	string get_name()
	{
		return name;
	}

private:
	int curr_pos;
	string name;
};