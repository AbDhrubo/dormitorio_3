#pragma once
#include "Cook.h"
#include<vector>

class cooks
{
private:
	vector<Cook> arr;
public:
	void add_cook(int i, string n, string cn, string t, int d, Position p, Meal m);
	int remove_cook(int ID);
	int cook_entry(int ID);
	void cook_exit(int ID);
	Cook find_cook(int ID);
	void going_on_leave(int ID);
	void returns_from_leave(int ID);
};

