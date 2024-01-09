#include "Teachers.h"

void Teachers::add_Teacher(int i, string n, string cn, string em_cn, string _dept, int loc, T_Position p) {
	Teacher t1 (i, n, cn, em_cn, _dept, loc, p);
	arr.push_back(t1);
	//delete &s1;
}

int Teachers::remove_Teacher(int ID) {
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

int Teachers::Teacher_entry(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			arr[i].presence_updater();
			return 0;
		}
	}
	return 1;
}

void Teachers::Teacher_exit(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			arr[i].presence_updater();
		}
	}
}

Teacher Teachers::find_Teacher(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			return arr[i];
		}
	}
	cout << "Not Found" << endl;
}