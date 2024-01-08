#pragma once
#include"Cleaner.h"
#include<vector>

class cleaners
{
private:
	vector<Cleaner> arr_cleaner;
public:
	/*students() {
	}*/
	void add_cleaner(int i, string n, string cn, int t, int d, int f, Block b);
	int remove_cleaner(int ID);
	int cleaner_entry(int ID);
	void cleaner_exit(int ID);
	Cleaner find_cleaner(int ID);
};