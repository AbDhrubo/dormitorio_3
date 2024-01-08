#pragma once
#include "Guard.h"
#include<vector>
class Guards
{
private:
	vector<Guard> arr;
public:
	/*students() {
	}*/
	void add_Guard(int i, string n, string cn, int t, int d, int g);
	int remove_Guard(int ID);
	int Guard_entry(int ID);
	void Guard_exit(int ID);
	Guard find_Guard(int ID);
};

