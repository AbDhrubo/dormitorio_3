#include "Guards.h"

void Guards::add_Guard(int i, string n, string cn, string t, int d, int g) {
	Guard s1(i, n, cn, t, d, g);
	arr.push_back(s1);
	//delete &s1;
}

int Guards::remove_Guard(int ID) {
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

int Guards::Guard_entry(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			//arr[i].presence_updater();
			return 0;
		}
	}
	return 1;
}

void Guards::Guard_exit(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			//arr[i].presence_updater();
		}
	}
}

Guard Guards::find_Guard(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			return arr[i];
		}
	}
	cout << "Not Found" << endl;
}