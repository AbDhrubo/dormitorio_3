#include "cooks.h"

void cooks::add_cook(int i, string n, string cn, string t, int d, Position p, Meal m)
{
	Cook c1(i, n, cn, t, d, p, m);
	arr.push_back(c1);
}

int cooks::remove_cook(int ID) 
{
	int ch = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			arr.erase(arr.begin() + i);
			ch = 1;
			return 0;
		}
	}
	if (!ch) return 1;
}

int cooks::cook_entry(int ID) 
{
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			arr[i].presence_updater();
			return 0;
		}
	}
	return 1;
}

void cooks::cook_exit(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			arr[i].presence_updater();
		}
	}
}

Cook cooks::find_cook(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			return arr[i];
		}
	}
	cout << "Cook invisible" << endl;
}

void cooks::going_on_leave(int ID)
{
	find_cook(ID).set_on_duty(false);
}

void cooks::returns_from_leave(int ID)
{
	find_cook(ID).set_on_duty(true);
}