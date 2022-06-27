#pragma once
#include <cstdlib>

using namespace std;

// common dice interface
class dice
{
public:
	virtual void set_seed(int n) = 0;
	virtual void set_num_faces(int n) = 0;
	virtual int do_roll() = 0;
	virtual ~dice() {}
};


// concrete implementation of normal dice - equal probability for all the numbers from 1 to n
class normal_dice : public dice
{
public:
	normal_dice() {}
	void set_seed(int n)
	{
		srand(n);
	}
	void set_num_faces(int n)
	{
		num_faces = n;
	}
	int do_roll()
	{
		int ans = rand();
		ans = ans % num_faces + 1;
		return ans;
	}
private:
	int num_faces = 6;
};