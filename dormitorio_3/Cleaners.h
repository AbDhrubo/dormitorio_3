#pragma once
#include"Cleaner.h"
#include<vector>

class Cleaners
{
private:
	vector<Cleaner> arr;
public:
	/*students() {
	}*/
	void add_cleaner(int i, string n, string cn, string t, int d, int f, Block b);
	int remove_cleaner(int ID);
	void cleaner_entry(int ID);
	void cleaner_exit(int ID);
	Cleaner *find_cleaner(int ID);
	void show_all();
	void show_present();
	void show_absent();
	void show_shift_present();
	void show_shift_absent();
	void on_duty_updater();
	void late_catcher();
};
