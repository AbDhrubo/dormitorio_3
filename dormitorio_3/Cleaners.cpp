#include "Cleaners.h"
void Cleaners::add_cleaner(int i, string n, string cn, string t, int d, int f, Block b) {
	Cleaner s1(i, n, cn, t, d, f, b);
	arr.push_back(s1);
	//delete& s1;
}

int Cleaners::remove_cleaner(int ID) {
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

void Cleaners::cleaner_entry(int ID) {
	try {
		Cleaner *temp = find_cleaner(ID);
		if (temp) {
			temp->set_presence(1);
			temp->set_on_duty(1);
			cout << "Entry Successfull" << endl;
		}
		else throw 1;
	}
	catch (int i) {
		cout << "ID not found" << endl;
	}
}

void Cleaners::cleaner_exit(int ID) {
	try {
		Cleaner* temp = find_cleaner(ID);
		if (temp) {
			temp->set_presence(0);
			cout << "Exit Successfull" << endl;
		}
		else throw 1;
	}
	catch (int i) {
		cout << "ID not found" << endl;
	}
}

//void cleaner_entry(int ID);
//void cleaner_exit(int ID);
Cleaner *Cleaners::find_cleaner(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			return &arr[i];
		}
	}
	return nullptr;
}

void Cleaners::show_all() {
	for (int i = 0; i < arr.size(); i++) {
		arr[i].show_info();
	}
}
void Cleaners::show_present() {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].get_presence()) arr[i].show_info();
	}
}
void Cleaners::show_absent() {
	for (int i = 0; i < arr.size(); i++) {
		if (!arr[i].get_presence()) arr[i].show_info();
	}
}

void Cleaners::show_shift_present() {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].get_presence() && arr[i].get_on_duty()) arr[i].show_info();
	}
}
void Cleaners::show_shift_absent() {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].get_presence() && !arr[i].get_on_duty()) arr[i].show_info();
	}
}

void Cleaners::on_duty_updater() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	for (int i = 0; i < arr.size(); i++) {
		DateTime temp = arr[i].get_duty_time();
		temp.updateDate(curr);
		if (DateTime::timeDiffMinute(temp, curr) <= arr[i].get_duration()) {
			arr[i].set_on_duty(1);
		}
		else arr[i].set_on_duty(0);
	}
}

void Cleaners::late_catcher() {
	auto currentTime = chrono::system_clock::now();
	DateTime curr(currentTime);
	for (int i = 0; i < arr.size(); i++) {
		DateTime temp = arr[i].get_duty_time();
		temp.updateDate(curr);
		if ((!arr[i].get_presence() || arr[i].get_on_duty()) && DateTime::timeDiffMinute(temp, curr) > 10) {
			arr[i].late_count_inc();
		}
	}
}