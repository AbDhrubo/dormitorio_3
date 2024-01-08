#include "Cleaners.h"
void cleaners::add_cleaner(int i, string n, string cn, int t, int d, int f, Block b) {
	Cleaner s1(i,n,cn,t,d,f,b);
	arr_cleaner.push_back(s1);
	delete& s1;
}

int cleaners::remove_cleaner(int ID) {
	int ch = 0;
	for (int i = 0; i < arr_cleaner.size(); i++) {
		if (ID == arr_cleaner[i].get_id()) {
			arr_cleaner.erase(arr_cleaner.begin() + i);
			ch = 1;
			return 0;
		}
	}
	if (!ch) return 1;
}

/*int cleaners::cleaner_entry(int ID) {
	for (int i = 0; i < arr_cleaner.size(); i++) {
		if (ID == arr_cleaner[i].get_id()) {
			arr_cleaner[i].presence_updater();
			return 0;
		}
	}
	return 1;
}

void cleaners::cleaner_exit(int ID) {
	for (int i = 0; i < arr_cleaner.size(); i++) {
		if (ID == arr_cleaner[i].get_id()) {
			arr_cleaner[i].presence_updater();
		}
	}
}*/
Cleaner cleaners::find_cleaner(int ID) {
	for (int i = 0; i < arr_cleaner.size(); i++) {
		if (ID == arr_cleaner[i].get_id()) {
			return arr_cleaner[i];
		}
	}
	cout << "Not Found" << endl;
}