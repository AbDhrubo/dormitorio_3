#pragma once
#include "Guards.h"
#include "DateTime.h"

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
	try {
		Guard* temp = find_Guard(ID);
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

void Guards::Guard_exit(int ID) {
	try {
		Guard* temp = find_Guard(ID);
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

Guard* Guards::find_Guard(int ID) {
	for (int i = 0; i < arr.size(); i++) {
		if (ID == arr[i].get_id()) {
			return &arr[i];
		}
	}
	cout << "Not Found" << endl;
}

void Guards::show_all_guards() {
	for (int i = 0; i < arr.size(); i++) {
		arr[i].show_info();
	}
}
void Guards::show_present_guards() {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].get_presence()) arr[i].show_info();
	}
}
void Guards::show_absent_gurds() {
	for (int i = 0; i < arr.size(); i++) {
		if (!arr[i].get_presence()) arr[i].show_info();
	}
}

void Guards::show_shift_present() {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].get_presence() && arr[i].get_on_duty()) arr[i].show_info();
	}
}
void Guards::show_shift_absent() {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].get_presence() && !arr[i].get_on_duty()) arr[i].show_info();
	}
}

void Guards::on_duty_updater() {
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

void Guards::late_catcher() {
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