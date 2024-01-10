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
	void add_Guard(int i, string n, string cn, string t, int d, int g);
	int remove_Guard(int ID);
	int Guard_entry(int ID);
	void Guard_exit(int ID);
	Guard* find_Guard(int ID);
	void show_all_guards();
	void show_present_guards();
	void show_absent_gurds();
	void show_shift_present();
	void show_shift_absent();
	void on_duty_updater();
	void late_catcher();
};

